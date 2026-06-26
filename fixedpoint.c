#include <stdio.h>
#include <math.h>

\
float g(float x)
{
    return (x + 2/x) / 2;
}

int main()
{
    float x0, x1, error;
    int i = 1;
    float e = 0.00001;

    printf("Enter initial guess x0: ");
    scanf("%f", &x0);

    printf("\n---------------------------------------------\n");
    printf("Iter\t x0\t\t x1\t\t Error\n");
    printf("---------------------------------------------\n");

    do
    {
        x1 = g(x0);
        error = fabs(x1 - x0);

        printf("%d\t %.6f\t %.6f\t %.6f\n",
               i, x0, x1, error);

        if(error <= e)
            break;

        x0 = x1;
        i++;

    } while(1);

    printf("\n---------------------------------------------\n");
    printf("Root = %.6f\n", x1);

    return 0;
}