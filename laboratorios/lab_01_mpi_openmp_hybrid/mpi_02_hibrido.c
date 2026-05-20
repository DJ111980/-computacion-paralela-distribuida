#include <mpi.h>
#include <omp.h>
#include <stdio.h>

int main(int argc, char** argv) {

    // Inicializar MPI con soporte para hilos
    int provided;

    MPI_Init_thread(&argc, &argv,
                    MPI_THREAD_FUNNELED,
                    &provided);

    int rank, size;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Región paralela OpenMP
    #pragma omp parallel num_threads(4)
    {

        int tid = omp_get_thread_num();

        int nthreads = omp_get_num_threads();

        printf("Proceso MPI %d | Hilo OpenMP %d de %d\n",
               rank, tid, nthreads);
    }

    // Solo el proceso maestro imprime esto
    if (rank == 0) {

        printf("\nTotal unidades: %d x 4 = %d\n",
               size, size * 4);
    }

    MPI_Finalize();

    return 0;
}