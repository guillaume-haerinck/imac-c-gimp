/**
 * @file blur.h
 * @brief Convolution based effects for blur
 */
#ifndef MINIGIMP_BLUR_H
#define MINIGIMP_BLUR_H

#include "core/imac-img.h"
#include "core/utils.h"
#include "core/imac-kernel.h"

/**
 * @brief Blur the image with a specified level
 *
 * @param[in] image
 * @param[in] output image
 * @param[in] blur intensity
 */
void blur_imgRecursive(ImacImg *img, ImacImg *outputImg, int value);

/**
 * @brief Blur the image
 *
 * @param[in] image
 * @param[in] output image
 */
void blur_imgKernel(ImacImg* img, ImacImg* outputImg);

#endif //MINIGIMP_BLUR_H
