#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "Tesseract.h"
#include<string>
using namespace std;
using namespace cv;
TessException::TessException(const string& message) : message(message) {} //end of FileException constructor
string& TessException::what() { return message; }
tess::tess() {
}
void tess::extractText(string filePath)
{
	char *outText;

	tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
	// Initialize tesseract-ocr with English, without specifying tessdata path
	if (api->Init(NULL, "eng")) {
		throw TessException("Tesseract failed to initalize image!");
		exit(1);
	}

	// Open input image with leptonica library
	const char* c = filePath.c_str();
	Pix *image = pixRead(c);
	api->SetImage(image);
	// Get OCR result
	outText = api->GetUTF8Text();
	printf("OCR output:\n%s", outText);

	// Destroy used object and release memory
	api->End();
	delete[] outText;
	pixDestroy(&image);
	waitKey(0);
}