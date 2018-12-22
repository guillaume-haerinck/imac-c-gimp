#ifndef MINIGIMP_PPM_H
#define MINIGIMP_PPM_H

typedef struct PPMImage {
    char format[3];
    int width;
    int height;
    int maxColor;
    char* data;
} PPMImage;

int ppm_load(char* path, PPMImage* img);

#endif //MINIGIMP_PPM_H
