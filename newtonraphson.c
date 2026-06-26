#include <stdio.h>
#include <math.h>

// f(x) = x^2 - 4
float f(float x)
{
    return x*x - 4;
}

// f'(x) = 2x
float df(float x)
{
    return 2*x;
}

int main()
{
    float x0, x1;
    int i = 1;
    float e = 0.00001;

    printf("Enter initial guess x0: ");
    scanf("%f", &x0);

    printf("\n---------------------------------------------\n");
    printf("Iter\t x0\t\t x1\t\t f(x1)\n");
    printf("---------------------------------------------\n");

    do
    {
        x1 = x0 - (f(x0) / df(x0));

        printf("%d\t %.6f\t %.6f\t %.6f\n",
               i, x0, x1, f(x1));

        if(fabs(f(x1)) <= e)
            break;

        x0 = x1;
        i++;

    } while(1);

    printf("\nRoot = %.6f\n", x1);

    return 0;
}