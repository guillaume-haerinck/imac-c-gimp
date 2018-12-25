#include <stdlib.h>
#include <stdio.h>
#include "histogram.h"
#include "image-loaders/ppm.h"
#include "utils.h"

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
    _printHistogram(histogram, imgBrightnessSpectrum, maxPixelsForBrightness, 150);
    return EXIT_SUCCESS;
};

int hist_channel(ImacImg* imgToAnalyse, ImacImg* histogram, enum img_Channel c) {
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
    _printHistogram(histogram, imgBrightnessSpectrum, maxPixelsForBrightness, 53);
    return EXIT_SUCCESS;
};

static void _printHistogram(ImacImg* histogram, unsigned int* histogramData, unsigned int maxData, unsigned char printColor) {
    img_setToWhite(histogram);

    if (histogram->width != 256) {
        printf("_printHistogram error: histogram not 256 width");
        exit(EXIT_FAILURE);
    }

    for (unsigned int x = 0; x < histogram->width; x++) {
        long columnHeight = linearMapping(histogramData[x], 0, maxData, 0, histogram->height);
        long columnEnd = histogram->height - columnHeight;
        for (unsigned int y = histogram->height - 1; y > columnEnd; y--) {
            img_setPixelChannels(histogram, x, y, printColor);
        }
    }
}