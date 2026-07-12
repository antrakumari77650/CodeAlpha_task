#include <stdio.h>
void matrix_addition(int a[10][10],int b[10][10], int c, int r)
{
    int sum[10][10];
    printf("\nAddition of matrices:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
}
void matrix_multiplication(int a[10][10], int b[10][10], int r1, int c1, int c2)
{
    int mul[10][10];
    printf("\nMultiplication of matrices:\n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            mul[i][j] = 0;
            for (int k = 0; k < c1; k++)
            {
                mul[i][j] += a[i][k] * b[k][j];
            }
            printf("%d ", mul[i][j]);
        }
        printf("\n");
    }
}
void matrix_transpose(int a[10][10], int r, int c)
{
    printf("\nTranspose of first matrix:\n");

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            printf("%d ", a[j][i]);
        }
        printf("\n");
    }
}
int main()
{
    int a[10][10], b[10][10];
    int r1, c1, r2, c2;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    if (r1 == r2 && c1 == c2)
        matrix_addition(a, b, c1, r1);
    else
        printf("\nAddition is not possible.\n");

    if (c1 == r2)
        matrix_multiplication(a, b, r1, c1, c2);
    else
        printf("\nMultiplication is not possible.\n");

    matrix_transpose(a, r1, c1);

    return 0;
}