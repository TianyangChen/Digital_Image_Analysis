#########################################################################
# MAKEFILE - FOR BUILDING PROGRAMS USING THE LIBDIP LIBRARY		#
#									#
# This is a basic Makefile for use in a Linux/Cygwin environment 	#
#									#
# Ver. 2.0.3 (2016-09-13)						#
# (c) 2016 Jeffrey J. Rodriguez. All rights reserved.		 	#
# jjrodrig@email.arizona.edu						#
#									#
# Edit the EXE definition to provide the file extension used for	#
# executable files on your operating system.				#
#									#
# Edit the LIBDIR defintiion to provide the location where libpng.a	#
# and libz.a are located on your system. If they are not pre-		#
# installed on your system, then you will have to download, compile,	#
# and install those libraries yourself.					#
#									#
# To compile and run the example programs, "negative" and "blur",	#
# put the source files and this Makefile in the same directory, and	#
# then do the following:						#
#									#
#	% make								#
#	% ./negative cman.png outfile.png				#
#	% ./blur -n 9 cman.png outfile.png				#
#									#
# If you write a new program myprog that depends on the functions in	#
# the libdip library, then add "myprog" to the PGMS definition		#
# below. Then you can just type "make" to compile it.			#
#									#
# During the debugging phase, use the "-g" option in the CFLAGS		#
# definition below. After debugging is completed, you can enable	#
# compiler optimization by using the "-O2" option in the CFLAGS		#
# definition.								#
#									#
# The indented lines below must begin with TAB character, not spaces.	#

#EXE =				# Linux: no file extension for executables
EXE =		.exe		# Cygwin/MSWindows file extension
LIBDIR =	/usr/local/libpng-1.6.24/lib	# where libpng.a and libz.a are located

CC =            gcc
CCC =           g++
CPPFLAGS =	#-I/dirname	# addl place to look for *.h files
# during debug use the following def to create a global symbol table
CFLAGS =	-g  -Wall	# compiler flags for C programs
# after debug we can optimize by using the following def
#CFLAGS =	-O2 -Wall
CCFLAGS =       $(CFLAGS)	# compiler flags for C++ programs
LDFLAGS =	-L. -L$(LIBDIR)	# where to look for *.a libraries
LDLIBS =        -ldip -lpng -lz -lm  # libraries to link with
PGMS =		cendiff frei
LIBMODULES =	pngOpen pngReadHdr pngWriteHdr pngReadRow pngWriteRow\
		pngClose pngErrorHandler pngWarningHandler matalloc\
		matfree reflect timediff error
LIBOBJECTS =	$(LIBMODULES:%=%.o)
EXECUTABLES =	$(PGMS:%=%$(EXE))

all:		$(PGMS)

$(PGMS):	libdip.a

libdip.a:	$(LIBOBJECTS)
		ar rc libdip.a $(LIBOBJECTS)

clean:
		@ rm -f $(LIBOBJECTS) libdip.a $(EXECUTABLES)
