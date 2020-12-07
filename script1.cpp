#include <iostream>
#include <stdlib.h>
#include <omp.h>

using namespace std;

int main(int argc, char **argv)
{

    int numberOfThreads = atoi(4);

#pragma omp parallel num_threads(numberOfThreads)

    cout << "hello from thread" << omp_get_thread_num() << endl;

    return 0;
}
