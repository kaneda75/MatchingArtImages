// -*- C++ -*-
/* 
 * File:   matchingImages.hpp
 * Author: xescriche
 *
 * Created on 13 de octubre de 2012, 20:09
 */

#ifndef MATCHINGIMAGES_HPP
#define	MATCHINGIMAGES_HPP

#include "matchingImages.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/contrib/contrib.hpp"
#include <iostream>
#include <fstream>

using namespace cv;
using namespace std;

static void printPrompt(const string& applName);
static void maskMatchesByTrainImgIdx(const vector<DMatch>& matches, int trainImgIdx, vector<char>& mask);
static void readTrainFilenames(const string& filename, string& dirName, vector<string>& trainFilenames);
static bool createDetectorDescriptorMatcher(const string& detectorType, const string& descriptorType, const string& matcherType,Ptr<FeatureDetector>& featureDetector,Ptr<DescriptorExtractor>& descriptorExtractor,Ptr<DescriptorMatcher>& descriptorMatcher);
static bool readImages(const string& queryImageName, const string& trainFilename,Mat& queryImage, vector <Mat>& trainImages, vector<string>& trainImageNames);
static void detectKeypoints(const Mat& queryImage, vector<KeyPoint>& queryKeypoints,const vector<Mat>& trainImages, vector<vector<KeyPoint> >& trainKeypoints,Ptr<FeatureDetector>& featureDetector);
static void computeDescriptors(const Mat& queryImage, vector<KeyPoint>& queryKeypoints, Mat& queryDescriptors,const vector<Mat>& trainImages, vector<vector<KeyPoint> >& trainKeypoints, vector<Mat>& trainDescriptors,Ptr<DescriptorExtractor>& descriptorExtractor);
static void matchDescriptors(const Mat& queryDescriptors, const vector<Mat>& trainDescriptors,vector<DMatch>& matches, Ptr<DescriptorMatcher>& descriptorMatcher);
static void saveResultImages(const Mat& queryImage, const vector<KeyPoint>& queryKeypoints,const vector<Mat>& trainImages, const vector<vector<KeyPoint> >& trainKeypoints,const vector<DMatch>& matches, const vector<string>& trainImagesNames, const string& resultDir);
int computeMatching(string detectorType, string descriptorType, string matcherType, string queryImageName, string fileWithTrainImages, string dirToSaveResImages);


#endif	/* MATCHINGIMAGES_HPP */

