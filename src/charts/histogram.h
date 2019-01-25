#ifndef MINIGIMP_HISTOGRAM_H
#define MINIGIMP_HISTOGRAM_H

#include "core/imac-img.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define HIST_SIZE 256
#define HIST_HEIGHT 15

/**
 * @brief Create an average histogram of the image
 *
 * @param[in] imgToAnalyse
 * @param[in] imgToAnalyseimgBrightnessSpectrum[4][HIST_SIZE]
 * @return EXIT_FAILURE or EXIT_SUCCESS
 */
void hist_buildHistogram(ImacImg* imgToAnalyse, unsigned int imgBrightnessSpectrum[rvb+1][HIST_SIZE]);

/**
 * @brief Find the highest number of similar brightness 
 *
 * @param[in] imgToAnalyseimgBrightnessSpectrum[4][HIST_SIZE]
 * @param[in] maxPixelsForBrightness[4]
 * @return EXIT_FAILURE or EXIT_SUCCESS
 */
void hist_getMaxBrightness(unsigned int imgBrightnessSpectrum[rvb+1][HIST_SIZE], unsigned int maxPixelsForBrightness[rvb+1]);

/**
 * @brief Get max Brightness for a one dimensional array
 *
 * @param[in] histogram[size]
 * @param[in] size
 * @param[out] max brightness value index
 */
int hist_findMaxIndex(int *histogram, int histSize);

/**
 * @brief Build an appropriate histogram array for terminal printing
 * @note You must free the pointer after you are done with it
 *
 * @param[in] outputHistogram[256]
 * @param[in] outputHist[scale]
 * @param[out] pointer on new array
 */
int *hist_initScaledHistogram(int *outputHistogram, int scale);

void hist_printHistValues(int *histogram, int nbOfValues);

/**
 * @brief Fill scaled histogram array for terminal printing
 *
 * @param[in] inputHist[256]
 * @param[in] outputHist[scale]
 * @param[in] scale
 */
void hist_fillScaledHistogram(int *inputHist, int *outputHist, int scale);

/**
 * @brief Print two histograms in the terminal side by side
 *
 * @param[in] histogram1[256]
 * @param[in] histogram2[256]
 * @param[in] scaleX
 */
void hist_printTerminal(unsigned int *histogram1, unsigned int *histogram2, int scaleX);

/**
 * @brief Print histogram data to an image
 *
 * @param histogram
 * @param histogramData
 * @param maxData - Values above will be clamped
 * @param printColor - The color of the printed graph
 */
void hist_printHistogram(ImacImg* histogram, unsigned int* histogramData, unsigned int maxData, unsigned char printColor, enum img_Channel);

/**
 * @brief Call the functions to build the histogram and put it into an image
 * @param[in] imgToAnalyse
 * @param[out] histogram
 * @return EXIT_FAILURE or EXIT_SUCCESS
 */
int hist_rgb(ImacImg* imgToAnalyse, ImacImg* histogram);

/**
 * @brief Create an histogram of the image for the selected channel
 *
 * @param[in] imgToAnalyse
 * @param[out] histogram
 * @param c - Color channel
 * @return EXIT_FAILURE or EXIT_SUCCESS
 */
int hist_channel(ImacImg* imgToAnalyse, ImacImg* histogram, enum img_Channel c);

#endif //MINIGIMP_HISTOGRAM_H
