#include <stdio.h>

int main(int argc, char** argv){

    #pragma omp parallel num_threads(10)

    printf("hello world\n");

    return 0;
}