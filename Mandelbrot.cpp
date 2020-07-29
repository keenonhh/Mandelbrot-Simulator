#include <complex>
#include "Mandelbrot.h"

using namespace std;

namespace keenspace {

	Mandelbrot::Mandelbrot() {

	}

	int Mandelbrot::getIterations(double x, double y) {

		// complex numbers for mandlbrot algorithm
		complex<double> z = 0;
		complex<double> c(x, y);

		int iterations = 0;

		// Mandelbrot algorithm
		while (iterations < MAX_ITERATIONS) {
			z = z * z + c;

			if (abs(z) > 2) {
				break;
			}

			iterations++;
		}

		return iterations;
	}

	Mandelbrot::~Mandelbrot() {

	}
}