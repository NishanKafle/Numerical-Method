#include <stdio.h>

int main()
{
    int n, i;
    float x[20], y[20];
    float sx=0, sx2=0, sx3=0, sx4=0;
    float sy=0, sxy=0, sx2y=0;
    float D, D1, D2, D3;
    float a1, a2, a3;

    printf("Enter number of data points: ");
    scanf("%d",&n);

    printf("Enter x and y values:\n");
    for(i=0;i<n;i++)
    {
        scanf("%f%f",&x[i],&y[i]);

        sx += x[i];
        sx2 += x[i]*x[i];
        sx3 += x[i]*x[i]*x[i];
        sx4 += x[i]*x[i]*x[i]*x[i];
        sy += y[i];
        sxy += x[i]*y[i];
        sx2y += x[i]*x[i]*y[i];
    }

    // Determinant of coefficient matrix
    D = n*(sx2*sx4 - sx3*sx3)
      - sx*(sx*sx4 - sx3*sx2)
      + sx2*(sx*sx3 - sx2*sx2);

    // Determinant for a1
    D1 = sy*(sx2*sx4 - sx3*sx3)
       - sx*(sxy*sx4 - sx3*sx2y)
       + sx2*(sxy*sx3 - sx2*sx2y);

    // Determinant for a2
    D2 = n*(sxy*sx4 - sx3*sx2y)
       - sy*(sx*sx4 - sx3*sx2)
       + sx2*(sx*sx2y - sxy*sx2);

    // Determinant for a3
    D3 = n*(sx2*sx2y - sxy*sx3)
       - sx*(sx*sx2y - sxy*sx2)
       + sy*(sx*sx3 - sx2*sx2);

    a1 = D1 / D;
    a2 = D2 / D;
    a3 = D3 / D;

    printf("\nValue of a1 = %.3f", a1);
    printf("\nValue of a2 = %.3f", a2);
    printf("\nValue of a3 = %.3f", a3);

    printf("\n\nQuadratic Regression Equation:\n");
    printf("y = %.3f + %.3fx + %.3fx^2\n", a1, a2, a3);

    return 0;
}