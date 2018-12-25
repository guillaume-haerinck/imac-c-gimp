/**
 * @file luminosity.h
 * @brief Change luminosity
 */
#ifndef MINIGIMP_LUMINOSITY_H
#define MINIGIMP_LUMINOSITY_H

#include "imac-img.h"
#include "imac-lut.h"

/**
 * @brief Add value to each color of the image
 *
 * @param img
 * @param value
 */
void lum_addToImg(ImacImg* img, unsigned char value);

/**
 * @brief Add value to each color of the lut
 *
 * @param lut
 * @param value
 */
void lum_addToLut(ImacLut* lut, unsigned char value);

/**
 * @brief Substract value to each color of the image
 *
 * @param img
 * @param value
 */
void lum_dimToImg(ImacImg* img, unsigned char value);

/**
 * @brief Substract value to each color of the lut
 *
 * @param lut
 * @param value
 */
void lum_dimToLut(ImacLut* lut, unsigned char value);

#endif //MINIGIMP_LUMINOSITY_H
