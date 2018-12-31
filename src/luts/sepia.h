/**
 * @file sepia.h
 * @brief sepia effect
 */
#ifndef MINIGIMP_SEPIA_H
#define MINIGIMP_SEPIA_H

#include "../imac-img.h"
#include "../imac-lut3d.h"

/**
 * @brief Add value to each color of the lut 3d
 *
 * @param lut
 * @param value
 */
void sepia_addToLut3d(ImacLut3d* lut);

#endif //MINIGIMP_SEPIA_H
