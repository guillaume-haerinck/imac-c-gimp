#include "blur.h"
#include <stdio.h>

// ---------------------------------------- PRIVATE MEMBERS
static int blurKernelMatrix[9] = {
	1, 2, 1,
	2, 4, 2,
	1, 2, 1
};

// ---------------------------------------- PRIVATE FUNCTIONS

/**
 * @brief Calculte the matrix shift value (recursive function)
 * @note Private function
 */
static int _recursiveMatrix(int n);
int _recursiveMatrix(int n) {
	if (n==1) return 0;
	return _recursiveMatrix(n-2) + 1;
}

// ----------------------------------------- PUBLIC FUNCTIONS

void blur_imgRecursive(ImacImg *img, ImacImg* outputImg, int value) {
	int averagePixelValue, count;
	int currentProgress = 0;
	int const progressBarSize = img->height * img->width * 3;
	if (!(value % 2)) value += 1;
	int radius = _recursiveMatrix(value);
	for (unsigned int height = 0; height < img->height; height++) {
		for (unsigned int width = 0; width < img->width; width++) {
			for (int channel = red; channel <= blue; channel++) {
				averagePixelValue = 0;
				count = 0;
				for (int matrixX = width - radius; matrixX <= width + radius; matrixX++) {
					if (matrixX < 0 || matrixX >= img->width) continue;
					for (int matrixY = height - radius; matrixY <= height + radius; matrixY++) {
						if (matrixY < 0 || matrixY >= img->height) continue;
						count++;
						averagePixelValue += img_getPixelChannel(img, matrixX, matrixY, (enum img_Channel) channel);
					}
				}
				if (count == 0) { count = 1; }
				averagePixelValue = averagePixelValue / count;
				img_setPixelChannel(outputImg, width, height, (int) averagePixelValue, (enum img_Channel) channel);
			}
		}
		currentProgress++;
		gui_progressBar(currentProgress, progressBarSize);
	}
}

// ---------------------- PUBLIC FUNCTIONS
void blur_imgKernel(ImacImg* img, ImacImg* outputImg) {
    ImacKernel blur;
    blur.matrixSize = 3;
    blur.arraySize = 9;
    blur.matrix = blurKernelMatrix;
    kernel_applyRgb(&blur, img, outputImg, 1.0f / 16.0f);
}
