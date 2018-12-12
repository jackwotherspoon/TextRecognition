#include<opencv2/opencv.hpp>
#include<iostream>
#include "OpenCV.h"
#include<string>
using namespace std;
using namespace cv;
FileException::FileException(const string& message) : message(message) {} //end of FileException constructor
string& FileException::what() { return message; }
OpenCV::OpenCV() {
}
void OpenCV::compute(string filePath, string ofilePath)
{	
	Mat img = imread(filePath);
	if (img.empty())
		throw FileException("Image could not be read!");
	Mat gray_image;
	cvtColor(img, gray_image, COLOR_BGR2GRAY);
	imwrite(ofilePath, gray_image);
	Mat output;
	//can uncomment lines to play around with opencv functions that can improve image quality
	//Mat blurred;
	//Mat blurred1;
	//Mat blurred2; 
	//Mat denoise;
	threshold(gray_image,output, 90, 255, THRESH_BINARY_INV);
	//adaptiveThreshold(gray_image, output,255,ADAPTIVE_THRESH_MEAN_C,THRESH_BINARY,80,3);
	imwrite(ofilePath, output);
	//imshow("image", gray_image);
	imshow("output", output);
	//fastNlMeansDenoising(output, denoise, 30, 7, 21);
	//imshow("Denoising", denoise);
	//bilateralFilter(output, blurred, 20, 100, 100);
	//blur(output,blurred1,Size(1,1));
	//GaussianBlur(denoise, blurred2, Size(1, 1), 0, 0);
	//imshow("Bilateral Filter", blurred);
	//imshow("Average filter", blurred1);
	//imshow("Gaussian filter", blurred2);
	//waitKey(0);
}