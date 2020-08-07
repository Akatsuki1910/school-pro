#include <stdio.h>

#include <stdlib.h>

int max1(int a, int b) {
	return a > b ? a : b;
}

int main(int argc, char ** argv) {
	char str1[1000], str2[1000];
	int img[2][1024][768];
	int w[2],h[2];
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
	fscanf(fp1, "%d %d", & w[0], & h[0]);
	fscanf(fp1, "%d", & d1);

	fscanf(fp2, "%s", str2);
	fscanf(fp2, "%d %d", & w[1], & h[1]);
	fscanf(fp2, "%d", & d2);

	for (y = 0; y < h[0]; y++) {
		for (x = 0; x < w[0]; x++) {
			fscanf(fp1, "%d", & (img[0][x][y]));
		}
	}

	for (y = 0; y < h[1]; y++) {
		for (x = 0; x < w[1]; x++) {
			fscanf(fp2, "%d", & (img[1][x][y]));
		}
	}

	fprintf(fp3, "%s\n%d %d\n%d\n", str1, max1(w[0], w[1]), max1(h[0], h[1]), d1);

	int max=0,min=1;
	if(w[0]<w[1]){
		min=0;
		max=1;
	}
	for (y = 0; y < max1(h[0], h[1]); y++) {
		for (x = 0; x < max1(w[0], w[1]); x++) {
			if(x>=(w[max]-w[min])/2 && x<=w[min]+(w[max]-w[min])/2 && y>=(h[max]-h[min])/2 && y<=h[min]+(h[max]-h[min])/2){
				fprintf(fp3, "%d ", img[min][x-(w[max]-w[min])/2-1][y-(h[max]-h[min])/2-1]);
			}else{
				fprintf(fp3, "%d ", img[max][x][y]);
			}
		}
		fprintf(fp3, "\n");
	}

	fclose(fp1);
	fclose(fp2);
	fclose(fp3);

	return 0;
}