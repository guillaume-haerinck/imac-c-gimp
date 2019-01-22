#ifndef MINIGIMP_IMAC_KERNEL_H
#define MINIGIMP_IMAC_KERNEL_H

#include "imac-img.h"

/**
 * @brief Kernel matrix for convolution operation
 * @struct ImacKernel
 */
typedef struct ImacKernel {
    unsigned int size;
    int* matrix;
} ImacKernel;

/**
 * @brief Apply convolution matrix on image
 * @param[in] kernel
 * @param[in, out] img
 */
void kernel_apply(ImacKernel* kernel, ImacImg* img);

#endif // MINIGIMP_IMAC_KERNEL_H
