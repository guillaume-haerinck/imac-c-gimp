#include <stdlib.h>
#include <stdio.h>
#include "histogram.h"
#include "../image-loaders/ppm.h"
#include "../core/utils.h"

// TODO parfois histogramme s'affiche mal, debugger
int hist_rgb(ImacImg* imgToAnalyse, ImacImg* histogram) {
    img_setToWhite(histogram);
    unsigned int imgBrightnessSpectrum[4][256] = {{0},{0},{0},{0}};

    // Get values for histogram
    unsigned int pixelAvgBrightness[4] = {0};
    unsigned int maxPixelsForBrightness[4] = {0};
    for (unsigned int x = 0; x < imgToAnalyse->width; x++) {
        for (unsigned int y = 0; y < imgToAnalyse->height; y++) {
            for (int c = red; c <= blue; c++) {
                pixelAvgBrightness[3] += img_getPixelChannel(imgToAnalyse, x, y, c);
		pixelAvgBrightness[c] += img_getPixelChannel(imgToAnalyse, x, y, c);
            }
            pixelAvgBrightness[3] = pixelAvgBrightness[3] / 3;
            imgBrightnessSpectrum[3][(unsigned char) pixelAvgBrightness[3]] += 1;
            if (imgBrightnessSpectrum[3][(unsigned char) pixelAvgBrightness[3]] > maxPixelsForBrightness[3]) {
                maxPixelsForBrightness[3] = imgBrightnessSpectrum[3][(unsigned char) pixelAvgBrightness[3]];
            }
            for (int c = red; c <= blue; c++) {
		    imgBrightnessSpectrum[c][(unsigned char) pixelAvgBrightness[c]] += 1;
		    if (imgBrightnessSpectrum[c][(unsigned char) pixelAvgBrightness[c]] > maxPixelsForBrightness[c]) {
			    maxPixelsForBrightness[c] = imgBrightnessSpectrum[c][(unsigned char) pixelAvgBrightness[c]];
		    }
            }
            pixelAvgBrightness[3] = 0;
            for (int c = red; c <= blue; c++) {
		    pixelAvgBrightness[c] = 0;
            }
        }
    }

    // Print histogram to file
    for (int c = red; c <= blue; c++) {
	    _printHistogram(histogram, imgBrightnessSpectrum[c], maxPixelsForBrightness[c], 255, c);
    }
    _printHistogram(histogram, imgBrightnessSpectrum[3], maxPixelsForBrightness[3], 150, rvb);
    return EXIT_SUCCESS;
};

int hist_channel(ImacImg* imgToAnalyse, ImacImg* histogram, enum img_Channel c) {
    img_setToWhite(histogram);
    unsigned int imgBrightnessSpectrum[255] = { 0 };

    // Get values for histogram
    unsigned int pixelBrightness = 0;
    unsigned int maxPixelsForBrightness = 0;
    for (unsigned int x = 0; x < imgToAnalyse->width; x++) {
        for (unsigned int y = 0; y < imgToAnalyse->height; y++) {
            pixelBrightness = img_getPixelChannel(imgToAnalyse, x, y, c);
            imgBrightnessSpectrum[(unsigned char) pixelBrightness] += 1;
            if (imgBrightnessSpectrum[(unsigned char) pixelBrightness] > maxPixelsForBrightness) {
                maxPixelsForBrightness = imgBrightnessSpectrum[(unsigned char) pixelBrightness];
            }
            pixelBrightness = 0;
        }
    }

    // Print histogram to file
    _printHistogram(histogram, imgBrightnessSpectrum, maxPixelsForBrightness, 255, c);
    return EXIT_SUCCESS;
};

static void _printHistogram(ImacImg* histogram, unsigned int* histogramData, unsigned int maxData, unsigned char printColor, enum img_Channel c) {

    if (histogram->width != 256) {
        printf("_printHistogram error: histogram not 256 width");
        exit(EXIT_FAILURE);
    }

    for (unsigned int x = 0; x < histogram->width; x++) {
        long columnHeight = linearMapping(histogramData[x], 0, maxData, 0, histogram->height);
        long columnEnd = histogram->height - columnHeight;
        for (unsigned int y = histogram->height - 1; y > columnEnd; y--) {
            if (c == rvb) img_setPixelChannels(histogram, x, y, printColor);
	    else {
	    	for (unsigned char ch = red; ch<=blue; ch++){
			if (ch == c) img_setPixelChannel(histogram, x, y, printColor, c);
			else img_setPixelChannel(histogram, x, y, 0, ch);
		}
	    }
        }
    }
}
