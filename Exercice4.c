#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 1000
#define M 1000
#define P 1000

void PrintVector(double *A, int n)
{
    if (A == NULL) {
        printf("Error: Null pointer passed to PrintVector\n");
        return;
    } 
    for (int i = 0; i < n; i++) {
        printf("%d ", (int)A[i]);
    }
    printf("\n");
}

void PrintMatrix(double **A, int n, int m)
{
    if (A == NULL) {
        printf("Error: Null pointer passed to PrintMatrix\n");
        return;
    } 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", (int)A[i][j]);
        }
        printf("\n");
    }
}

double SumofMatrix(double **A, int n, int m)
{
    double sum = 0.0;

    if (A == NULL) {
        printf("Error: Null pointer passed to SumofMatrix\n");
        return 0.0;
    }

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum += A[i][j];
        }
    }

    printf("Sum of all elements: %f\n", sum);
    return sum;
}

double SumofVector(double *A, int n)
{
    double sum = 0.0;

    if (A == NULL) {
        printf("Error: Null pointer passed to SumofVector\n");
        return 0.0;
    }

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < n; i++) {
        sum += A[i];
    }

    printf("Sum of elements: %f\n", sum);
    return sum;
}

double** CreateMatrix(int n, int m) {
    double **matrix = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (double *)malloc(m * sizeof(double));
        for (int j = 0; j < m; j++) {
            matrix[i][j] = 1.0; 
        }
    }
    return matrix;
}

double* CreateVector(int n) {
    double *vector = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        vector[i] = 1.0; 
    }
    return vector;
}

int main() {
    int n = 7, m = 8, p = 17;
    double** matrix = CreateMatrix(n, m);
    double* vector = CreateVector(p);

    printf("_________________________________________________________________\n");
    PrintMatrix(matrix, n, m);
    SumofMatrix(matrix, n, m);

    printf("_________________________________________________________________\n");
    PrintVector(vector, p);
    SumofVector(vector, p);

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(vector);

    return 0;
}




