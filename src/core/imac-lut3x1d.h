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
 * @note You need to use lut3d_new to init it
 */

typedef struct ImacLut3x1d {
    unsigned char channelSize;
    unsigned char* dataR;
    unsigned char* dataG;
    unsigned char* dataB;
} ImacLut3x1d;

// --------------------- CONSTRUCTOR & DESTRUCTOR

/**
 * @brief Constructor for ImacLut3d
 * @note Don't forget to call lut3d_delete once you are done with the lut3d
 *
 * @param lut3d
 * @return EXIT_SUCCESS or EXIT_FAILURE
 */
int lut3d_new(ImacLut3x1d* lut3d);

/**
 * @brief Destructor for ImacLut
 *
 * @param lut3d
 * @return EXIT_SUCCESS or EXIT_FAILURE
 */
int lut3d_delete(ImacLut3x1d* lut3d);

// ---------------------- SETTERS

/**
 * @brief Set the lut3d data with security
 *
 * @param lut3d
 * @param index
 * @param value
 * @param channel
 */
void lut3d_set(ImacLut3x1d* lut3d, unsigned int index, unsigned char value, enum img_Channel c);

/**
 * @brief Apply the lut3d to the image
 *
 * @param lut3d
 * @param img
 * @return EXIT_SUCCESS or EXIT_FAILURE
 */
void lut3d_apply(ImacLut3x1d* lut3d, ImacImg* img);

// ----------------------- GETTERS

/**
 * @brief Access the lut3d data with security
 *
 * @param lut3d
 * @param index
 * @param channel
 * @return brightness
 */
unsigned char lut3d_get(ImacLut3x1d* lut3d, unsigned int index, enum img_Channel c);

/**
 *
 * @brief Print the lut3d on debug screen.
 * @param lut3d
 */
void lut3d_print(ImacLut3x1d* lut3d);

#endif //MINIGIMP_IMAC_LUT3D_H
