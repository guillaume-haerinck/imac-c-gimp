/**
 * @file blur.h
 * @brief Convolution based effects for blur
 */
#ifndef MINIGIMP_BLUR_H
#define MINIGIMP_BLUR_H

#include <math.h>
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
 * @brief Blur the image with a specified level at a specific position
 *
 * @param[in] image
 * @param[in] output image
 * @param[in] posX gradient position in image
 * @param[in] posY gradient position in image
 * @param[in] blur intensity
 */
void blur_vignette(ImacImg *img, ImacImg *outputImg, int value, int posX, int posY);

/**
 * @brief Blur the image
 *
 * @param[in] image
 * @param[in] output image
 */
void blur_imgKernel(ImacImg* img, ImacImg* outputImg);

#endif //MINIGIMP_BLUR_H
