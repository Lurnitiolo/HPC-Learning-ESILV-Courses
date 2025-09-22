

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define N 1000
#define M 1000
#define P 1000

void mat_vec_seq(double **A, double *v, double *y, int n, int m) {
    for (int i = 0; i < n; i++) {
        y[i] = 0.0;
        for (int j = 0; j < m; j++) {
            y[i] += A[i][j] * v[j];
        }
    }
}

void mat_mat_seq(double **A, double **B, double **C, int n, int m, int p) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0.0;
            for (int k = 0; k < m; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

double dot_prod_seq(double *x, double *y, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += x[i] * y[i];
    }
    return sum;
}

void string_length(const char *str) {
    int i = 0, count = 0;

    // First way: using a loop
    while (str[i] != '\0') {
        i++;
    }

    // Second way: using pointer arithmetic
    const char *p = str;
    while (*p != '\0') {
        count++;
        p++;
    }

    printf("Length using index method: %d\n", i);
    printf("Length using pointer method: %d\n", count);
}

void concat_arrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int i, j;

    // Copy elements of arr1
    for (i = 0; i < size1; i++) {
        result[i] = arr1[i];
    }

    // Copy elements of arr2
    for (j = 0; j < size2; j++) {
        result[size1 + j] = arr2[j];
    }
}

void Exo4(double **A)
{
    
}


int main() {
    
    return 0;
}
