#include "utils.h"
#include "string.h"

/* Input & Outputs */
const char* getFilenameExtension(const char *filename) {
    const char *dot = strrchr(filename, '.');
    if(!dot || dot == filename) return "";
    return dot + 1;
}

/* Maths */
long linearMapping(int value, int start1, int stop1, int start2, int stop2) {
    return (value - start1) * (stop2 - start2) / (stop1 - start1) + start2;
}
