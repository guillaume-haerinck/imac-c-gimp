#ifndef MINIGIMP_HISTOGRAM_H
#define MINIGIMP_HISTOGRAM_H

#include "core/imac-img.h"
#define HIST_SIZE 256

/**
 * @brief Find the highest number of similar brightness 
 *
 * @param[in] imgToAnalyseimgBrightnessSpectrum[4][HIST_SIZE]
 * @param[in] maxPixelsForBrightness[4]
 * @return EXIT_FAILURE or EXIT_SUCCESS
 */

void get_maxBrightness(unsigned int imgBrightnessSpectrum[rvb+1][HIST_SIZE], unsigned int maxPixelsForBrightness[rvb+1]);

/**
 * @brief Create an average histogram of the image
 *
 * @param[in] imgToAnalyse
 * @param[in] imgToAnalyseimgBrightnessSpectrum[4][HIST_SIZE]
 * @return EXIT_FAILURE or EXIT_SUCCESS
 */
void build_histogram(ImacImg* imgToAnalyse, unsigned int imgBrightnessSpectrum[rvb+1][HIST_SIZE]);

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

/**
 * @brief Private function used to print histogram data to an image
 *
 * @param histogram
 * @param histogramData
 * @param maxData - Values above will be clamped
 * @param printColor - The color of the printed graph
 */
static void _printHistogram(ImacImg* histogram, unsigned int* histogramData, unsigned int maxData, unsigned char printColor, enum img_Channel);

#endif //MINIGIMP_HISTOGRAM_H
