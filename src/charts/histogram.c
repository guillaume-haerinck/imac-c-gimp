#include <stdlib.h>
#include <stdio.h>
#include "histogram.h"
#include "../image-loaders/ppm.h"

int hist_rgb(ImacImg* imgToAnalyse) {
    unsigned int imgBrightnessSpectrum[256] = { 0 };

    // Get values for histogram
    unsigned int pixelAvgBrightness = 0;
    unsigned int maxBrightness = 0;
    for (int x = 0; x < imgToAnalyse->width; x++) {
        for (int y = 0; y < imgToAnalyse->height; y++) {
            for (int c = red; c <= blue; c++) {
                pixelAvgBrightness += img_getPixelChannel(imgToAnalyse, x, y, c);
            }
            pixelAvgBrightness = pixelAvgBrightness / 3;
            imgBrightnessSpectrum[(unsigned char) pixelAvgBrightness] += 1;
            if (imgBrightnessSpectrum[(unsigned char) pixelAvgBrightness] > maxBrightness) {
                maxBrightness = imgBrightnessSpectrum[(unsigned char) pixelAvgBrightness];
            }
            pixelAvgBrightness = 0;
        }
    }

    ImacImg histogram;
    img_new(&histogram, 256, 150);
    img_setImageToWhite(&histogram);
    for (int x = 0; x < histogram.width; x++) {
        printf("%d ", imgBrightnessSpectrum[x]);
        int columnHeight = imgBrightnessSpectrum[x];
        if (columnHeight > histogram.height) {
            columnHeight = histogram.height;
        }
        for (int y = 0; y < columnHeight; y++) {
            img_setPixelChannels(&histogram, x, y, 0);
        }
    }
    printf("\n");

    // TODO use the image with and height to make the histogram dynamically.

    ppm_save("./histogram.ppm", &histogram);
    return EXIT_SUCCESS;
};