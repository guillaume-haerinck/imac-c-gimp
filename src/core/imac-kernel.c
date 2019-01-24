#include "imac-kernel.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

// ----------------------------------------- PRIVATE FUNCTIONS

static unsigned char _getPixelAvgKernelValue(ImacKernel* kernel, ImacImg* img, unsigned int anchorX, unsigned int anchorY);
static unsigned char _getPixelAvgKernelValue(ImacKernel* kernel, ImacImg* img, unsigned int anchorX, unsigned int anchorY) {
    int avgKernelBrightness = 0;
    int pixelBrightness = 0;
    for (unsigned int matX = 0; matX < kernel->matrixSize; matX++) {
        for (unsigned int matY = 0; matY < kernel->matrixSize; matY++) {
            pixelBrightness = img_getPixelGrayscale(img, anchorX - 1 + matX, anchorY - 1 + matY);
            pixelBrightness = pixelBrightness * kernel_get(kernel, matX, matY);
            avgKernelBrightness += pixelBrightness;
        }
    }
    if (avgKernelBrightness > 255) { avgKernelBrightness = 255; }
    if (avgKernelBrightness < 0) { avgKernelBrightness = 0; }
    return (unsigned char) avgKernelBrightness;
}

static unsigned char _getPixelChannelAvgKernelValue(ImacKernel* kernel, ImacImg* img, unsigned int anchorX, unsigned int anchorY, enum img_Channel channel);
static unsigned char _getPixelChannelAvgKernelValue(ImacKernel* kernel, ImacImg* img, unsigned int anchorX, unsigned int anchorY, enum img_Channel channel) {
    int avgKernelBrightness = 0;
    int pixelBrightness = 0;
    for (unsigned int matX = 0; matX < kernel->matrixSize; matX++) {
        for (unsigned int matY = 0; matY < kernel->matrixSize; matY++) {
            pixelBrightness = img_getPixelChannel(img, anchorX - 1 + matX, anchorY - 1 + matY, channel);
            pixelBrightness = pixelBrightness * kernel_get(kernel, matX, matY);
            avgKernelBrightness += pixelBrightness;
        }
    }
    if (avgKernelBrightness > 255) { avgKernelBrightness = 255; }
    if (avgKernelBrightness < 0) { avgKernelBrightness = 0; }
    return (unsigned char) avgKernelBrightness;
}

// ----------------------------------------- PUBLIC FUNCTIONS

void kernel_applyGrayscale(ImacKernel* kernel, ImacImg* img, ImacImg* outputImg) {
    if (kernel->matrixSize == 3) {
        unsigned char brightness = 0;
        for (unsigned int x = 1; x < img->width - 1; x++) {
            for (unsigned int y = 1; y < img->height - 1; y++) {
                brightness = _getPixelAvgKernelValue(kernel, img, x, y);
                img_setPixelChannels(outputImg, x, y, brightness);
            }
        }
    } else {
        printf("error kernel_apply: Squarred Matrix size must be 3\n");
        DEBUG_BREAK;
    }
}

void kernel_applyRgb(ImacKernel* kernel, ImacImg* img, ImacImg* outputImg) {
    if (kernel->matrixSize == 3) {
        unsigned char brightness = 0;
        for (unsigned int x = 1; x < img->width - 1; x++) {
            for (unsigned int y = 1; y < img->height - 1; y++) {
                brightness = _getPixelChannelAvgKernelValue(kernel, img, x, y, red);
                img_setPixelChannel(outputImg, x, y, brightness, red);

                brightness = _getPixelChannelAvgKernelValue(kernel, img, x, y, green);
                img_setPixelChannel(outputImg, x, y, brightness, green);

                brightness = _getPixelChannelAvgKernelValue(kernel, img, x, y, blue);
                img_setPixelChannel(outputImg, x, y, brightness, blue);
            }
        }
    } else {
        printf("error kernel_apply: Squarred Matrix size must be 3\n");
        DEBUG_BREAK;
    }
}

int kernel_get(ImacKernel* kernel, unsigned int x, unsigned int y) {
    if ((x >= kernel->matrixSize) || (y >= kernel->matrixSize)) {
        printf("Error kernel_get: index superior to matrix size\n");
        DEBUG_BREAK;
        return(EXIT_FAILURE);
    }
    return kernel->matrix[y * kernel->matrixSize + x];
}