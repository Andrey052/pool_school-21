#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int n, int max_v, int min_v, double mean_v, double variance_v);

int main()
{
    int n, data[NMAX];
    input(data, &n);
    if (data, n)
    {
        output(data, n);
        output_result(n, max(data, n), min(data, n), mean(data, n), variance(data, n));
    }
    else
    {
        printf("n/a\n");
    }
    return 0;
}

int input(int *a, int *n)
{
    scanf("%d", n);
    if (*n <= NMAX)
    {
        for (int *p = a; p - a < *n; p++)
        {
            scanf("%d", p);
        }
    }
    return 1;
}
void output(int *a, int n)
{
    if (n <= NMAX)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }
    }
}
int max(int *a, int n)
{
    int max_v = a[0];
    if (n <= NMAX)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] > max_v)
            {
                max_v = a[i];
            }
        }
    }
    return max_v;
}
int min(int *a, int n)
{
    int min_v = a[0];
    if (n <= NMAX)
    {
        for (int i = 1; i < n; i++)
        {
            if (a[i] < min_v)
            {
                min_v = a[i];
                printf("%d", min_v);
            }
        }
    }
    return min_v;
}
double mean(int *a, int n)
{
    double mean_v = 0.0;
    for (int i = 0; i < n; i++)
    {
        mean_v += a[i];
    }
    mean_v /= n;
    return mean_v;
}
double variance(int *a, int n)
{
    double variance_v = 0.0;
    double sred = 0.0;
    for (int i = 0; i < n; i++)
    {
        sred += a[i];
    }
    sred /= n;
    for (int i = 0; i < n; i++)
    {
        variance_v += (a[i] - sred) * (a[i] - sred);
    }
    variance_v /= n;
    return variance_v;
}
void output_result(int n, int max_v, int min_v, double mean_v, double variance_v)
{
    if (n <= NMAX)
    {
        printf("\n%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
    }
}