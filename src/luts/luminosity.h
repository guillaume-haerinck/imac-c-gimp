/**
 * @file luminosity.h
 * @brief change luminosity lut
 */
#ifndef MINIGIMP_LUMINOSITY_H
#define MINIGIMP_LUMINOSITY_H

#include "../imac-img.h"

/**
 * @brief Add value to each color
 *
 * @param img
 * @param value
 */
void addLuminosity(ImacImg* img, unsigned char value);

/**
 * @brief Substract value to each color
 *
 * @param img
 * @param value
 */
void dimLuminosity(ImacImg* img, unsigned char value);

#endif //MINIGIMP_LUMINOSITY_H
