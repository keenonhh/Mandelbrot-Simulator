#include "RGB.h"

namespace keenspace {

	RGB::RGB(double r, double g, double b) : r(r), g(g), b(b) {

	}

	// setting the color of the fractal
	RGB operator-(const RGB& first, const RGB& second) {
		return RGB(first.r - second.r, first.g - second.g, first.b - second.b);
	}
}


