#include <stdio.h>

int main()
{
    float a, b;
    int prov = scanf("%f %f", &a, &b);
    if (prov == 2 && a == (int)a && b == (int)b)
    {
        int c, d, e, x;
        c = a + b;
        d = a - b;
        e = a * b;
        if (b != 0)
        {
            x = a / b;
            printf("%d %d %d %d", c, d, e, x);
        }
        else
        {
            printf("%d %d %d n/a\n", c, d, e);
        }
    }
    else
    {
        printf("n/a\n");
    }
    return 0;
}