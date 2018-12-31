/**
 * @file imac-lut3d.h
 * @brief 3D look up table handler
 *
 */

#ifndef MINIGIMP_IMAC_LUT3D_H
#define MINIGIMP_IMAC_LUT3D_H

#include "imac-img.h"

// --------------------- STRUCT & ENUMS

/**
 * @struct ImacLut3d
 * @note You need to use lut3d_new to init it
 */

// TODO voir si stocker dans un seul tableau de data est plus optimisé
typedef struct ImacLut3d {
    unsigned char channelSize;
    unsigned char* dataR;
    unsigned char* dataG;
    unsigned char* dataB;
} ImacLut3d;

// --------------------- CONSTRUCTOR & DESTRUCTOR

/**
 * @brief Constructor for ImacLut3d
 * @note Don't forget to call lut3d_delete once you are done with the lut3d
 *
 * @param lut3d
 * @return EXIT_SUCCESS or EXIT_FAILURE
 */
int lut3d_new(ImacLut3d* lut3d);

/**
 * @brief Destructor for ImacLut
 *
 * @param lut3d
 * @return EXIT_SUCCESS or EXIT_FAILURE
 */
int lut3d_delete(ImacLut3d* lut3d);

// ---------------------- SETTERS

/**
 * @brief Set the lut3d data with security
 *
 * @param lut3d
 * @param index
 * @param value
 * @param channel
 */
void lut3d_set(ImacLut3d* lut3d, unsigned int index, unsigned char value, enum img_Channel c);

/**
 * @brief Apply the lut3d to the image
 *
 * @param lut3d
 * @param img
 * @return EXIT_SUCCESS or EXIT_FAILURE
 */
void lut3d_apply(ImacLut3d* lut3d, ImacImg* img);

// ----------------------- GETTERS

/**
 * @brief Access the lut3d data with security
 *
 * @param lut3d
 * @param index
 * @param channel
 * @return brightness
 */
unsigned char lut3d_get(ImacLut3d* lut3d, unsigned int index, enum img_Channel c);

/**
 *
 * @brief Print the lut3d on debug screen.
 * @param lut3d
 */
void lut3d_print(ImacLut3d* lut3d);

#endif //MINIGIMP_IMAC_LUT3D_H
