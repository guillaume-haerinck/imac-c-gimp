/**
 * @file imac-lut3d.h
 * @brief Look up table handler
 *
 */

#ifndef MINIGIMP_IMAC_LUT_H
#define MINIGIMP_IMAC_LUT_H

#include "imac-img.h"

// --------------------- STRUCT & ENUMS

/**
 * @struct ImacLut
 * @note You need to use lut3d_new to init it
 */
typedef struct ImacLut {
    int size;
    unsigned char* dataR;
    unsigned char* dataG;
    unsigned char* dataB;
} ImacLut;

// --------------------- CONSTRUCTOR & DESTRUCTOR

/**
 * @brief Constructor for ImacLut
 * @note Don't forget to call lut3d_delete once you are done with the lut3d
 *
 * @param lut3d
 * @return
 */
int lut3d_new(ImacLut* lut3d);

/**
 * @brief Destructor for ImacLut
 *
 * @param lut3d
 * @return
 */
int lut3d_delete(ImacLut* lut3d);

// ---------------------- SETTERS

/**
 * @brief Set the lut3d data with security
 *
 * @param lut3d
 * @param index
 * @param value
 * @return brightness
 */
void lut3d_set(ImacLut* lut3d, unsigned int index, unsigned char value, int c);

/**
 * @brief Apply the lut3d to the all the channels of the image
 *
 * @param lut3d
 * @param img
 * @return
 */
int lut3d_applyRgb(ImacLut* lut3d, ImacImg* img);

// ----------------------- GETTERS

/**
 * @brief Access the lut3d data with security
 *
 * @param lut3d
 * @param index
 * @return brightness
 */
unsigned char lut3d_get(ImacLut* lut3d, unsigned int index, int c);

/**
 *
 * @brief Print the lut3d on debug screen.
 * @param lut3d
 */
void lut3d_print(ImacLut* lut3d);

#endif //MINIGIMP_IMAC_LUT_H
