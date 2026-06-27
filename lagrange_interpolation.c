#include <stdio.h>

int main()
{
    int n, i, j;
    int x[20], y[20];
    float xp, yp = 0.0, p;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("\nEnter the data points:\n");
    for(i = 0; i < n; i++)
    {
        printf("x[%d] = ", i);
        scanf("%d", &x[i]);

        printf("y[%d] = ", i);
        scanf("%d", &y[i]);
    }

    printf("\nEnter the value of x where y is to be calculated: ");
    scanf("%f", &xp);

    for(i = 0; i < n; i++)
    {
        p = 1.0;

        for(j = 0; j < n; j++)
        {
            if(i != j)
            {
                p = p * (xp - x[j]) / (float)(x[i] - x[j]);
            }
        }

        yp = yp + p * y[i];
    }

    printf("\nThe interpolated value at x = %.2f is %.3f\n", xp, yp);

    return 0;
}