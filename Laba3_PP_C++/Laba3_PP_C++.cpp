// Laba3_PP_C++.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

//function sleep
#include <Windows.h>

#include "mpi.h"
#include <stdio.h>

using namespace std;

void swapA()
{

}

//algorithm odd-even sort
void OddEvenSort(double A[], int n)
{
	for (int i = 1; i < n; i++)
	{
		if (i % 2 == 1)
		{   
			// odd iteration
			for (int j = 0; j < n / 2 - 2; j++)
				swapA(A[2 * j + 1], A[2 * j + 2]);

			//compare the last pair at odd "n"
			if (n % 2 == 1)
				swapA(A[n - 2], A[n - 1]);
		}
		else
		{
			// even iteration
			for (int j = 1; j < n / 2 - 1; j++)
				swapA(A[2 * j], A[2 * j + 1]);
		}
	}
}

int main(int argc, char **argv)
{
	int rank, size;
	MPI_Init(&argc, &argv);
	MPI_Comm comm = MPI_COMM_WORLD;
	MPI_Comm_rank(comm, &rank);
	MPI_Comm_size(comm, &size);

	//count of values
	const int N = 16;

	//input blockly sorting array
	int A[N] = {13, 55, 59, 88, 29, 43, 71, 85, 2, 18, 40, 75, 4, 14, 22, 43};

	//blocks of data (N / p) = 4
	int piece = N / size;

	//for recieve part of block of array A (size of blocks multipy on 2 for part of blocks on other processes at swap)
	int* B = new int[piece*2];

	//0-process send pieces of blocks "A" all processes (A separate on equal pieces between all processes)
	MPI_Scatter(A, piece, MPI_INT, B, piece, MPI_INT, 0, comm);

	//swap between the 2 processes
	

	//merging and sorting


	//left part - 1 process, right part - 2 process


	MPI_Finalize();
	return 0;
}

//void OddEvenSort(double A[], int n)
//{
//	for (int i = 1; i < n; i++)
//	{
//		if (i % 2 == 1)
//		{
//			// odd iteration
//			for (int j = 0; j < n / 2 - 2; j++)
//				swapA(A[2 * j + 1], A[2 * j + 2]);
//
//			//compare the last pair at odd "n"
//			if (n % 2 == 1)
//				swapA(A[n - 2], A[n - 1]);
//		}
//		else
//		{
//			// even iteration
//			for (int j = 1; j < n / 2 - 1; j++)
//				swapA(A[2 * j], A[2 * j + 1]);
//		}
//	}
//}