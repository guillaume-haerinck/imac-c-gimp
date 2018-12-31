/**
 * @file sepia.h
 * @brief sepia effect
 */
#ifndef MINIGIMP_SEPIA_H
#define MINIGIMP_SEPIA_H

#include "../imac-img.h"
#include "../imac-lut3d.h"

/**
 * @brief Apply sepia effect to lut3d
 *
 * @param lut
 * @param value
 */
void sepia_addToLut3d(ImacLut3d* lut);

/**
 * @brief Apply sepia effect to image
 *
 * @param img
 */
void sepia_addToImg(ImacImg* img);

#endif //MINIGIMP_SEPIA_H
