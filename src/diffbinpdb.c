/********************************************************************/
/*                                                                  */
/*   Copyright 2011, Jim Phillips and the University of Illinois.   */
/*                                                                  */
/********************************************************************/

#include "largefiles.h"  /* must be first! */

#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

int fd1, fd2;
struct stat statbuf;
int i, j, n1, n2;
off_t s1, s2;
int imax, usetol;
double dmax, dtol;

if ( argc < 3 || argc > 4 ) {
  fprintf(stderr,"Returns the maximum distance between two binary pdb files.\n");
  fprintf(stderr,"Optionally lists all differences greater than [tolerance].\n");
  fprintf(stderr,"Usage: %s <filename1> <filename2> [tolerance]\n",argv[0]);
  exit(-1);
}

if ( ( fd1 = open(argv[1], O_RDONLY) ) < 0 ) {
  fprintf(stderr,"Can't open %s for reading.\n",argv[1]);
  exit(-1);
}

if ( fstat(fd1,&statbuf) < 0 ) {
  fprintf(stderr,"Can't stat %s.\n",argv[1]);
  exit(-1);
}

s1 = statbuf.st_size;

if ( (s1 < 4) || ((s1-4) % 24) ) {
  fprintf(stderr,"Size %ld of %s is not 4 plus a multiple of 24.\n",s1,argv[1]);
  exit(-1);
}

read(fd1,&n1,4);

if ( s1 != 4 + (off_t)n1 * 24 ) {
  fprintf(stderr,"Size %ld of %s is not 4 plus %d times 24.\n",s1,argv[1],n1);
  exit(-1);
}

if ( ( fd2 = open(argv[2], O_RDONLY) ) < 0 ) {
  fprintf(stderr,"Can't open %s for reading.\n",argv[2]);
  exit(-1);
}

if ( fstat(fd2,&statbuf) < 0 ) {
  fprintf(stderr,"Can't stat %s.\n",argv[2]);
  exit(-1);
}

s2 = statbuf.st_size;

if ( (s2 < 4) || ((s2-4) % 24) ) {
  fprintf(stderr,"Size %ld of %s is not 4 plus a multiple of 24.\n",s2,argv[2]);
  exit(-1);
}

read(fd2,&n2,4);

if ( s2 != 4 + (off_t)n2 * 24 ) {
  fprintf(stderr,"Size %ld of %s is not 4 plus %d times 24.\n",s2,argv[2],n2);
  exit(-1);
}

if ( n1 != n2 ) {
  fprintf(stderr,"%s atomcount %d does not match %s atomcount %d..\n",
          argv[1],n1,argv[2],n2);
  exit(-1);
}

usetol = 0;
dtol = 0;

if ( argc == 4 ) {
  if ( sscanf(argv[3],"%lf",&dtol) != 1 ) {
    fprintf(stderr,"Unable to parse tolerance argument %s\n",argv[3]);
    fprintf(stderr,"Usage: %s <filename1> <filename2> [tolerance]\n",argv[0]);
    exit(-1);
  }
  usetol = 1;
  if ( dtol > 0. ) dtol *= dtol;  /* preserve negative values */
}

imax = 0;
dmax = 0;

int bufatoms = 1000000;
if ( bufatoms > n1 ) bufatoms = n1;

double *c1 = malloc(bufatoms*24);
double *c2 = malloc(bufatoms*24);

if ( ! c1 || ! c2 ) {
  fprintf(stderr,"Memory allocation failed.\n");
}

for ( i=0; i<n1; i+=bufatoms ) {
  if ( i + bufatoms > n1 ) bufatoms = n1 - i;
  if ( read(fd1,c1,bufatoms*24) != bufatoms*24 ) {
    fprintf(stderr,"Error reading %s.\n",argv[1]);
    exit(-1);
  }
  if ( read(fd2,c2,bufatoms*24) != bufatoms*24 ) {
    fprintf(stderr,"Error reading %s.\n",argv[2]);
    exit(-1);
  }

  for ( j=0; j<bufatoms; ++j ) {
    double dx = c1[3*j+0] - c2[3*j+0];
    double dy = c1[3*j+1] - c2[3*j+1];
    double dz = c1[3*j+2] - c2[3*j+2];
    double d = dx*dx + dy*dy + dz*dz;
    if ( d > dmax ) { imax = i+j; dmax = d; }
    if ( usetol && d > dtol ) {
      printf("%lg at %d\n",sqrt(d),i+j);
    }
  }
}

dmax = sqrt(dmax);

if ( dtol ) printf("MAX: ");
printf("%lg at %d\n",dmax,imax);

exit(0);

}

