#include <stdio.h>

int main()
{
    int n, i, j;
    float x[10], y[10], diff[10][10];
    float value, h, u, ans, term, fact;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter x and y values:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%f%f", &x[i], &y[i]);
        diff[i][0] = y[i];
    }

    // Backward Difference Table
    for(j = 1; j < n; j++)
    {
        for(i = n - 1; i >= j; i--)
        {
            diff[i][j] = diff[i][j - 1] - diff[i - 1][j - 1];
        }
    }

    // Print Backward Difference Table
    printf("\nBackward Difference Table:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j <= i; j++)
        {
            printf("%.3f\t", diff[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter the value of x: ");
    scanf("%f", &value);

    h = x[1] - x[0];
    u = (value - x[n - 1]) / h;

    ans = diff[n - 1][0];
    term = 1;
    fact = 1;

    for(i = 1; i < n; i++)
    {
        term = term * (u + (i - 1));
        fact = fact * i;
        ans = ans + (term * diff[n - 1][i]) / fact;
    }

    printf("\nInterpolated value = %.3f\n", ans);

    return 0;
}