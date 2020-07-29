#ifndef ZOOMLIST_H
#define ZOOMLIST_H

#include <iostream>
#include <vector>
#include <utility>
#include "Zoom.h"
using namespace std;

namespace keenspace {

	class ZoomList {
	private:
		// coordinates and scale of zoom location
		double m_xCenter{ 0 };
		double m_yCenter{ 0 };
		double m_scale{ 1.0 };

		// dimensions of bitmap and previous zooms
		int m_width{ 0 };
		int m_height{ 0 };
		vector<Zoom> zooms;

	public:
		ZoomList(int width, int height);
		void add(const Zoom& zoom);
		pair <double, double> doZoom(int x, int y);
	};
}

#endif
