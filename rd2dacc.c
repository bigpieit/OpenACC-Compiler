#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void matprint(double **x, int nrow, int ncol) {
        for (int i = 0; i < nrow; i++ ) {
                for (int j = 0; j < ncol; j++) {
                        printf("%lf ", x[i][j]);
                }
                printf("\n");
        }
}

/*  rdist compute the Euclidean distance between i and j row in matrix x  */
/*                   save the result to dist[i][j]                        */
void rdist(double **x, double **dist, int row, int col) {
	int nrow = row, ncol = col;
	double sum, diff;
	int len = nrow * ncol;
	int distlen = nrow * nrow;
	#pragma acc data copy(x[0:nrow][0:ncol], dist[0:nrow][0:nrow], nrow, ncol)
	#pragma acc kernels
	{
	for (int i = 0; i < nrow; i++) {
		for (int j = 0; j < nrow; j++) {
			sum = 0.0;
			for (int k = 0; k < ncol; k++) {
				diff = x[i][k] - x[j][k];
				sum += pow(diff, 2);
			}
			sum = pow(sum, 0.5);
			dist[i][j] = sum;
		}
	}
	}
}

int main() {
	int nrow = 3, ncol = 4;
	/*          init matrix x dim(x) = (3,4)          */
	double **restrict x;
        x = (double **)malloc(nrow * sizeof(double *));
        for (int i = 0; i< nrow; i++)
                x[i] = (double *)malloc(ncol * sizeof(double));

	for (int i = 0; i < nrow; i++) {
		for (int j = 0; j < ncol; j++) {
			x[i][j] = i*ncol + j;
		}
	}

        /*        init matrix dist  dim(dist) = (3,3)     */
        double **restrict dist;
        dist = (double **)malloc(nrow * sizeof(double *));
        for (int i = 0; i< nrow; i++)
                dist[i] = (double *)malloc(nrow * sizeof(double));

        for (int i = 0; i < nrow; i++) {
                for (int j = 0; j < ncol; j++) {
                        dist[i][j] = 0.0;
                }
        }

	printf("Matrix x is:\n");
	matprint(x, nrow, ncol);
	printf("\nInitial matrix dist is:\n");
	matprint(dist, nrow, nrow);

	rdist(x, dist, nrow, ncol);

	printf("\nFinal matrix dist is:\n");
	matprint(dist, nrow, nrow);
	return 0;
}
