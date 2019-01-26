#include "symmetry.h"

void symmetry_flipV(ImacImg* img) {
	int width = img->width;
	int height = img->height;
	int value1, value2;

	for (int h = 0; h < height; h++) {
		for (int w = 0; w < width/2; w++) {
			for (int channel = red; channel <= blue; channel++) {
				value1 = img_getPixelChannel(img, width-w-1, h, (enum img_Channel) channel);	
				value2 = img_getPixelChannel(img, w, h, (enum img_Channel) channel);	
				img_setPixelChannel(img, w, h, value1, (enum img_Channel) channel);
				img_setPixelChannel(img, width-w-1, h, value2, (enum img_Channel) channel);
			}
		}
	}
}

void symmetry_flipH(ImacImg* img) {
	int width = img->width;
	int height = img->height;
	int value1, value2;

	for (int w = 0; w < width; w++) {
		for (int h = 0; h < height/2; h++) {
			for (int channel = red; channel <= blue; channel++) {
				value1 = img_getPixelChannel(img, w, height-1-h, (enum img_Channel) channel);	
				value2 = img_getPixelChannel(img, w, h, (enum img_Channel) channel);	
				img_setPixelChannel(img, w, h, value1, (enum img_Channel) channel);
				img_setPixelChannel(img, w, height-1-h, value2, (enum img_Channel) channel);
			}
		}
	}
}
