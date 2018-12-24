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
    for (int x = 0; x < imgToAnalyse->width; x++) {
        for (int y = 0; y < imgToAnalyse->height; y++) {
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

    // TODO histogram is inverted, put top to bottom
    img_setImageToWhite(histogram);
    for (int x = 0; x < histogram->width; x++) {
        int columnHeight = linearMapping(imgBrightnessSpectrum[x], 0, maxPixelsForBrightness, 0, histogram->height);
        if (columnHeight > histogram->height) {
            printf("linearMapping not working \n");
        }
        for (int y = 0; y < columnHeight; y++) {
            img_setPixelChannels(histogram, x, y, 0);
        }
    }
    return EXIT_SUCCESS;
};