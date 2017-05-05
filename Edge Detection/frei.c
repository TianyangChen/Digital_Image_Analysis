/************************************************************************/
/* frei - Implement Frei-Chen operator to detect edge                   */
/************************************************************************/
/* Usage:  ./frei infile outfile                                        */
/* Infile and outfile are grayscale PNG images.                         */
/*                                                                      */
/*      [  -1      0     1   ]     [1    sqrt(2)   1]                   */
/* h1 = [-sqrt(2)  0  sqrt(2)]  h2=[0      0       0]                   */
/*      [  -1      0     1   ]     [-1  -sqrt(2)  -1]                   */
/*                                                                      */
/* Ver. 1.0.0 (2016-09-26)                                              */
/* (c) 2016 Tianyang Chen. All rights reserved.                         */
/* tianyangchen@email.arizona.edu                                       */
/************************************************************************/

#include "dip.h"

int main(int argc, char **argv)
{
  PNGFILE *fpx, *fpy;
  uint8_t **x, **y,threshold=51;
  int badswitch=0;
  int32_t R=1, nrows, ncols, r, c, pixsum=0;
  float h1,h2,h,sq2,sf,hmax=0;
 

  /* PARSE THE COMMAND LINE */
  progname = argv[0];
  while(--argc > 0 && **(argv+1) == '-')
    switch((*++argv)[1])
    {
    default:
      badswitch = 1;
    }
  if(badswitch || argc != 2)
  {
    fprintf(stderr, "Usage: %s infile outfile\n", progname);
    exit(1);
  }

  /* OPEN FILES */
  if((fpx = pngOpen(*++argv, "r")) == NULL)
    error("can't open infile");
  if((fpy = pngOpen(*++argv, "w")) == NULL)
    error("can't open outfile");

  /* READ INFILE HEADER */
  pngReadHdr(fpx, &nrows, &ncols);
  
  /* WRITE OUTFILE HEADER */
  pngWriteHdr(fpy, nrows, ncols);

  /* ALLOCATE ARRAYS */
  /* The x array is extended by R pixels on all four sides. */
  /* The first element of the array is x[-R][-R]. */
  /* The first actual pixel of the image will be stored at x[0][0]. */
  x = (uint8_t **)matalloc(nrows+2*R, ncols+2*R,
    -R, -R, sizeof(uint8_t));/* The operator is a 3*3 matrix, So R=1. */
  y = (uint8_t **)matalloc(nrows, ncols, 0, 0, sizeof(uint8_t));
  if(x == NULL || y == NULL) error("can't allocate memory");

  /* READ THE IMAGE */
  for(r = 0; r < nrows; r++)
    pngReadRow(fpx, x[r]);

  /* REFLECT THE IMAGE ACROSS ITS BORDERS */
  reflect(x, nrows, ncols, R, sizeof(uint8_t));

  /* Implement Frei-Chen operator */
  sq2 = sqrt(2); //define sqrt(2);
  sf = 1/(2*(2+sq2)); //define scaling factor
    for (r = 0; r < nrows; r++)
  {
    for (c = 0; c < ncols; c++)
    {
      h1 = ( x[r-1][c+1] + sq2*x[r][c+1] + x[r+1][c+1] )-( x[r-1][c-1] + sq2*x[r][c-1] + x[r+1][c-1] );
      h2 = ( x[r-1][c-1] + sq2*x[r-1][c] + x[r-1][c+1] )-( x[r+1][c-1] + sq2*x[r+1][c] + x[r+1][c+1] );
      h = sf*sf*(h1*h1 + h2*h2); //compute the magnitude-squared gradient value
      if (h > hmax)
      {
        hmax = h; //save the maximum magnitude-squared gradient value
      }
      if (h >= (threshold*threshold) )
      {
        y[r][c]=255; // set edge pixel to white
        pixsum++; //count the number of edge pixels
      }else{
        y[r][c]=0; // set background pixel to black
      }
    }
  }

  /* WRITE THE IMAGE */
  for(r = 0; r < nrows; r++)
    pngWriteRow(fpy, y[r]);

  /* CLOSE */
  pngClose(fpx);
  pngClose(fpy);
  printf("edge has been extracted successfully!\n");
  printf("Total amount of edge pixels: %d\n",pixsum ); //display total amount of edge pixels
  printf("Maximum Magnitude-squared gradient: %f\n",hmax ); //display Maximum Magnitude-squared gradient value
  exit(0);
  
}

