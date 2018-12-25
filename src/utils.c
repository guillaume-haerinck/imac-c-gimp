#include "utils.h"
#include "string.h"

/* Input & Outputs */
const char* getFilenameExtension(const char *filename) {
    const char *dot = strrchr(filename, '.');
    if(!dot || dot == filename) return "";
    return dot + 1;
}

/* Maths */
long linearMapping(int val, int A, int B, int a, int b) {
    return (val - A)*(b-a)/(B-A) + a;
}
