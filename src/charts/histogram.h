#ifndef MINIGIMP_HISTOGRAM_H
#define MINIGIMP_HISTOGRAM_H

#include "core/imac-img.h"
#define HIST_SIZE 256

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
