#include <omp.h>
#include <stdio.h>
#include <stdlib.h>





int main() {

    int N = 10000;
    int a = 0;
    int b = 1;
    double sum = 0.0;
    double h = (b - a) / (double) N;

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < N-1; i++) 
    {
        sum += 4.0 / (1.0 + (i + 0.5)*h * (i + 0.5)*h);
    }

    printf("Approximation of Pi: %f\n", sum * h);

}





