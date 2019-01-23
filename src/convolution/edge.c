#include "edge.h"

// ---------------------- PRIVATE MEMBERS
static int edgeKernelMatrix[9] = {
    -1, -1, -1,
    -1,  8, -1,
    -1, -1, -1
};

// ---------------------- PUBLIC FUNCTIONS
void edge_img(ImacImg* img, ImacImg* outputImg) {
    ImacKernel edge;
    edge.matrixSize = 3;
    edge.arraySize = 9;
    edge.matrix = edgeKernelMatrix;
    kernel_applyGrayscale(&edge, img, outputImg);
}
