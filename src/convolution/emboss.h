/**
 * @file emboss.h
 * @brief Convolution based effects for emboss detection
 */
#ifndef MINIGIMP_EMBOSS_H
#define MINIGIMP_EMBOSS_H

#include "../core/imac-img.h"
#include "../core/imac-kernel.h"

void emboss_img(ImacImg* img, ImacImg* outputImg);


#endif // MINIGIMP_EMBOSS_H
