/**
 * @file utils.h
 * @brief Utility library functions
 */

#ifndef MINIGIMP_UTILS_H
#define MINIGIMP_UTILS_H

// ----------------------------- INPUTS & OUTPUTS

/**
 * @brief Get FileExtension (string after last dot) from string input
 *
 * @param filename
 * @return extension
 */
const char* getFilenameExtension(const char *filename);

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
