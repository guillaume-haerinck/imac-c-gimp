/**
 * @file convolution.h
 * @brief Convolution based effects
 */
#ifndef MINIGIMP_CONVOLUTION_H
#define MINIGIMP_CONVOLUTION_H

#include "core/imac-img.h"

/**
 * @brief Calculte the matrix shift value (recursive function)
 *
 * @param[in] Matrix size
 * @param[out] Matrix shift
 */
int recursiveMatrix(int n);
/**
 * @brief Blur the image with a specified level
 *
 * @param[in] image
 * @param[in] output image
 * @param[in] blur intensity
 */
void convolution_blur(ImacImg *img, ImacImg *outputImg, int value);
#endif //MINIGIMP_CONVOLUTION_H
