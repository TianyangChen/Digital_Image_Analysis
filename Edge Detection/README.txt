This package includes the following files:
	cendiff.c
	dip.h
	error.c
	frei.c
	matalloc.c
	matfree.c
	png.h
	pngClose.c
	pngconf.h	
	pngErrorHandler.c
	pngio.h
	pnglibconf.h
	pngOpen.c
	pngReadHdr.c
	pngReadRow.c
	pngWarningHandler.c
	pngWriteHdr.c
	pngWriteRow.c	
	reflect.c
	timediff.c

Edit the EXE & LIBDIR definitions in Makefile to match your operating system.
Then build the library and executables by typing "make".

To implement the Central difference operator and Frei-Chen operator, 
type the flowing command lines:

	./cendiff parth.png edgecendiff.png
	./frei parth.png edgefrei.png

The program will display the total amount of edge pixels and the maximum magnitude-squared gradient value.

The maximum magnitude-squared gradient value for these two operators:
Central-difference : 16865.000000
Frei-Chen : 11515.434570 
