#include <mpi.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    int rank, size;
    int number;

    MPI_Init(&argc, &argv);                 
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);  
    MPI_Comm_size(MPI_COMM_WORLD, &size);   

    if (size < 2) {
        printf("This program requires at least 2 processes.\n");
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    if (rank == 0) {
        number = 5; 
        MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    } else if (rank == 1) {
        MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process 1 received %d\n", number);
        printf("Process 1 multiplied value = %d\n", number * 2);
    }

    MPI_Finalize();
    return 0;
}
