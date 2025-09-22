#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>


#define N 1000
#define M 1000
#define P 1000


int main(int argc, char *argv[]) {
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    printf("Hello from rank %d of %d\n", rank+1, size);

    MPI_Finalize();
    return 0;
}





