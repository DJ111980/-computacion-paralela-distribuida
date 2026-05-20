#include <mpi.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 1000000

int main(int argc, char** argv) {

    int provided;

    MPI_Init_thread(&argc, &argv,
                    MPI_THREAD_FUNNELED,
                    &provided);

    int rank, size;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int chunk = N / size;

    long long *arr = NULL;

    // Solo el maestro crea el arreglo
    if (rank == 0) {

        arr = (long long*) malloc(N * sizeof(long long));

        for (int i = 0; i < N; i++) {
            arr[i] = i;
        }
    }

    // Iniciar medición paralela
    double t_inicio = MPI_Wtime();

    // Memoria local
    long long *local =
        (long long*) malloc(chunk * sizeof(long long));

    // Repartir datos
    MPI_Scatter(arr,
                chunk,
                MPI_LONG_LONG,
                local,
                chunk,
                MPI_LONG_LONG,
                0,
                MPI_COMM_WORLD);

    // Suma local con OpenMP
    long long suma_local = 0;

    #pragma omp parallel for reduction(+:suma_local)
    for (int i = 0; i < chunk; i++) {

        suma_local += local[i];
    }

    // Reducir resultados
    long long suma_total = 0;

    MPI_Reduce(&suma_local,
               &suma_total,
               1,
               MPI_LONG_LONG,
               MPI_SUM,
               0,
               MPI_COMM_WORLD);

    // Fin tiempo paralelo
    double t_fin = MPI_Wtime();

    // Solo el maestro imprime
    if (rank == 0) {

        printf("Suma total = %lld\n", suma_total);

        printf("Tiempo paralelo: %.6f segundos\n",
               t_fin - t_inicio);

        // -------------------------
        // VERSION SECUENCIAL
        // -------------------------

        long long suma_seq = 0;

        double ts = MPI_Wtime();

        for (int i = 0; i < N; i++) {

            suma_seq += i;
        }

        double te = MPI_Wtime();

        printf("Suma secuencial = %lld\n", suma_seq);

        printf("Tiempo secuencial: %.6f segundos\n",
               te - ts);

        // Speedup
        double speedup =
            (te - ts) / (t_fin - t_inicio);

        printf("Speedup: %.2fx\n", speedup);

        free(arr);
    }

    free(local);

    MPI_Finalize();

    return 0;
}