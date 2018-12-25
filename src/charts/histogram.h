#ifndef MINIGIMP_HISTOGRAM_H
#define MINIGIMP_HISTOGRAM_H

#include "../imac-img.h"

/**
 * @brief Create an average histogram of the image
 *
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
static void _printHistogram(ImacImg* histogram, unsigned int* histogramData, unsigned int maxData, unsigned char printColor);

#endif //MINIGIMP_HISTOGRAM_H