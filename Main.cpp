#include <iostream>
#include "FractalCreator.h"
#include "RGB.h"
#include "Zoom.h"

using namespace std;
using namespace keenspace;

int main() {
	
	FractalCreator fractalCreator(800, 600);

	// set the range of colors for pixels in bitmap
	fractalCreator.addRange(0.0, RGB(0, 0, 0));
	fractalCreator.addRange(0.3, RGB(0, 99, 71));
	fractalCreator.addRange(0.3, RGB(0, 215, 0));
	fractalCreator.addRange(1.0, RGB(0, 255, 255));

	// zoom in to fractal
	fractalCreator.addZoom(Zoom(295, 202, 0.1));
	fractalCreator.addZoom(Zoom(312, 304, 0.1));

	fractalCreator.run("temp.bmp");

	cout << "Finished!" << endl;
	return 0;
}