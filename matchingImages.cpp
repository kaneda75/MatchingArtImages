#include "opencv2/highgui/highgui.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/contrib/contrib.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>

#define RESULT_CSV_FILE        "//Users/xescriche/Documents/MASTER LINUX/PFM/images/results/result.csv"

using namespace cv;
using namespace std;

static void maskMatchesByTrainImgIdx(const vector<DMatch>& matches, int trainImgIdx, vector<char>& mask) {
    try {
        mask.resize(matches.size());
        fill(mask.begin(), mask.end(), 0);
        for (size_t i = 0; i < matches.size(); i++) {
            if (matches[i].imgIdx == trainImgIdx)
                mask[i] = 1;
        }
    } catch (exception& e) {
        cout << e.what() << endl;
    }
}

static void readTrainFilenames(const string& filename, string& dirName, vector<string>& trainFilenames) {
    try {
        trainFilenames.clear();
        ifstream file(filename.c_str());
        if (!file.is_open())
            return;

        size_t pos = filename.rfind('\\');
        char dlmtr = '\\';
        if (pos == String::npos) {
            pos = filename.rfind('/');
            dlmtr = '/';
        }
        dirName = pos == string::npos ? "" : filename.substr(0, pos) + dlmtr;

        while (!file.eof()) {
            string str;
            getline(file, str);
            if (str.empty()) break;
            trainFilenames.push_back(str);
        }
        file.close();
    } catch (exception& e) {
        cout << e.what() << endl;
    }
}

static bool createDetectorDescriptorMatcher(const string& detectorType, const string& descriptorType, const string& matcherType,Ptr<FeatureDetector>& featureDetector,Ptr<DescriptorExtractor>& descriptorExtractor,Ptr<DescriptorMatcher>& descriptorMatcher)  {
    try {
        featureDetector = FeatureDetector::create(detectorType);
        descriptorExtractor = DescriptorExtractor::create(descriptorType);
        descriptorMatcher = DescriptorMatcher::create(matcherType);
    } catch (exception& e) {
        cout << e.what() << endl;
    }

    bool isCreated = !(featureDetector.empty() || descriptorExtractor.empty() || descriptorMatcher.empty());
    if (!isCreated)
        cout << "No es pot crear el detector, el descriptor o el matcher." << endl << ">" << endl;
    return isCreated;
}

static bool readImages(const string& queryImageName, const string& trainFilename,Mat& queryImage, vector <Mat>& trainImages, vector<string>& trainImageNames, int color, int & numTrainImages) {
    try {
        queryImage = imread(queryImageName, color);
        if (queryImage.empty()) {
            cout << "La imatge consulta no pot ser llegida." << endl << ">" << endl;
            return false;
        }
        string trainDirName;
        readTrainFilenames(trainFilename, trainDirName, trainImageNames);
        if (trainImageNames.empty()) {
            cout << "Les imatges a comparar no poden ser llegides." << endl << ">" << endl;
            return false;
        }
        int readImageCount = 0;
        for (size_t i = 0; i < trainImageNames.size(); i++) {
            string filename = trainDirName + trainImageNames[i];
            Mat img = imread(filename, color);
            if (img.empty())
                cout << "La imatge a comparar " << filename << " no pot ser llegida." << endl;
            else
                readImageCount++;
            trainImages.push_back(img);
        }
        if (!readImageCount) {
            cout << "Totes les imatges a comparar no poden ser llegides." << endl << ">" << endl;
            return false;
        } else {
            numTrainImages = readImageCount;
            cout << "Number of train images:                        " << readImageCount << endl;
        }
    } catch (exception& e) {
        cout << e.what() << endl;
    }
    return true;
}

static void detectKeypoints(const Mat& queryImage, vector<KeyPoint>& queryKeypoints,const vector<Mat>& trainImages, vector<vector<KeyPoint> >& trainKeypoints,Ptr<FeatureDetector>& featureDetector) {
    try {
        featureDetector->detect(queryImage, queryKeypoints);
        featureDetector->detect(trainImages, trainKeypoints);
    } catch (exception& e) {
        cout << e.what() << endl;
    }
}

