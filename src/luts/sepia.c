#include "sepia.h"
#include <stdio.h>

void sepia_addToLut3x1d(ImacLut3x1d *lut) {
    double brightnessR, brightnessG, brightnessB;

    for (unsigned int i = 0; i <= lut->channelSize; i++) {
	brightnessR = (i * .393) + (i * .769) + (i * .189);
	brightnessG = (i * .349) + (i * .686) + (i * .168);
	brightnessB = (i * .272) + (i * .534) + (i * .131);

	if (brightnessR > 255) { brightnessR = 255; }
	if (brightnessG > 255) { brightnessG = 255; }
	if (brightnessB > 255) { brightnessB = 255; }

	lut3x1d_set(lut, i, (int) brightnessR, red);
	lut3x1d_set(lut, i, (int) brightnessG, green);
	lut3x1d_set(lut, i, (int) brightnessB, blue);
    }
}


void sepia_addToImg(ImacImg* img) {
	double brightnessR = 0, brightnessG = 0, brightnessB = 0;

	for (unsigned int y = 0; y < img->height; y++) {
		for (unsigned int x = 0; x < img->width; x++) {
			brightnessR = img_getPixelChannel(img, x, y, red);
			brightnessG = img_getPixelChannel(img, x, y, green);
			brightnessB = img_getPixelChannel(img, x, y, blue);

			brightnessR = (brightnessR * .393) + (brightnessG * .769) + (brightnessB * .189);
			brightnessG = (brightnessR * .349) + (brightnessG * .686) + (brightnessB * .168);
			brightnessB = (brightnessR * .272) + (brightnessG * .534) + (brightnessB * .131);

			if (brightnessR > 255) { brightnessR = 255; }
			if (brightnessG > 255) { brightnessG = 255; }
			if (brightnessB > 255) { brightnessB = 255; }

			img_setPixelChannel(img, x, y, (unsigned char) brightnessR, red);
			img_setPixelChannel(img, x, y, (unsigned char) brightnessG, green);
			img_setPixelChannel(img, x, y, (unsigned char) brightnessB, blue);
		}
	}
}
