/**
 * @file utils.h
 * @brief Utility library functions
 */

#ifndef MINIGIMP_UTILS_H
#define MINIGIMP_UTILS_H

// ----------------------------- PRINT FANCY LOGO IN TERMINAL
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_GREEN "\x1b[32m"

void print_logo();

// ----------------------------- PROGRESS BAR FOR SLOW EFFECTS
#include <stdio.h>

void progress_bar(int currentProgress, int total); 

// ----------------------------- DEBUG
#include <signal.h>

#ifdef _MSC_VER
#define DEBUG_BREAK __debugbreak()
#else
    #ifndef SIGTRAP
    #define SIGTRAP 5
    #endif
#define DEBUG_BREAK raise(SIGTRAP)
#endif

// ----------------------------- INPUTS & OUTPUTS

/**
 * @brief Get FileExtension (string after last dot) from string input
 *
 * @param filename
 * @return extension
 */
const char* getFilenameExtension(const char* filename);

/**
 * @brief Get directory path without filename
 * @note Will change the pointer passed
 *
 * @param path
 * @return dirname - no ending '/'
 */
char* getDirname(char* path);

// ----------------------------- MATHS
/**
 * @brief Map value from interval1 to interval2
 *
 * @param value
 * @param start1
 * @param stop1
 * @param start2
 * @param stop2
 * @return mappedValue
 */
long linearMapping(int value, int start1, int stop1, int start2, int stop2);

#endif //MINIGIMP_UTILS_H
