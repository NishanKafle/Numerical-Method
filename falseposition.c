#include <stdio.h>
#include <math.h>

// Function: f(x) = x^3 - x - 2
float f(float x)
{
    return x*x*x - x - 2;
}

int main()
{
    float a, b, c;
    int i = 1;

    printf("Enter a and b: ");
    scanf("%f %f", &a, &b);

    if(f(a) * f(b) > 0)
    {
        printf("Root is not bracketed.\n");
        return 0;
    }

    printf("\n-----------------------------------------------\n");
    printf("Iter\t a\t\t b\t\t c\t\t f(c)\n");
    printf("-----------------------------------------------\n");

    do
    {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        printf("%d\t %.5f\t %.5f\t %.5f\t %.5f\n",
               i, a, b, c, f(c));

        if(f(a) * f(c) < 0)
            b = c;
        else
            a = c;

        i++;

    } while(fabs(f(c)) > 0.00001);

    printf("\nRoot = %.6f\n", c);

    return 0;
}