static void computeDescriptors(const Mat& queryImage, vector<KeyPoint>& queryKeypoints, Mat& queryDescriptors,const vector<Mat>& trainImages, vector<vector<KeyPoint> >& trainKeypoints, vector<Mat>& trainDescriptors,Ptr<DescriptorExtractor>& descriptorExtractor, int & numQueryDescriptors, int & numTrainDescriptors) {
    try {
        descriptorExtractor->compute(queryImage, queryKeypoints, queryDescriptors);
        descriptorExtractor->compute(trainImages, trainKeypoints, trainDescriptors);
        int totalTrainDesc = 0;
        for (vector<Mat>::const_iterator tdIter = trainDescriptors.begin(); tdIter != trainDescriptors.end(); tdIter++)
            totalTrainDesc += tdIter->rows;
        
        numQueryDescriptors = queryDescriptors.rows;
        cout << "Number of query image descriptors:     " << numQueryDescriptors << endl;
        numTrainDescriptors = totalTrainDesc;
        cout << "Number of train images descriptors:     " << totalTrainDesc << endl;
    } catch (exception& e) {
        cout << e.what() << endl;
    }
}

static void matchDescriptors(const Mat& queryDescriptors, const vector<Mat>& trainDescriptors, vector<DMatch>& matches, Ptr<DescriptorMatcher>& descriptorMatcher, int & numMatches, double & matchTime) {
    try {
        TickMeter tm;
        tm.start();
        descriptorMatcher->add(trainDescriptors);
        descriptorMatcher->train();
        tm.stop();
    //    double buildTime = tm.getTimeMilli();
        tm.start();
        descriptorMatcher->match(queryDescriptors, matches);
        tm.stop();
        matchTime = tm.getTimeMilli();
        CV_Assert(queryDescriptors.rows == (int) matches.size() || matches.empty());
        numMatches = matches.size();
        cout << "Number of matches:                              " << numMatches << endl;
        cout << "Match time:                                            " << matchTime << " ms" << endl;
    //    cout << "Temps de compilacio/build: " << buildTime << " ms" << endl;

    } catch (exception& e) {
        cout << e.what() << endl;
    }
}

static void saveResultImages(const Mat& queryImage, const vector<KeyPoint>& queryKeypoints,const vector<Mat>& trainImages, const vector<vector<KeyPoint> >& trainKeypoints, const vector<DMatch>& matches, const vector<string>& trainImagesNames, const string& resultDir, string nomArxiu) {
    try {
        Mat drawImg;
        vector<char> mask;
        for (size_t i = 0; i < trainImages.size(); i++) {
            if (!trainImages[i].empty()) {
                maskMatchesByTrainImgIdx(matches, (int) i, mask);
                drawMatches(queryImage, queryKeypoints, trainImages[i], trainKeypoints[i],
                        matches, drawImg, Scalar(255, 0, 0), Scalar(0, 255, 255), mask);
                string filename = resultDir + "/" + nomArxiu + "_" + trainImagesNames[i];
                if (!imwrite(filename, drawImg))
                    cout << "L'imatge " << filename << " no pot ser guardada (pot ser que el directori " << resultDir << " no existeixi)." << endl;
            }
        }
    } catch (exception& e) {
        cout << e.what() << endl;
    }
}

static void generarFicheroPropietarios(int id, string detectorType, string descriptorType, string matcherType, int color, int numTrainImages, int numQueryDescriptors, int numTrainDescriptors, int numMatches, double matchTime, string error) {
    FILE *ftxt;
    char resultFile[30];
    sprintf(resultFile, RESULT_CSV_FILE);
    ftxt = fopen(resultFile, "a");
    if (ftxt != NULL) {
        fprintf(ftxt, "%d;", id);
        fprintf(ftxt, "%s;", detectorType.c_str());
        fprintf(ftxt, "%s;", descriptorType.c_str());
        fprintf(ftxt, "%s;", matcherType.c_str());
        fprintf(ftxt, "%d;", color);
        fprintf(ftxt, "%d;", numTrainImages);
        fprintf(ftxt, "%d;", numQueryDescriptors);
        fprintf(ftxt, "%d;", numTrainDescriptors);
        fprintf(ftxt, "%d;", numMatches);
        fprintf(ftxt, "%f;", matchTime);
        fprintf(ftxt, "%d;", color);
        fprintf(ftxt, "%s\n", error.c_str());
        fclose(ftxt);
    }
}

