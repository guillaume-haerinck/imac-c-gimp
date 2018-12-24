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

#endif //MINIGIMP_HISTOGRAM_H