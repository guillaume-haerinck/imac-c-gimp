#include "sepia.h"
#include <stdio.h>

void sepia_addToLut3x1d(ImacLut3x1d *lut) {
    double brightnessR = 0, brightnessG = 0, brightnessB = 0;

    // FIXME
    /*
    for (unsigned int r = 0; r <= lut3d->channelSize; r++) {
	    for (unsigned int g = 0; g <= lut3d->channelSize; g++) {
		    for (unsigned int b = 0; b <= lut3d->channelSize; b++) {
			    //brightnessR = (red*.33) + (green * .33) + (blue * .33);
			    brightnessR = (r * .393) + (g * .769) + (b * .189);
			    brightnessG = (r * .349) + (g * .686) + (b * .168);
			    brightnessB = (r * .272) + (g * .534) + (b * .131);
				// lut3d_set(lut3d, r, (unsigned char) brightnessR, red);
				lut3d_set(lut3d, g, (unsigned char) brightnessG, green);
				lut3d_set(lut3d, b, (unsigned char) brightnessB, blue);
		    }
	    }
    }
     */

	// FIXME
    for (unsigned int i = 0; i <= lut->channelSize; i++) {
    	brightnessR = lut3d_get(lut, i, red);
		brightnessG = lut3d_get(lut, i, green);
		brightnessB = lut3d_get(lut, i, blue);

	    brightnessR = (brightnessR * .393) + (brightnessG * .769) + (brightnessB * .189);
	    brightnessG = (brightnessR * .349) + (brightnessG * .686) + (brightnessB * .168);
	    brightnessB = (brightnessR * .272) + (brightnessG * .534) + (brightnessB * .131);

	    if (brightnessR > 255) { brightnessR = 255; }
		if (brightnessG > 255) { brightnessG = 255; }
		if (brightnessB > 255) { brightnessB = 255; }

	    lut3d_set(lut, i, (unsigned char) brightnessR, red);
		lut3d_set(lut, i, (unsigned char) brightnessG, green);
		lut3d_set(lut, i, (unsigned char) brightnessB, blue);
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