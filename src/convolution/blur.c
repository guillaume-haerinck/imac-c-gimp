#include "blur.h"
#include <stdio.h>

// ---------------------------------------- Private functions

/**
 * @brief Calculte the matrix shift value (recursive function)
 * @note Private function
 */
static int _recursiveMatrix(int n);
int _recursiveMatrix(int n) {
	//printf("Value in recur = %d\n", n);
	if (n==1) return 0;
	return _recursiveMatrix(n-2) + 1;
}

// ----------------------------------------- Public functions

// TODO use kernel_apply() and declare convolution matrix + FIXME on windows

void blur_img(ImacImg *img, ImacImg* outputImg, int value) {
	int averagePixelValue, count;
	if (!(value%2)) value+=1;
	//printf("Value  = %d\n", value);
	int radius = _recursiveMatrix(value);
	//printf("value %d\n", value);
	//printf("recursive = %d\n", _recursiveMatrix(value));
	for (int height = 0; height < img->height; height++) {
		for (int width = 0; width < img->width; width++) {
			for (int channel = red; channel <= blue; channel++) {
				averagePixelValue = 0;
				count = 0;
				//if (width==0&&height==0) printf("\nChannel %d, value %d\n", channel, averagePixelValue);
				for (int matrixX= width-radius; matrixX <= width+radius; matrixX++) {
					if (matrixX < 0 || matrixX > img->width) continue;
					for (int matrixY = height-radius; matrixY <= height+radius; matrixY++) {
						if (matrixY < 0 || matrixY > img->height) continue;
						count++;
						averagePixelValue += img_getPixelChannel(img, matrixX, matrixY, channel);
						//if (width == 0 && height == 0){
						//	printf("averagePixelValueue taken from : %d %d, current total %d\n", matrixX, matrixY, averagePixelValue);
						//	printf("Value of channel at this point : %d\n", img_getPixelChannel(img, matrixX, matrixY, channel));
						//}
					}
				}
				//if (width == 0 && height == 0){
				//	printf("PixelValue total %d count total %d\n", averagePixelValue, count);
				//}
				averagePixelValue = averagePixelValue/count;
				//if (width == 0 && height == 0){
				//	printf("PixelValue is %d\n", averagePixelValue);
				//}
				//averagePixelValue = (img_getPixelChannel(img, width, height, channel))/9 + 
				img_setPixelChannel(outputImg, width, height, (unsigned char) averagePixelValue, channel);
			}
		}
	}
}
