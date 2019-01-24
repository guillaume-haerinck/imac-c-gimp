/**
 * @file imac-lut3x1d.h
 * @brief 3x 1D look up table handler
 *
 */

#ifndef MINIGIMP_IMAC_LUT3D_H
#define MINIGIMP_IMAC_LUT3D_H

#include "imac-img.h"

// --------------------- STRUCT & ENUMS

/**
 * @struct ImacLut3x1d
 * @note You need to use lut3x1d_new to init it
 */

typedef struct ImacLut3x1d {
    unsigned int channelSize;
    unsigned char* dataR;
    unsigned char* dataG;
    unsigned char* dataB;
} ImacLut3x1d;

// --------------------- CONSTRUCTOR & DESTRUCTOR

/**
 * @brief Constructor for ImacLut3x1d
 * @note Don't forget to call lut3x1d_delete once you are done with the lut3x1d
 *
 * @param lut3x1d
 * @return EXIT_SUCCESS or EXIT_FAILURE
 */
int lut3x1d_new(ImacLut3x1d* lut3x1d);

/**
 * @brief Destructor for ImacLut
 *
 * @param lut3x1d
 * @return EXIT_SUCCESS or EXIT_FAILURE
 */
int lut3x1d_delete(ImacLut3x1d* lut3x1d);

// ---------------------- SETTERS

/**
 * @brief Set the lut3x1d data with security
 *
 * @param lut3x1d
 * @param index
 * @param value
 * @param channel
 */
void lut3x1d_set(ImacLut3x1d* lut3x1d, unsigned int index, unsigned int value, enum img_Channel c);

/**
 * @brief Apply the lut3x1d to the image
 *
 * @param lut3x1d
 * @param img
 * @return EXIT_SUCCESS or EXIT_FAILURE
 */
void lut3x1d_apply(ImacLut3x1d* lut3x1d, ImacImg* img);

// ----------------------- GETTERS

/**
 * @brief Access the lut3x1d data with security
 *
 * @param lut3x1d
 * @param index
 * @param channel
 * @return brightness
 */
unsigned int lut3x1d_get(ImacLut3x1d* lut3x1d, unsigned int index, enum img_Channel c);

#endif //MINIGIMP_IMAC_LUT3D_H
