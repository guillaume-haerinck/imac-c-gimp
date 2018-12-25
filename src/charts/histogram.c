#include <stdlib.h>
#include <stdio.h>
#include "histogram.h"
#include "../image-loaders/ppm.h"
#include "../utils.h"

int hist_rgb(ImacImg* imgToAnalyse, ImacImg* histogram) {
    unsigned int imgBrightnessSpectrum[256] = { 0 };

    // Get values for histogram
    unsigned int pixelAvgBrightness = 0;
    unsigned int maxPixelsForBrightness = 0;
    for (unsigned int x = 0; x < imgToAnalyse->width; x++) {
        for (unsigned int y = 0; y < imgToAnalyse->height; y++) {
            for (int c = red; c <= blue; c++) {
                pixelAvgBrightness += img_getPixelChannel(imgToAnalyse, x, y, c);
            }
            pixelAvgBrightness = pixelAvgBrightness / 3;
            imgBrightnessSpectrum[(unsigned char) pixelAvgBrightness] += 1;
            if (imgBrightnessSpectrum[(unsigned char) pixelAvgBrightness] > maxPixelsForBrightness) {
                maxPixelsForBrightness = imgBrightnessSpectrum[(unsigned char) pixelAvgBrightness];
            }
            pixelAvgBrightness = 0;
        }
    }

    // Print histogram to file
    img_setToWhite(histogram);
    for (unsigned int x = 0; x < histogram->width; x++) {
        long columnHeight = linearMapping(imgBrightnessSpectrum[x], 0, maxPixelsForBrightness, 0, histogram->height);
        long columnEnd = histogram->height - columnHeight;
        for (unsigned int y = histogram->height - 1; y > columnEnd; y--) {
            img_setPixelChannels(histogram, x, y, 0);
        }
    }
    return EXIT_SUCCESS;
};