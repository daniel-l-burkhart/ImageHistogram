#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "histogram.h"
#include "bmputils.h"

int main(int argc, char *argv[]) {

	FILE* infile;
	FILE* outfile;
	unsigned int* hist;
	unsigned char* pixels;
	unsigned int size;

	// open files for reading and writing
	infile = fopen(argv[1], "rb");
	if (!infile) {
		printf("Could not open file for reading\n");
		exit(1);
	}
    
	outfile = fopen("histogram", "w");

	// calculate the histogram
	pixels = read_pixel_data(infile);
	size = find_number_of_pixels(infile);
	hist = create_histogram(size, pixels);

	// write the output
    write_histogram(hist, outfile);

	// clean up our messes
	free(hist);
	free(pixels);
	fclose(infile);
	fclose(outfile);
    
	return 0;
}


