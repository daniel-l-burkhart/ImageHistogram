#ifndef BMPUTILS_H
#define BMPUTILS_H

#include <stdio.h>

#define DATA_OFFSET (0xA)
#define ROWS (0x16)
#define COLUMNS (0x12)
#define NUMBER_OF_COLORS (3)

/**
 * Finds the file offset for the data section of a BMP file
 *
 * @param bmp_file the bitmap file we're searching in
 * @return the data section offset
 */
unsigned int find_bmp_data_offset(FILE* bmp_file);

/**
 * Reads all pixel data from a bitmap file into a byte array.
 *
 * @param bmp_file the bitmap file
 * @return a pointer to a chunk of memory containing the copied pixel byte data
 */
unsigned char* read_pixel_data(FILE* bmp_file);

/**
 * Finds the number of RGB pixels in a bitmap file (i.e., the width*height)
 *
 * @param bmp_file the bitmap file
 * @return the number of pixels in the bitmap
 */
unsigned int find_number_of_pixels(FILE* bmp_file);


#endif
