#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include<string>
using namespace std;
using namespace cv;
class TessException {
public:
	TessException(const string& message);
	string& what();
private:
	string message;
}; // end TessException class
class tess {
public:
	tess();
	void extractText(string);

private:
};