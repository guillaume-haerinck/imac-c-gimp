#include <stdlib.h>
#include <stdio.h>
#include "histogram.h"
#include "../image-loaders/ppm.h"
#include "../core/utils.h"

// ------------------------------------------- PRIVATE FUNCTIONS

/**
 * @brief Create an average histogram of the image
 *
 * @param[in] imgToAnalyse
 * @param[in] imgToAnalyseimgBrightnessSpectrum[4][HIST_SIZE]
 * @return EXIT_FAILURE or EXIT_SUCCESS
 */
static void hist_buildHistogram(ImacImg* imgToAnalyse, unsigned int imgBrightnessSpectrum[rvb+1][HIST_SIZE]);
static void hist_buildHistogram(ImacImg* imgToAnalyse, unsigned int imgBrightnessSpectrum[rvb+1][HIST_SIZE]) {
    // Get values for histogram
    unsigned int pixelAvgBrightness[4] = {0};
    for (unsigned int x = 0; x < imgToAnalyse->width; x++) {
        for (unsigned int y = 0; y < imgToAnalyse->height; y++) {
            for (int c = red; c <= blue; c++) {
                pixelAvgBrightness[c] += img_getPixelChannel(imgToAnalyse, x, y, (enum img_Channel) c);
                imgBrightnessSpectrum[c][(unsigned char) pixelAvgBrightness[c]] += 1;
            }

            pixelAvgBrightness[rvb] = (pixelAvgBrightness[red] + pixelAvgBrightness[green] + pixelAvgBrightness[blue])/ 3;
	        imgBrightnessSpectrum[rvb][(unsigned char) pixelAvgBrightness[rvb]] += 1;
            for (int c = red; c <= blue; c++) {
                pixelAvgBrightness[c] = 0;
            }
        }
    }
}

/**
 * @brief Find the highest number of similar brightness 
 *
 * @param[in] imgToAnalyseimgBrightnessSpectrum[4][HIST_SIZE]
 * @param[in] maxPixelsForBrightness[4]
 * @return EXIT_FAILURE or EXIT_SUCCESS
 */
static void hist_getMaxBrightness(unsigned int imgBrightnessSpectrum[rvb+1][HIST_SIZE], unsigned int maxPixelsForBrightness[rvb+1]);
static void hist_getMaxBrightness(unsigned int imgBrightnessSpectrum[rvb+1][HIST_SIZE], unsigned int maxPixelsForBrightness[rvb+1]) {
    for (int i = 0; i<HIST_SIZE; i++) {
	    for (int c = red; c<=rvb; c++) {
		    if (imgBrightnessSpectrum[c][i] > maxPixelsForBrightness[c]) {
			    maxPixelsForBrightness[c] = imgBrightnessSpectrum[c][i];
		    }
	    }	
    }
}

/**
 * @brief Print histogram data to an image
 *
 * @param histogram
 * @param histogramData
 * @param maxData - Values above will be clamped
 * @param printColor - The color of the printed graph
 */
static void hist_printHistogram(ImacImg* histogram, unsigned int* histogramData, unsigned int maxData, unsigned char printColor, enum img_Channel);
static void hist_printHistogram(ImacImg* histogram, unsigned int* histogramData, unsigned int maxData, unsigned char printColor, enum img_Channel c) {
    if (histogram->width != 256) {
        printf("hist_printHistogram error: histogram not 256 width");
        exit(EXIT_FAILURE);
    }

    for (unsigned int x = 0; x < histogram->width; x++) {
        unsigned int columnHeight = linearMapping(histogramData[x], 0, maxData, 0, histogram->height);
        unsigned int columnEnd = histogram->height - columnHeight;

        for (unsigned int y = histogram->height - 1; y > columnEnd; y--) {
            if (c == rvb) img_setPixelChannels(histogram, x, y, printColor);
            else {
                for (int ch = red; ch <= blue; ch++) {
                    if (ch == c) img_setPixelChannel(histogram, x, y, printColor, c);
                    else img_setPixelChannel(histogram, x, y, 0, (enum img_Channel) ch);
                }
            }
        }
    }
}

// --------------------------------------------------- PUBLIC FUNCTIONS

int hist_rgb(ImacImg* imgToAnalyse, ImacImg* histogram) {
    img_setToWhite(histogram);
    unsigned int imgBrightnessSpectrum[4][256] = {{0},{0},{0},{0}};
    hist_buildHistogram(imgToAnalyse, imgBrightnessSpectrum);
    unsigned int maxPixelsForBrightness[4] = {0};
    hist_getMaxBrightness(imgBrightnessSpectrum, maxPixelsForBrightness);
    unsigned char colorLevel = 0;

    // Print histogram to file
    for (int c = red; c <= rvb; c++) {
	    colorLevel = (c==rvb)?150:255;
	    hist_printHistogram(histogram, imgBrightnessSpectrum[c], maxPixelsForBrightness[c], colorLevel, (enum img_Channel) c);
    }
    return EXIT_SUCCESS;
}

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

    hist_printHistogram(histogram, imgBrightnessSpectrum, maxPixelsForBrightness, 255, c);
    return EXIT_SUCCESS;
}
