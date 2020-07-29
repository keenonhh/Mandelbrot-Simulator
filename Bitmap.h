#ifndef BITMAP_H
#define BIMAP_H

#include <string>
#include <cstdint>
using namespace std;

namespace keenspace {

	class Bitmap
	{
	private:
		int m_width{ 0 };
		int m_height{ 0 };

		// pointer for setting color of pixels
		unique_ptr<uint8_t[]> m_pPixels{nullptr};

	public:
		// constructor sets bitmap dimensions
		Bitmap(int width, int height);

		// write bitmap information and header to a file
		bool write(string filename);

		// pixel position and color
		void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);

		virtual ~Bitmap();
	};

}

#endif