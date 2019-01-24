#include "contrast.h"
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

void contrast_addToLut1d(ImacLut1d *lut, int value) {
    double brightness = 0;
    double contrastFactor = (259.0 * (value + 255.0)) / (255.0 * (259.0 - value));
    for (unsigned int i = 0; i < lut->size; i++) {
        brightness = contrastFactor * (lut_get(lut, i) - 128) + 128;
		lut_set(lut, i, (int) brightness);
    }
}

void contrast_dimToLut1d(ImacLut1d *lut, int value) {
    double brightness = 0;
    double contrastFactor = (259.0 * ((-value) + 255.0)) / (255.0 * ( 259.0 - (-value)));
    for (unsigned int i = 0; i < lut->size; i++) {
        brightness = contrastFactor * (lut_get(lut, i) - 128) + 128;
        lut_set(lut, i, (int) brightness);
    }
}

void contrast_sinToLut1d(ImacLut1d *lut, int value) {
	double brightness;
	int lutData;
	double sinFormula, resultSin;
	for (unsigned int i = 0; i < lut->size; i++) {
		lutData = (int) lut_get(lut, i);
		for (int v = 0; v < value; v++) {
			sinFormula = (M_PI * lutData) / 255 + (3 * M_PI) / 2;
			resultSin = sin(sinFormula);
			brightness = ((resultSin + 1) * 255) / 2;
			lutData = (int) brightness;
		}
		lut_set(lut, i, (int) brightness);
	}
}

void contrast_equalizeToLut1d(ImacLut1d *lut, unsigned int histogram[256]) {
	// FIXME doesn't work sometimes for no reason, not depending on the image, it randomly goes wrong
	int totalValues = 0;
	double cdf = 0.0;
	for (unsigned int i = 0; i < 256; i++) {
		totalValues += histogram[i];
	}
	for (unsigned int i = 0; i < lut->size; i++) {
		cdf += (double) histogram[i] / totalValues;
		lut_set(lut, i, (int) (255 * cdf));
	}
}
