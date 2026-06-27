#include <stdio.h>

int main()
{
    int n, i, j;
    float x[10], y[10], d[10][10], value, ans, p;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter x and y values:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%f%f", &x[i], &y[i]);
        d[i][0] = y[i];
    }

    // Divided Difference Table
    for(j = 1; j < n; j++)
    {
        for(i = 0; i < n - j; i++)
        {
            d[i][j] = (d[i+1][j-1] - d[i][j-1]) /
                      (x[i+j] - x[i]);
        }
    }

   
    printf("\nDivided Difference Table:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n - i; j++)
            printf("%.3f\t", d[i][j]);
        printf("\n");
    }

    printf("\nEnter the value of x: ");
    scanf("%f", &value);

    ans = d[0][0];
    p = 1;

    for(i = 1; i < n; i++)
    {
        p = p * (value - x[i-1]);
        ans = ans + p * d[0][i];
    }

    printf("\nInterpolated value = %.3f", ans);

    return 0;
}