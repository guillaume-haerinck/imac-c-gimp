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

void blur_vignette(ImacImg *img, ImacImg* outputImg, int valueMax, int posX, int posY) {
	if (!(valueMax % 2)) valueMax++;
	valueMax /= 2;
	int averagePixelValue, count;
	int currentProgress = 0;
	int const progressBarSize = img->height;
	double powWidth = pow((double)img->width/2, 2.0);
	double powHeight = pow((double)img->height/2, 2.0);
	double hypotenuseMax = sqrt(powWidth + powHeight);
	int radiusSteps = hypotenuseMax / valueMax;
	//printf("powWidth : %f, powHeight = %f, hypotenuseMax = %f, radiusSteps = %d\n", powWidth, powHeight, hypotenuseMax, radiusSteps);
	double SideP1, SideP2;
	if (posX < 0) posX = 0;
	else if (posX > 100) posX = 100;
	if (posY < 0) posY = 0;
	else if (posY > 100) posY = 100;
	double SideO1 = (img->width / 100.) * posX;
	double SideO2 = (img->height / 100.) * posY;
	//printf("SideO1 = %f, SideO2 = %f\n", SideO1, SideO2);
	int radius;
	double beforeRadius;

	for (unsigned int height = 0; height < img->height; height++) {
		for (unsigned int width = 0; width < img->width; width++) {
			SideP1 = SideO1 - width;
			SideP2 = SideO2 - height;
			//printf("SideP1 : %d, SideP2 = %d\n", SideP1, SideP2);
			SideP1 = pow(SideP1, 2.0);
			SideP2 = pow(SideP2, 2.0);
			beforeRadius = sqrt(SideP1 + SideP2) / radiusSteps + 0.5;
			radius = (int) beforeRadius;
			//if (width == 0 && height == 0) printf("Radius = %d, SideP1 = %f, SideP2 = %f\n", radius, SideP1, SideP2);
			//if (radius > 1 ) printf("Radius = %d\n", radius);
			for (int channel = red; channel <= blue; channel++) {
				averagePixelValue = 0;
				count = 0;
				for (int matrixX = (signed int)width - radius; matrixX <= (signed int)width + radius; matrixX++) {
					if (matrixX < 0 || matrixX >= img->width) continue;
					for (int matrixY = (signed int)height - radius; matrixY <= (signed int)height + radius; matrixY++) {
						if (matrixY < 0 || matrixY >= img->height) continue;
						count++;
						averagePixelValue += img_getPixelChannel(img, matrixX, matrixY, (enum img_Channel) channel);
					}
				}
				if (count) averagePixelValue = averagePixelValue / count;
				else averagePixelValue = img_getPixelChannel(img, width, height, (enum img_Channel) channel);
				img_setPixelChannel(outputImg, width, height, (int) averagePixelValue, (enum img_Channel) channel);
			}
		}
		currentProgress++;
		gui_progressBar(currentProgress, progressBarSize);
	}
}

void blur_imgRecursive(ImacImg *img, ImacImg* outputImg, int value) {
	int averagePixelValue, count;
	int currentProgress = 0;
	int const progressBarSize = img->height;
	if (!(value % 2)) value++;
	int radius = _recursiveMatrix(value);
	for (unsigned int height = 0; height < img->height; height++) {
		for (unsigned int width = 0; width < img->width; width++) {
			for (int channel = red; channel <= blue; channel++) {
				averagePixelValue = 0;
				count = 0;
				for (int matrixX = (signed int)width - radius; matrixX <= (signed int)width + radius; matrixX++) {
					if (matrixX < 0 || matrixX >= img->width) continue;
					for (int matrixY = (signed int)height - radius; matrixY <= (signed int)height + radius; matrixY++) {
						if (matrixY < 0 || matrixY >= img->height) continue;
						count++;
						averagePixelValue += img_getPixelChannel(img, matrixX, matrixY, (enum img_Channel) channel);
					}
				}
				if (count) averagePixelValue = averagePixelValue / count;
				else averagePixelValue = img_getPixelChannel(img, width, height, (enum img_Channel) channel);
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
