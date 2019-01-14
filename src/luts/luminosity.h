/**
 * @file luminosity.h
 * @brief Change luminosity
 */
#ifndef MINIGIMP_LUMINOSITY_H
#define MINIGIMP_LUMINOSITY_H

#include "core/imac-img.h"
#include "core/imac-lut1d.h"

/**
 * @brief Add value to each color of the image
 *
 * @param img
 * @param value
 */
void lum_addToImg(ImacImg* img, int value);

/**
 * @brief Add value to each color of the lut
 *
 * @param lut
 * @param value
 */
void lum_addToLut1d(ImacLut1d *lut, int value);

/**
 * @brief Substract value to each color of the image
 *
 * @param img
 * @param value
 */
void lum_dimToImg(ImacImg* img, int value);

/**
 * @brief Substract value to each color of the lut
 *
 * @param lut
 * @param value
 */
void lum_dimToLut1d(ImacLut1d *lut, int value);

#endif //MINIGIMP_LUMINOSITY_H
