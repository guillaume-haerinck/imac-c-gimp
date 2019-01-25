#include "emboss.h"

// ---------------------- PRIVATE MEMBERS
static int embossKernelMatrix[9] = {
    -1, -1,  0,
    -1,  0,  1,
     0,  1,  1
};

// ---------------------- PUBLIC FUNCTIONS
void emboss_img(ImacImg* img, ImacImg* outputImg) {
    ImacKernel emboss;
    emboss.matrixSize = 3;
    emboss.arraySize = 9;
    emboss.matrix = embossKernelMatrix;
    kernel_applyRgb(&emboss, img, outputImg, 1.0f);
}
