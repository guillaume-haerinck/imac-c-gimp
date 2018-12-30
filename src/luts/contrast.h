/**
 * @file constrast.h
 * @brief Change contrast
 */
#ifndef MINIGIMP_CONTRAST_H
#define MINIGIMP_CONTRAST_H

#include "../imac-img.h"
#include "../imac-lut.h"

/**
 * @brief Add value to each color of the lut
 *
 * @param lut
 * @param value
 */
void contrast_addToLut(ImacLut* lut, unsigned char value);

/**
 * @brief Reduce value to each color of the lut
 *
 * @param lut
 * @param value
 */
void contrast_dimToLut(ImacLut* lut, unsigned char value);

#endif //MINIGIMP_CONTRAST_H
