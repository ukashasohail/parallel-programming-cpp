#include <iostream>
#include <stdlib.h>
#include <omp.h>

// void MatrixMult(double *A, double *B, double *C, int n)
// {
//     int i, j, k;

//     for (i = 0; i < n; i++)
//     {
//         for (j = 0; j < n; j++)
//         {
//             double dot = 0;

//             for (k = 0; k < n; k++)
//             {
//                 dot += A[i][k] * B[k][j];
//             }

//             C[i][j] = dot;
//         }
//     }
// }

// i =0,    j=0,    k=0
//  [5 6]   [1 6]           []
//  [7 5]   [9 1]           []
//

void MatMul_omp(double *A, double *B, double *C, int n)

{

#pragma omp parallel
    {
        int i, j, k;

        #pragma omp for
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                double dot = 0;
                for (k = 0; k < n; k++)
                {
                    dot += A[i][k] * B[k][j];
                    printf("total no of threads: % d", omp_get_num_threads());
                    printf("i=%d j=%d k=%d for threads#%d\n", i, j, k, omp_get_thread_num());
                }
                C[i][j] = dot;
            }
        }
    }
}