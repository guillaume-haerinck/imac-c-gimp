/**
 * @file inversion.h
 * @brief lut for image color inversion
 *
 * */

#ifndef MINIGIMP_INVERSION_H
#define MINIGIMP_INVERSION_H

#include "core/imac-img.h"
#include "core/imac-lut1d.h"

/**
 * @brief Invert color of the image on procedural calculation
 * @param img
 */
void inv_img(ImacImg* img);

/**
 * @brief Invert color of a LUT
 * @param lut
 */
void inv_lut1d(ImacLut1d *lut);

#endif //MINIGIMP_INVERSION_H
