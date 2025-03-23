#include "data_stat.h"

#include <math.h>
#include <stdio.h>

double max(double *data, int n) {
    double max_res = data[0];

    for (int i = 1; i < n; i++) {
        if (max_res < data[i]) {
            max_res = data[i];
        }
    }
    return max_res;
}
double min(double *data, int n) {
    double min_res = data[0];
    for (int i = 1; i < n; i++) {
        if (min_res > data[i]) {
            min_res = data[i];
        }
    }
    return min_res;
}

double mean(double *data, int n) {
    double res = 0;
    for (double *p = data; p - data < n; p++) {
        res += *p;
    }
    return (res / (n));
}

double variance(double *data, int n) {
    double res = 0;
    for (double *p = data; p - data < n; p++) {
        res += pow((*p - mean(data, n)), 2);
    }
    return (res / (n));
}

void sort(double *data, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (data[j] > data[j + 1]) {
                double tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
            }
        }
    }
}