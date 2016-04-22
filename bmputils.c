#include <stdio.h>
#include <stdlib.h>
#include "bmputils.h"

/**
 * Finds the file offset for the data section of a BMP file
 *
 * @param bmp_file the bitmap file we're searching in
 * @return the data section offset
 */
unsigned int find_bmp_data_offset(FILE* bmp_file) {
    
    fseek(bmp_file, DATA_OFFSET, SEEK_SET);
    unsigned int pixelDataOffset = 0;
    fread(&pixelDataOffset, sizeof(unsigned int), 1, bmp_file);
    
    return pixelDataOffset;
}

/**
 * Reads all pixel data from a bitmap file into a byte array.
 *
 * @param bmp_file the bitmap file
 * @return a pointer to a chunk of memory containing the copied pixel byte data
 */
unsigned char* read_pixel_data(FILE* bmp_file) {
    
    int i;
    
    unsigned int numPixels = find_number_of_pixels(bmp_file);
   
    unsigned char* pixelData;
    
    pixelData = (unsigned char*)malloc(sizeof(unsigned char) * numPixels * NUMBER_OF_COLORS);
    
    int pixelDataOffset = find_bmp_data_offset(bmp_file);
    
    fseek(bmp_file, pixelDataOffset, SEEK_SET);
    
    for (i = 0; i<(numPixels*3); i+=3) {

        fread((pixelData+i), 1, 1, bmp_file);
        fread((pixelData+i+1), 1, 1, bmp_file);
        fread((pixelData+i+2), 1, 1, bmp_file);
		
    }
	
    return pixelData;
}

/**
 * Finds the number of RGB pixels in a bitmap file (i.e., the width*height)
 *
 * @param bmp_file the bitmap file
 * @return the number of pixels in the bitmap
 */
unsigned int find_number_of_pixels(FILE* bmp_file) {
    
    fseek(bmp_file, COLUMNS, SEEK_SET);
    unsigned int numOfColumns = 0;
    fread(&numOfColumns, 4, 1, bmp_file);
    
    fseek(bmp_file, ROWS, SEEK_SET);
    unsigned int numOfRows = 0;
    fread(&numOfRows, 4, 1, bmp_file);
    
    unsigned int numOfPixels = (numOfColumns * numOfRows);
    
    return numOfPixels;
}