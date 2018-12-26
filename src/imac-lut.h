/**
 * @file imac-lut.h
 * @brief Look up table handler
 *
 */

#ifndef MINIGIMP_IMAC_LUT_H
#define MINIGIMP_IMAC_LUT_H

#include "imac-img.h"

// --------------------- STRUCT & ENUMS

/**
 * @struct ImacLut
 * @note You need to use lut_new to init it
 */
typedef struct ImacLut {
    unsigned char size;
    unsigned char* data;
} ImacLut;

// --------------------- CONSTRUCTOR & DESTRUCTOR

/**
 * @brief Constructor for ImacLut
 * @note Don't forget to call lut_delete once you are done with the lut
 *
 * @param lut
 * @return
 */
int lut_new(ImacLut* lut);

/**
 * @brief Destructor for ImacLut
 *
 * @param lut
 * @return
 */
int lut_delete(ImacLut* lut);

// ---------------------- SETTERS

/**
 * @brief Set the lut data with security
 *
 * @param lut
 * @param index
 * @param value
 * @return brightness
 */
void lut_set(ImacLut* lut, unsigned int index, unsigned char value);

/**
 * @brief Apply the lut to the all the channels of the image
 *
 * @param lut
 * @param img
 * @return
 */
int lut_applyRgb(ImacLut* lut, ImacImg* img);

// ----------------------- GETTERS

/**
 * @brief Access the lut data with security
 *
 * @param lut
 * @param index
 * @return brightness
 */
unsigned char lut_get(ImacLut* lut, unsigned int index);

/**
 *
 * @brief Print the lut on debug screen.
 * @param lut
 */
void lut_print(ImacLut* lut);

#endif //MINIGIMP_IMAC_LUT_H
