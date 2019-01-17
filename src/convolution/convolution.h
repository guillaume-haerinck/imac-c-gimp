/**
 * @file convolution.h
 * @brief Convolution based effects
 */
#ifndef MINIGIMP_CONVOLUTION_H
#define MINIGIMP_CONVOLUTION_H

#include "core/imac-img.h"

int recursiveMatrix(int n);
/**
 * @brief Add value to each color of the lut
 *
 * @param lut
 * @param value
 */
void convolution_blur(ImacImg *img, ImacImg *outputImg, int value);
#endif //MINIGIMP_CONVOLUTION_H
