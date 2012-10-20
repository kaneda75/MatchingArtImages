#include "opencv2/highgui/highgui.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/contrib/contrib.hpp"

#include <iostream>
#include <fstream>

using namespace cv;
using namespace std;

static void printPrompt(const string& applName) {
    cout << "/*\n"
         << " * This is a sample on matching descriptors detected on one image to descriptors detected in image set.\n"
         << " * So we have one query image and several train images. For each keypoint descriptor of query image\n"
         << " * the one nearest train descriptor is found the entire collection of train images. To visualize the result\n"
         << " * of matching we save images, each of which combines query and train image with matches between them (if they exist).\n"
         << " * Match is drawn as line between corresponding points. Count of all matches is equel to count of\n"
         << " * query keypoints, so we have the same count of lines in all set of result images (but not for each result\n"
         << " * (train) image).\n"
         << " */\n" << endl;

    cout << endl << "Format:\n" << endl;
    cout << "./" << applName << " [detectorType] [descriptorType] [matcherType] [queryImage] [fileWithTrainImages] [dirToSaveResImages]" << endl;
    cout << endl;

    cout << "\nExample:" << endl
         << "./" << applName << " " << "SURF" << " " << "SURF" << " " << "FlannBased" << " "
         << "/Users/example.jpg" << " " << "/Users/example.txt" << " " << "/Users/user1/results" << endl;
}

static void maskMatchesByTrainImgIdx(const vector<DMatch>& matches, int trainImgIdx, vector<char>& mask) {
    mask.resize(matches.size());
    fill(mask.begin(), mask.end(), 0);
    for (size_t i = 0; i < matches.size(); i++) {
        if (matches[i].imgIdx == trainImgIdx)
            mask[i] = 1;
    }
}

static void readTrainFilenames(const string& filename, string& dirName, vector<string>& trainFilenames) {
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
}

static bool createDetectorDescriptorMatcher(const string& detectorType, const string& descriptorType, const string& matcherType,Ptr<FeatureDetector>& featureDetector,Ptr<DescriptorExtractor>& descriptorExtractor,Ptr<DescriptorMatcher>& descriptorMatcher) {
    cout << "< Creant detector, descriptor i matcher ..." << endl;
    featureDetector = FeatureDetector::create(detectorType);
    descriptorExtractor = DescriptorExtractor::create(descriptorType);
    descriptorMatcher = DescriptorMatcher::create(matcherType);
    cout << ">" << endl;

    bool isCreated = !(featureDetector.empty() || descriptorExtractor.empty() || descriptorMatcher.empty());
    if (!isCreated)
//        cout << "Can not create feature detector or descriptor extractor or descriptor matcher of given types." << endl << ">" << endl;
          cout << "No es pot crear el detector, el descriptor o el matcher." << endl << ">" << endl;


    return isCreated;
}

static bool readImages(const string& queryImageName, const string& trainFilename,Mat& queryImage, vector <Mat>& trainImages, vector<string>& trainImageNames, int color) {
    cout << "< Llegint les imatges..." << endl;
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
    } else
        cout << readImageCount << " imatges a comparar llegides." << endl;
    cout << ">" << endl;

    return true;
}

static void detectKeypoints(const Mat& queryImage, vector<KeyPoint>& queryKeypoints,const vector<Mat>& trainImages, vector<vector<KeyPoint> >& trainKeypoints,Ptr<FeatureDetector>& featureDetector) {
    cout << endl << "< Extraent descriptors de les imatges..." << endl;
    featureDetector->detect(queryImage, queryKeypoints);
    featureDetector->detect(trainImages, trainKeypoints);
    cout << ">" << endl;
}

static void computeDescriptors(const Mat& queryImage, vector<KeyPoint>& queryKeypoints, Mat& queryDescriptors,const vector<Mat>& trainImages, vector<vector<KeyPoint> >& trainKeypoints, vector<Mat>& trainDescriptors,Ptr<DescriptorExtractor>& descriptorExtractor) {
    cout << "< Computant descriptors..." << endl;
    descriptorExtractor->compute(queryImage, queryKeypoints, queryDescriptors);
    descriptorExtractor->compute(trainImages, trainKeypoints, trainDescriptors);

    int totalTrainDesc = 0;
    for (vector<Mat>::const_iterator tdIter = trainDescriptors.begin(); tdIter != trainDescriptors.end(); tdIter++)
        totalTrainDesc += tdIter->rows;

    cout << "Descriptors consulta num: " << queryDescriptors.rows << "; Total descriptors consulta num: " << totalTrainDesc << endl;
    cout << ">" << endl;
}

