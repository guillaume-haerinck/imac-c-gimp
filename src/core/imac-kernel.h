#ifndef MINIGIMP_IMAC_KERNEL_H
#define MINIGIMP_IMAC_KERNEL_H

#include "imac-img.h"

/**
 * @brief Kernel matrix for convolution operation
 * @struct ImacKernel
 * @note Matrix must be a 1 dimensional array, and squared.
 */
typedef struct ImacKernel {
    unsigned int arraySize;
    unsigned int matrixSize;
    int* matrix;
} ImacKernel;

/**
 * @brief Apply convolution matrix on image
 * @param[in] kernel
 * @param[in, out] img
 */
void kernel_applyGrayscale(ImacKernel* kernel, ImacImg* img, ImacImg* outputImg);

/**
 * @brief Apply convolution matrix on image
 * @param[in] kernel
 * @param[in, out] img
 */
void kernel_applyRgb(ImacKernel* kernel, ImacImg* img, ImacImg* outputImg);

/**
 * @brief Get the x, y value of the matrix
 * @note 0,0 is top left
 * @param kernel
 * @param x
 * @param y
 * @return value
 */ 
int kernel_get(ImacKernel* kernel, unsigned int x, unsigned int y);

#endif // MINIGIMP_IMAC_KERNEL_H
