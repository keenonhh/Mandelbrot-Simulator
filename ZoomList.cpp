#include "ZoomList.h"

using namespace std;

namespace keenspace {

	ZoomList::ZoomList(int width, int height) : m_width(width), m_height(height) {

	}

	// adds the coordinates to zoom to based on the previous coordiantes and the amount to zoom(scale)
	void ZoomList::add(const Zoom& zoom) {
		zooms.push_back(zoom);

		m_xCenter += (zoom.x - m_width / 2)*m_scale;
		m_yCenter += -(zoom.y - m_height / 2)*m_scale;

		m_scale *= zoom.scale;
	}

	// returns the coordinates of the pixels to zoom to
	pair <double, double> ZoomList::doZoom(int x, int y) {
		double xFractal = (x - m_width / 2) * m_scale + m_xCenter;
		double yFractal = (y - m_height / 2) * m_scale + m_yCenter;

		return pair<double, double>(xFractal, yFractal);
	}
}
