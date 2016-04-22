#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <stdio.h>

#define HIST_SIZE (256)

/**
 * Creates a new histogram with the given number of elements from the given pixel data.
 *
 * @param num_elements the number of elements the histogram should have
 * @param pixel_data the RGB pixel data
 * @return a pointer to the created histogram 
 */
unsigned int* create_histogram(int num_elements, unsigned char* pixel_data);

/**
 * Writes the histogram to an output file.
 *
 * @param histogram the histogram to write
 * @param outfile the output file
 */
void write_histogram(unsigned int* histogram, FILE* outfile);

#endif
