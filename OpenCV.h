
#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

class FileException {
public:
	FileException(const string& message);
	string& what();
private:
	string message;
}; // end FileException class
class OpenCV {
public:
	OpenCV();
	//OpenCV(Mat, Mat);
	void compute(string, string);
private:

};