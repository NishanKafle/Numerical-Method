#include <stdio.h>
#include <math.h>

int main()
{
    int n, i;
    float x[20], y[20];
    float X, Y;
    float sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    float A, a, b;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter x and y values:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%f%f", &x[i], &y[i]);

        X = log(x[i]);
        Y = log(y[i]);

        sumX += X;
        sumY += Y;
        sumXY += X * Y;
        sumX2 += X * X;
    }

    b = (n * sumXY - sumX * sumY) /
        (n * sumX2 - sumX * sumX);

    A = (sumY - b * sumX) / n;

    a = exp(A);

    printf("\nValue of a = %.3f", a);
    printf("\nValue of b = %.3f", b);

    printf("\n\nRegression Equation:\n");
    printf("y = %.3f * x^(%.3f)\n", a, b);

    return 0;
}