/**
 * @file constrast.h
 * @brief Change contrast
 */
#ifndef MINIGIMP_CONTRAST_H
#define MINIGIMP_CONTRAST_H

#include "core/imac-img.h"
#include "core/imac-lut1d.h"

/**
 * @brief Add value to each color of the lut
 *
 * @param lut
 * @param value
 */
void contrast_addToLut1d(ImacLut1d *lut, unsigned char value);

/**
 * @brief Reduce value to each color of the lut
 *
 * @param lut
 * @param value
 */
void contrast_dimToLut1d(ImacLut1d *lut, unsigned char value);

#endif //MINIGIMP_CONTRAST_H
