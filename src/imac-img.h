/**
 * @file imac-image.h
 * @brief Abstact software-oriented general type for raster images
 *
 * */

#ifndef MINIGIMP_IMAC_IMG_H
#define MINIGIMP_IMAC_IMG_H

#include <stdbool.h>

/**
 * @enum ImageFormat
 * Image File Format working with this software
 */
enum ImageFormat {
    P6,
    P5,
    P4,
    P3,
    P2,
    P1
};

/**
 * @struct ImacImg
 * Image
 */
typedef struct ImacImg {
    enum ImageFormat format;
    unsigned int width;
    unsigned int height;
    bool transparency;
    unsigned char* data;
} ImacImg;

/**
 * @enum Color
 */
enum Color {
    red = 0,
    green = 1,
    blue = 2,
    alpha = 3,
};

/**
 * Image Pixel
 */
typedef struct Pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char alpha;
} Pixel;

/**
 * @brief Get the pixel value for given color.
 * @note 0,0 position is top left corner.
 *
 * @param img
 * @param x
 * @param y
 * @param c
 * @return Brightness value contained between 0 and 255.
 */
unsigned char getPixelValue(ImacImg* img, int x, int y, enum Color c);

/**
 * @brief Get a pixel from x y position. Debug-only purpose.
 * @note 0, 0 position is top left corner.
 *
 * @param img
 * @param x
 * @param y
 * @return Pixel with red, green, blue color values (and alpha if available)
 */
Pixel getPixel(ImacImg* img, int x, int y);

#endif //MINIGIMP_IMAC_IMG_H
