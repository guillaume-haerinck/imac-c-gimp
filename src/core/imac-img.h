/**
 * @file imac-image.h
 * @brief Abstact software-oriented general type for raster images
 *
 * */

#ifndef MINIGIMP_IMAC_IMG_H
#define MINIGIMP_IMAC_IMG_H

#include <stdbool.h>

// ------------------------------------- STRUCTS & ENUMS

/**
 * @enum img_Channel
 * The channel of the pixels
 *
 */
enum img_Channel {
    red = 0,
    green = 1,
    blue = 2,
    rvb = 3,
};

/**
 * @enum img_Format
 * Image File Format working with this software
 */
enum img_Format {
    P6,
    P5,
    P4,
    P3,
    P2,
    P1
};

/**
 * @struct ImacImg
 * @brief Abstract image format used for modifications
 * @note You need to use img_new or an image loader to init it
 */
typedef struct ImacImg {
    unsigned int width;
    unsigned int height;
    unsigned char* data;
} ImacImg;

// ------------------------------------- CONSTRUCTOR & DESTRUCTOR

/**
 * @brief Constructor for ImacImg
 * @note If you use an image loader, you do not need it
 * @note Don't forget to call img_delete once you are done with the image
 * @note Width and height are READONLY, because the data array has been allocated with it
 *
 * @param img
 * @param width
 * @param height
 * @return EXIT_FAILURE or EXIT_SUCCESS
 */
int img_new(ImacImg* img, unsigned int width, unsigned int height);

/**
 * @brief Destructor for ImacImg
 *
 * @param img
 * @return
 */
int img_delete(ImacImg* img);

// ------------------------------------- GETTERS

/**
 * @brief Get the pixel value for given color.
 * @note 0,0 position is top left corner.
 *
 * @param img
 * @param x
 * @param y
 * @param c - Channel color enum
 * @return Brightness value contained between 0 and 255.
 */
unsigned char img_getPixelChannel(ImacImg* img, unsigned int x, unsigned int y, enum img_Channel c);

/**
 * @brief Get the average pixel value.
 * @note 0,0 position is top left corner.
 *
 * @param img
 * @param x
 * @param y
 * @return Brightness value contained between 0 and 255.
 */
unsigned char img_getPixelGrayscale(ImacImg* img, unsigned int x, unsigned int y);

// ------------------------------------- SETTERS

/**
 * @brief Set all the pixels to white
 * @param img
 */
void img_setToWhite(ImacImg* img);

/**
 * @brief Set the value of a color of a pixel
 * @note 0,0 is top left position
 *
 * @param img
 * @param x
 * @param y
 * @param value
 * @param c - color channel
 */
void img_setPixelChannel(ImacImg* img, unsigned int x, unsigned int y, int value, enum img_Channel c);

/**
 * @brief Set each colors of the pixel with the value
 * @note 0,0 is top left position
 *
 * @param img
 * @param x
 * @param y
 * @param value
 */
void img_setPixelChannels(ImacImg* img, unsigned  int x, unsigned int y, int value);

#endif //MINIGIMP_IMAC_IMG_H
