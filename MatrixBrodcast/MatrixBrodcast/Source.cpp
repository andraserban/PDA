#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stddef.h>
#include "mpi.h"


#define N 4     

void display(char *result, int a[N][N])
{
	int i, j;
	printf("\n\n%s\n", result);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf(" %d", a[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char *argv[])
{
	int i, j, rank, size, sum = 0;
	int a[N][N] = { { 1,2,3,4 },{ 7,9,1,1 },{ 6,9,2,5 },{ 13,33,12,67 } };
	int b[N][N] = { { 6,7,9,0 },{ 9,4,5,9 },{ 4,5,3,13 } ,{ 17,22,5,55 } };
	int c[N][N];

	int a_buffer[N], c_buffer[N];

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	//scatter rows of first matrix to different processes     
	MPI_Scatter(a, N*N / size, MPI_INT, a_buffer, N*N / size, MPI_INT, 0, MPI_COMM_WORLD);


	MPI_Bcast(b, N*N, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Barrier(MPI_COMM_WORLD);

	//perform vector multiplication by all processes
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			sum += a_buffer[j] * b[j][i];
		}
		c_buffer[i] = sum;
		sum = 0;
	}


	MPI_Gather(c_buffer, N*N / size, MPI_INT, c, N*N / size, MPI_INT, 0, MPI_COMM_WORLD);

	/* Time how long the longest process takes to do its work
	Start them at the gate together using barrier synchronization */

	MPI_Barrier(MPI_COMM_WORLD);

	if (rank == 0)
		display("C ", c);

	MPI_Finalize();
	exit(0);
}