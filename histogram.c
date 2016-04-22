#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "histogram.h"

/**
 * Creates a new histogram with the given number of elements from the given pixel data.
 *
 * @param num_elements the number of elements the histogram should have
 * @param pixel_data the RGB pixel data
 * @return a pointer to the created histogram
 */
unsigned int* create_histogram(int num_elements, unsigned char* pixel_data) {
    
    unsigned int grayArray[num_elements];
    
    int i;
    int count = 0;
	
    for (i=0; i<(num_elements*3); i+=3) {
        
        unsigned int blue = *(pixel_data+i);
        unsigned int green = *(pixel_data+i+1);
        unsigned int red = *(pixel_data+i+2);
        
        unsigned int gray = (red*3)/10 + (green*59)/100 + (blue*11)/100;
        
        grayArray[count] = gray;
        count++;
    }
    
    unsigned int* histogramOut;
    
    histogramOut = (unsigned int*)malloc(HIST_SIZE*sizeof(unsigned int));
    
	int j;
    for (j = 0; i<HIST_SIZE; i++) {
        *(histogramOut+j) = 0;
    }
    
	int histCount;
    for (histCount=0; histCount<num_elements; histCount++) {
        
        unsigned int value = grayArray[histCount];
		
        *(histogramOut+value) +=1;
    }
    
	return histogramOut;
	
}

/**
 * Writes the histogram to an output file.
 *
 * @param histogram the histogram to write
 * @param outfile the output file
 */
void write_histogram(unsigned int* histogram, FILE* outfile) {

	int writer;
    
    for (writer = 0; writer<HIST_SIZE; writer++) {
       
        fprintf (outfile, "%u,%u\n", writer, *(histogram+writer));
    }
   
    
}
