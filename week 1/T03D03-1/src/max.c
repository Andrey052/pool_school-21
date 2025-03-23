#include <stdio.h>

int main()
{
    float a, b;
    scanf("%f %f", &a, &b);
    if (a == (int)a && b == (int)b)
    {
        if (a > b)
        {
            printf("%.f\n", a);
        }
        else if (a < b)
        {
            printf("%.f\n", b);
        }
        else if (a == b)
        {
            printf("%.f\n", a);
        }
    }
    else
    {
        printf("n/a");
    }
}