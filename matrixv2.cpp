#include <stdio.h>
#include <algorithm>

int main()
{
    const int n = 3;
    double matrix[n][n+1] = {0, 1, 1, 2 , 2, 1, 1, 4, 3, 0, 2, 5};
    double x[n];
    for (int i = 0; i < n - 1; i++)
    {
        int t = i;
        for (int j = i + 1; j < n; j++)
        {
            if (abs(matrix[t][i]) < abs(matrix[j][i])) t = j;
        }
        for (int j = i; j < n + 1; j++)
        {
            std::swap(matrix[i][j], matrix[t][j]);
        }
        for (int j = i + 1; j < n; j++)
        {
            double k = matrix[j][i]/matrix[i][i];
            for (int m = i; m < n + 1; m++)
            {
                matrix[j][m] -= k*matrix[i][m];
            }
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        x[i] = matrix[i][n];
        for (int j = i + 1; j < n; j++)
        {
            x[i] -= matrix[i][j]*x[j];
        }
        x[i] /= matrix[i][i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("x1 = %lf, x2 = %lf, x3 = %lf", x[0], x[1], x[2]);
}
