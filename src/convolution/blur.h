/**
 * @file blur.h
 * @brief Convolution based effects for blur
 */
#ifndef MINIGIMP_BLUR_H
#define MINIGIMP_BLUR_H

#include "core/imac-img.h"
#include "core/utils.h"

/**
 * @brief Blur the image with a specified level
 *
 * @param[in] image
 * @param[in] output image
 * @param[in] blur intensity
 */
void blur_img(ImacImg *img, ImacImg *outputImg, int value);

// TODO verifier que bien convolution https://en.wikipedia.org/wiki/Kernel_(image_processing)

#endif //MINIGIMP_BLUR_H
