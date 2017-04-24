
#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

#define NoOfElements 5
int outputMatrix[NoOfElements][NoOfElements];
int processes;
int rank;
int index, index1, index2;
	int main(int argc, char *argv[])
{
	int inputMatrix[NoOfElements][NoOfElements] = {
		{ 1,   1, -1, 10 ,-5 },
		{ 12,   0,  3, -1 ,-1 },
		{ -1,   -2,  5,  1 , 4 },
		{ 3,  -1,  1,  6 ,-1 },
		{ -1,  -9,  12, -1 , 0 }
	};

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &processes);

	for ( index = 0; index < NoOfElements; index++)
	{
		for (index1 = rank; index1 < NoOfElements; index1 = index1 + processes)
		{
			for (index2 = 0; index2 < NoOfElements; index2++)
			{
				if (inputMatrix[index1][index2] > inputMatrix[index1][index] + inputMatrix[index][index2])

					inputMatrix[index1][index2] = inputMatrix[index1][index] + inputMatrix[index][index2];
			}
		}
		//all getter 
		MPI_Reduce(inputMatrix, outputMatrix, NoOfElements*NoOfElements, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);

		if (rank == 0) {
			//print matrix 
			for (int i = 0; i < NoOfElements; i++)
				for (int j = 0; j < NoOfElements; j++)
					inputMatrix[i][j] = outputMatrix[i][j];
			MPI_Bcast(inputMatrix, NoOfElements*NoOfElements, MPI_INT, 0, MPI_COMM_WORLD);
		}
		// fara barrier daca avem all getter
		MPI_Barrier(MPI_COMM_WORLD);
	}

	MPI_Finalize();
}
