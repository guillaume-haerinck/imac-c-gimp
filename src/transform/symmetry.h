#ifndef MINIGIMP_SYMMETRY_H
#define MINIGIMP_SYMMETRY_H

#include "core/imac-img.h"

/**
 * @brief Flip image from a vertical axis 
 *
 * @param[in] image
 */
void symmetry_flipV(ImacImg* img);

/**
 * @brief Flip image from a horizontal axis 
 *
 * @param[in] image
 */
void symmetry_flipH(ImacImg* img);

#endif // MINIGIMP_SYMMETRY_H
