#include <stdio.h>
#include <stdlib.h>

int *multiply(int A[], int B[], int m, int n)
{
    int *prod = (int *)malloc((m+n-1) * sizeof(int));

    for (int i = 0; i < m+n-1; i++)
        prod[i] = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            prod[i+j] += A[i] * B[j];
    }
    return prod;
}

void printPoly(int poly[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", poly[i]);
        if (i != 0)
            printf("x^%d", i);
        if (i != n-1)
            printf(" + ");
    }
}

int main()
{
    int A[] = {5, 0, 10, 6};
    int B[] = {1, 2, 4};
    int m = sizeof(A) / sizeof(A[0]);
    int n = sizeof(B) / sizeof(B[0]);
    printf("First polynomial is ");
    printPoly(A, m);
    printf("\nSecond polynomial is ");
    printPoly(B, n);
    int *prod = multiply(A, B, m, n);
    printf("\nProduct polynomial is ");
    printPoly(prod, m+n-1);
    return 0;
}
