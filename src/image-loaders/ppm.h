/**
 * @file ppm.h
 * @brief PPM image loader
 *
 * */

#ifndef MINIGIMP_PPM_H
#define MINIGIMP_PPM_H

#include "../imac-img.h"

/**
 * @brief Load a ppm image file and init the PPMImage pointer with it.
 * @note You must free the img data yourself.
 *
 * @param path - Relative path to the ppm file
 * @param[out] img - Empty pointer with allocated memory
 * @return EXIT_FAILURE or EXIT_SUCCESS.
 */
int ppm_load(char* path, ImacImg* img);

/**
 * @brief Save the given ppmImage to a file
 *
 * @param path - full path with filename
 * @param img - PPMImage to save
 * @return EXIT_SUCCESS or EXIT_FAILURE
 */
int ppm_save(char* path, ImacImg* img);

#endif //MINIGIMP_PPM_H