static void matchDescriptors(const Mat& queryDescriptors, const vector<Mat>& trainDescriptors, vector<DMatch>& matches, Ptr<DescriptorMatcher>& descriptorMatcher) {
//    cout << "< Set train descriptors collection in the matcher and match query descriptors to them..." << endl;
    cout << "< Prepara descriptors de la colecció d'imatges a comparar i compara els descriptors consulta amb ells..." << endl;
    
    TickMeter tm;

    tm.start();
    descriptorMatcher->add(trainDescriptors);
    descriptorMatcher->train();
    tm.stop();
    double buildTime = tm.getTimeMilli();

    tm.start();
    descriptorMatcher->match(queryDescriptors, matches);
    tm.stop();
    double matchTime = tm.getTimeMilli();

    CV_Assert(queryDescriptors.rows == (int) matches.size() || matches.empty());

    cout << "Numero de coincidencies: " << matches.size() << endl;
    cout << "Temps de compilacio/build: " << buildTime << " ms; Temps de comparació: " << matchTime << " ms" << endl;
    cout << ">" << endl;
}

static void saveResultImages(const Mat& queryImage, const vector<KeyPoint>& queryKeypoints,const vector<Mat>& trainImages, const vector<vector<KeyPoint> >& trainKeypoints, const vector<DMatch>& matches, const vector<string>& trainImagesNames, const string& resultDir, string nomArxiu) {
    cout << "< Guardant els resultats..." << endl;
    Mat drawImg;
    vector<char> mask;
    for (size_t i = 0; i < trainImages.size(); i++) {
        if (!trainImages[i].empty()) {
            maskMatchesByTrainImgIdx(matches, (int) i, mask);
            drawMatches(queryImage, queryKeypoints, trainImages[i], trainKeypoints[i],
                    matches, drawImg, Scalar(255, 0, 0), Scalar(0, 255, 255), mask);
            string filename = resultDir + "/res_" + nomArxiu + "_" + trainImagesNames[i];
            if (!imwrite(filename, drawImg))
                cout << "L'imatge " << filename << " no pot ser guardada (pot ser que el directori " << resultDir << " no existeixi)." << endl;
        }
    }
    cout << ">" << endl;
}

int computeMatching(string detectorType, string descriptorType, string matcherType, string queryImageName, string fileWithTrainImages, string dirToSaveResImages, int color) {
    Ptr<FeatureDetector> featureDetector;
    Ptr<DescriptorExtractor> descriptorExtractor;
    Ptr<DescriptorMatcher> descriptorMatcher;
    
    if (!createDetectorDescriptorMatcher(detectorType, descriptorType, matcherType, featureDetector, descriptorExtractor, descriptorMatcher)) {
        printPrompt(detectorType);
        return -1;
    }

    Mat queryImage;
    vector<Mat> trainImages;
    vector<string> trainImagesNames;
    if (!readImages(queryImageName, fileWithTrainImages, queryImage, trainImages, trainImagesNames, color)) {
        printPrompt(detectorType);
        return -1;
    }

    vector<KeyPoint> queryKeypoints;
    vector<vector<KeyPoint> > trainKeypoints;
    detectKeypoints(queryImage, queryKeypoints, trainImages, trainKeypoints, featureDetector);

    Mat queryDescriptors;
    vector<Mat> trainDescriptors;
    computeDescriptors(queryImage, queryKeypoints, queryDescriptors,trainImages, trainKeypoints, trainDescriptors,descriptorExtractor);

    vector<DMatch> matches;
    matchDescriptors(queryDescriptors, trainDescriptors, matches, descriptorMatcher);
    saveResultImages(queryImage, queryKeypoints, trainImages, trainKeypoints,matches, trainImagesNames, dirToSaveResImages, detectorType + "_" + descriptorType + "_" + matcherType);
    
    return 0;
}