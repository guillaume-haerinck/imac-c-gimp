/**
 * @file ppm.h
 * @brief PPM image loader
 *
 * */

#ifndef MINIGIMP_PPM_H
#define MINIGIMP_PPM_H

/**
 * PPMImage
 */
typedef struct PPMImage {
    char format[3];
    int width;
    int height;
    int maxColor;
    unsigned char* data;
} PPMImage;

/**
 * Pixel
 */
typedef struct Pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

/**
 * Pixel Color
 */
enum Color {
    red = 0,
    green = 1,
    blue = 2,
};

/**
 * @brief Load a ppm image file and init the PPMImage pointer with it.
 * @note You must free the img data yourself.
 *
 * @param <path> Relative path to the ppm file
 * @param[out] <img> Empty pointer with allocated memory
 * @return EXIT_FAILURE if error, EXIT_SUCCESS otherwise.
 */
int ppm_load(char* path, PPMImage* img);

/**
 * @brief Get the pixel brightness value for given color.
 * @note 0,0 position is top left corner.
 *
 * @param <img>
 * @param <x>
 * @param <y>
 * @param <c>
 * @return Brightness value contained between 0 and 255.
 */
unsigned char ppm_getPixelColor(PPMImage* img, int x, int y, enum Color c);

/**
 * @brief Get a pixel from x y position.
 * @note 0, 0 position is top left corner.
 *
 * @param img
 * @param x
 * @param y
 * @return Pixel with red, green, blue color values
 */
Pixel ppm_getPixel(PPMImage* img, int x, int y);

#endif //MINIGIMP_PPM_H
