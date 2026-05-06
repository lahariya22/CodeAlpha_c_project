#include <stdio.h>

#define MAX 10

void add(int a[MAX][MAX], int b[MAX][MAX], int r, int c) {
    int i, j, sum[MAX][MAX];
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            sum[i][j] = a[i][j] + b[i][j];

    printf("\nMatrix Addition:\n");
    for(i=0;i<r;i++) {
        for(j=0;j<c;j++)
            printf("%d ", sum[i][j]);
        printf("\n");
    }
}

void multiply(int a[MAX][MAX], int b[MAX][MAX], int r1, int c1, int c2) {
    int i, j, k, mul[MAX][MAX] = {0};

    for(i=0;i<r1;i++)
        for(j=0;j<c2;j++)
            for(k=0;k<c1;k++)
                mul[i][j] += a[i][k] * b[k][j];

    printf("\nMatrix Multiplication:\n");
    for(i=0;i<r1;i++) {
        for(j=0;j<c2;j++)
            printf("%d ", mul[i][j]);
        printf("\n");
    }
}

void transpose(int a[MAX][MAX], int r, int c) {
    int i, j;
    printf("\nTranspose:\n");
    for(i=0;i<c;i++) {
        for(j=0;j<r;j++)
            printf("%d ", a[j][i]);
        printf("\n");
    }
}

int main() {
    int a[MAX][MAX], b[MAX][MAX];
    int r, c, i, j;

    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter Matrix A:\n");
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf("%d", &a[i][j]);

    printf("Enter Matrix B:\n");
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf("%d", &b[i][j]);

    add(a, b, r, c);
    multiply(a, b, r, c, c);
    transpose(a, r, c);

    return 0;
}