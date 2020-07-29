#include <fstream>
#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

using namespace keenspace;
using namespace std;

namespace keenspace {

	// constructor to initialize width, height, and pixels/color of bitmap
	Bitmap::Bitmap(int width, int height) : m_width(width), m_height(height), m_pPixels(new uint8_t[width *height * 3]{}) {

	}

	bool Bitmap::write(string filename) {

		// objects to be written to file
		BitmapFileHeader fileHeader;
		BitmapInfoHeader infoHeader;

		// set the size of the file
		fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width * m_height * 3;

		// distance to where bitmap data starts (after header and info)
		fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

		// set dimensions of info header in file
		infoHeader.width = m_width;
		infoHeader.height = m_height;

		// create and open a file to write to that is binary
		ofstream file;
		file.open(filename, ios::out | ios::binary);

		// check file opened
		if (!file) {
			return false;
		}

		// write the bitmap header to the file 
		file.write((char *)&fileHeader, sizeof(fileHeader));

		// write the bitmap info to the file
		file.write((char *)&infoHeader, sizeof(infoHeader));

		// write the pixels info to the file
		file.write((char *)m_pPixels.get(), m_width * m_height * 3);

		file.close();

		// check file closed
		if (!file) {
			return false;
		}

		return true;
	}

	void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
		
		uint8_t *pPixel = m_pPixels.get();

		// target the specifed pixel in the bitmap
		pPixel += (y * 3)* m_width + (x * 3);

		// set the RGB values of target pixel
		pPixel[0] = blue;
		pPixel[1] = green;
		pPixel[2] = red;
	}

	Bitmap::~Bitmap() {

	}


}