#include <stdio.h>
#include <math.h>

int main()
{
    int n, i;
    float x[20], y[20];
    float sumx = 0, sumY = 0, sumxY = 0, sumx2 = 0;
    float A, a, b, Y;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter x and y values:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%f %f", &x[i], &y[i]);

        Y = log(y[i]);      // Natural Log

        sumx += x[i];
        sumY += Y;
        sumxY += x[i] * Y;
        sumx2 += x[i] * x[i];
    }

    b = (n * sumxY - sumx * sumY) /
        (n * sumx2 - sumx * sumx);

    A = (sumY - b * sumx) / n;

    a = exp(A);

    printf("\nValue of a = %.3f", a);
    printf("\nValue of b = %.3f", b);

    printf("\n\nRegression Equation:\n");
    printf("y = %.3f * e^(%.3fx)\n", a, b);

    return 0;
}