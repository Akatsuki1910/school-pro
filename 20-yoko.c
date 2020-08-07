#include <stdio.h>

#include <stdlib.h>

int max1(int a, int b) {
  return a > b ? a : b;
}

int main(int argc, char ** argv) {
  char str1[1000], str2[1000];
  int img1[1024][768], img2[1024][768];
  int w1, h1, w2, h2;
  int d1, d2;
  int x, y;
  FILE * fp1, * fp2, * fp3;

  if ((fp1 = fopen(argv[1], "r")) == NULL) {
    perror(argv[1]);
    exit(1);
  }

  if ((fp2 = fopen(argv[2], "r")) == NULL) {
    perror(argv[2]);
    exit(1);
  }

  if ((fp3 = fopen(argv[3], "w")) == NULL) {
    perror(argv[3]);
    exit(1);
  }

  fscanf(fp1, "%s", str1);
  fscanf(fp1, "%d %d", & w1, & h1);
  fscanf(fp1, "%d", & d1);

  fscanf(fp2, "%s", str2);
  fscanf(fp2, "%d %d", & w2, & h2);
  fscanf(fp2, "%d", & d2);

  for (y = 0; y < h1; y++) {
    for (x = 0; x < w1; x++) {
      fscanf(fp1, "%d", & (img1[x][y]));
    }
  }

  for (y = 0; y < h2; y++) {
    for (x = 0; x < w2; x++) {
      fscanf(fp2, "%d", & (img2[x][y]));
    }
  }

  fprintf(fp3, "%s\n%d %d\n%d\n", str1, w1 + w2, max1(h1, h2), d1);
  for (y = 0; y < max1(h1, h2); y++) {
    for (x = 0; x < w1; x++) {
      if (y < h1) {
        fprintf(fp3, "%d ", img1[x][y]);
      } else {
        fprintf(fp3, "%d ", 255);
      }
    }
    for (x = 0; x < w2; x++) {
      if (y < h2) {
        fprintf(fp3, "%d ", img2[x][y]);
      } else {
        fprintf(fp3, "%d ", 255);
      }
    }
    fprintf(fp3, "\n");
  }

  fclose(fp1);
  fclose(fp2);
  fclose(fp3);

  return 0;
}