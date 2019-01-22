/**
 * @file sepia.h
 * @brief sepia effect
 */
#ifndef MINIGIMP_SEPIA_H
#define MINIGIMP_SEPIA_H

#include "core/imac-img.h"
#include "core/imac-lut3x1d.h"

/**
 * @brief Apply sepia effect to 3x1d lut
 *
 * @param lut
 */
void sepia_addToLut3x1d(ImacLut3x1d *lut);

/**
 * @brief Apply sepia effect to image
 *
 * @param img
 */
void sepia_addToImg(ImacImg* img);

#endif //MINIGIMP_SEPIA_H
