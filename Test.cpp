//Author: Jack Wotherspoon
//Created: Nov 5th, 2018
#include<opencv2/opencv.hpp>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include<iostream>
#include "OpenCV.h"
#include "Tesseract.h"
using namespace std;
using namespace cv;

int main() {
	
	string filePath="C:/Users/Test/Pictures/testslide2.jpg"; //place desired input file path here
	string ofilePath= "C:/Users/Test/Pictures/tester.jpg";   //output filepath of opencv that feeds in to tesseract
	OpenCV cv;
	tess tesseract;
	cv.compute(filePath, ofilePath);
	tesseract.extractText(ofilePath);
	cout << "Test complete" << endl;
	waitKey(0);
}
