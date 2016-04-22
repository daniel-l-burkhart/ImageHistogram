CC=gcc
CCFLAGS= -c -Wall

imghist: imghist.o histogram.o bmputils.o
	$(CC) -o imghist imghist.o histogram.o bmputils.o

imghist.o: imghist.c histogram.c histogram.h bmputils.c bmputils.h
	$(CC) $(CCFLAGS) imghist.c

histogram.o: histogram.c histogram.h bmputils.c bmputils.h
	$(CC) $(CCFLAGS) histogram.c

bmputils.o: bmputils.c bmputils.h
	$(CC) $(CCFLAGS) bmputils.c

clean:
	rm -f *.o imghist

test: imghist
	./imghist BlkRGB_colortest.bmp
	diff --brief histogram BlkRGB_colortest.txt
	./imghist lolcat.bmp
	diff --brief histogram lolcat.txt
	./imghist nyancat.bmp
	diff --brief histogram nyancat.txt
	./imghist lathe.bmp
	diff --brief histogram lathe.txt
	rm histogram
