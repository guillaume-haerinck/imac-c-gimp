/**
 * @file blur.h
 * @brief Convolution based effects for blur
 */
#ifndef MINIGIMP_BLUR_H
#define MINIGIMP_BLUR_H

#include "core/imac-img.h"

/**
 * @brief Blur the image with a specified level
 *
 * @param[in] image
 * @param[in] output image
 * @param[in] blur intensity
 */
void blur_img(ImacImg *img, ImacImg *outputImg, int value);

#endif //MINIGIMP_BLUR_H