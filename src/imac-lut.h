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
 * @brief Apply the lut to the image
 *
 * @param lut
 * @param img
 * @return
 */
int lut_apply(ImacLut* lut, ImacImg* img);

#endif //MINIGIMP_IMAC_LUT_H
