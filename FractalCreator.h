#ifndef FRACTALCREATOR_H
#define FRACTALCREATOR_H

#include <cstdint>
#include <memory>
#include <math.h>
#include <string>
#include <vector>
#include <assert.h>
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "Zoom.h"
#include "ZoomList.h"
#include "RGB.h"

using namespace std;

namespace keenspace {
	
	class FractalCreator
	{
	private:
		// dimensions of the bitmap image
		int m_width;
		int m_height;
		int m_total{ 0 };

		// pointers for the bitmap colors
		unique_ptr<int[]> m_histogram;
		unique_ptr<int[]> m_fractal;

		// bitmap object to call member methods on
		Bitmap m_bitmap;

		// set coordinates to zoom to from bitmap
		ZoomList m_zoomlist;

		vector<int> m_ranges;
		vector<RGB> m_colors;
		vector<int> m_rangeTotals;

		bool m_bGotFirstRange{ false };

	private:
		// calculate iterations to run the Mandelbrot algorithm for
		void calculateIterations();

		void calculateTotalIterations();

		void calculateRangeTotals();

		// draw the fractal in the bitmap file
		void drawFractal();

		// write the information to the bmp file
		void writeBitmap(string name);

		// range of colors for iterations
		int getRange(int iterations) const;

	public:
		FractalCreator(int width, int height);
		virtual ~FractalCreator();

		// range of color of fractal
		void addRange(double rangeEnd, const RGB& rgb);

		// zoom in on coordinates of the bitmap
		void addZoom(const Zoom& zoom);

		// for running the whole program from main
		void run(string name);
	};
}


#endif