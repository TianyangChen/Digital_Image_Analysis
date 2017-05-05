/************************************************************************/
/* dip.h - HEADER FILE FOR PROGRAMS USING LIBDIP LIBRARY		*/
/*									*/
/* Ver. 2.0.2 (2016-09-11)						*/
/* (c) 2016 Jeffrey J. Rodriguez. All rights reserved.			*/
/* jjrodrig@email.arizona.edu						*/

/* HEADER FILES */
#include <stdio.h>	/* for fprintf(), etc.		       */
#include <stdlib.h>	/* for malloc(), exit()		       */
#include <string.h>	/* for strcmp()			       */
#include <time.h>	/* for clock_gettime()		       */
#include <math.h>	/* for cos(), etc.		       */
#include "pngio.h"	/* for PNGFILE & PNG fct declarations  */

/* DECLARATIONS OF GLOBAL VARIABLES */
extern const char *progname; /* for error handler */

/* FUNCTION DECLARATIONS */
extern void *matalloc(int32_t nrows, int32_t ncols, int32_t firstRowCoord,
		     int32_t firstColCoord, int elementSize);
extern void matfree(void *ptr);
extern void reflect(void *x, int nrows, int ncols, int amount, int size);
extern double timediff(struct timespec t1, struct timespec t2);
extern void error(const char *msg);