int computeMatching(int & id, string detectorType, string descriptorType, string matcherType, string queryImageName, string fileWithTrainImages, string dirToSaveResImages, int color) {
    int numTrainImages=0;
    int numQueryDescriptors=0;
    int numTrainDescriptors=0;
    int numMatches=0;
    double matchTime=0;
    string error = "";

    try {
        Ptr<FeatureDetector> featureDetector;
        Ptr<DescriptorExtractor> descriptorExtractor;
        Ptr<DescriptorMatcher> descriptorMatcher;

        cout << endl;
        cout << "Detector:                                               " << detectorType << endl;
        cout << "Descriptor:                                             " << descriptorType << endl;
        cout << "Matcher:                                                " << matcherType << endl;

        if (!createDetectorDescriptorMatcher(detectorType, descriptorType, matcherType, featureDetector, descriptorExtractor, descriptorMatcher)) {
            return -1;
        }

        Mat queryImage;
        vector<Mat> trainImages;
        vector<string> trainImagesNames;
        if (!readImages(queryImageName, fileWithTrainImages, queryImage, trainImages, trainImagesNames, color, numTrainImages)) {
            return -1;
        }

        vector<KeyPoint> queryKeypoints;
        vector<vector<KeyPoint> > trainKeypoints;
        detectKeypoints(queryImage, queryKeypoints, trainImages, trainKeypoints, featureDetector);

        Mat queryDescriptors;
        vector<Mat> trainDescriptors;
        computeDescriptors(queryImage, queryKeypoints, queryDescriptors, trainImages, trainKeypoints, trainDescriptors, descriptorExtractor, numQueryDescriptors, numTrainDescriptors);

        vector<DMatch> matches;
        matchDescriptors(queryDescriptors, trainDescriptors, matches, descriptorMatcher, numMatches, matchTime);

        saveResultImages(queryImage, queryKeypoints, trainImages, trainKeypoints, matches, trainImagesNames, dirToSaveResImages, detectorType + "_" + descriptorType + "_" + matcherType);
//        generarFicheroPropietarios(id, detectorType, descriptorType, matcherType, color, numTrainImages, numQueryDescriptors, numTrainDescriptors, numMatches, matchTime, error);

        FILE *ftxt;
        char resultFile[30];
        sprintf(resultFile, RESULT_CSV_FILE);
        ftxt = fopen(resultFile, "a");
        if (ftxt != NULL) {
            fprintf(ftxt, "%d;", id);
            fprintf(ftxt, "%s;", detectorType.c_str());
            fprintf(ftxt, "%s;", descriptorType.c_str());
            fprintf(ftxt, "%s;", matcherType.c_str());
            fprintf(ftxt, "%d;", color);
            fprintf(ftxt, "%d;", numTrainImages);
            fprintf(ftxt, "%d;", numQueryDescriptors);
            fprintf(ftxt, "%d;", numTrainDescriptors);
            fprintf(ftxt, "%d;", numMatches);
            fprintf(ftxt, "%f;", matchTime);
            fprintf(ftxt, "%d;", color);
            fprintf(ftxt, "%s\n", error.c_str());
            fclose(ftxt);
        }        
        
    } catch (exception& e) {
        cout << e.what() << endl;
//        generarFicheroPropietarios(id, detectorType, descriptorType, matcherType, color, numTrainImages, numQueryDescriptors, numTrainDescriptors, numMatches, matchTime, e.what());

    }
    return 0;
}