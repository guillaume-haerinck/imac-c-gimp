/**
 * @file imac-lut1d.h
 * @brief 1D Look up table handler
 *
 */

#ifndef MINIGIMP_IMAC_LUT_H
#define MINIGIMP_IMAC_LUT_H

#include "imac-img.h"

// --------------------- STRUCT & ENUMS

/**
 * @struct ImacLut1d
 * @note You need to use lut_new to init it
 */
typedef struct ImacLut1d {
    unsigned int size;
    unsigned char* data;
} ImacLut1d;

// --------------------- CONSTRUCTOR & DESTRUCTOR

/**
 * @brief Constructor for ImacLut
 * @note Don't forget to call lut_delete once you are done with the lut
 *
 * @param lut
 * @return
 */
int lut_new(ImacLut1d* lut);

/**
 * @brief Destructor for ImacLut
 *
 * @param lut
 * @return
 */
int lut_delete(ImacLut1d* lut);

// ---------------------- SETTERS

/**
 * @brief Set the lut data with security
 *
 * @param lut
 * @param index
 * @param value
 * @return brightness
 */
void lut_set(ImacLut1d* lut, unsigned int index, int value);

/**
 * @brief Apply the lut to the all the channels of the image
 *
 * @param lut
 * @param img
 */
void lut_applyRgb(ImacLut1d* lut, ImacImg* img);

// ----------------------- GETTERS

/**
 * @brief Access the lut data with security
 *
 * @param lut
 * @param index
 * @return brightness
 */
unsigned int lut_get(ImacLut1d* lut, unsigned int index);

#endif //MINIGIMP_IMAC_LUT_H
