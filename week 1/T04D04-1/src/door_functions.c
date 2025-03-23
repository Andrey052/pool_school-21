#include <math.h>
#include <stdio.h>

double Agnesi(double x);
double Bernoulli(double x);
double hyperbola(double x);

int main() {
  double Ag, Be, he;
  double x = (-1) * M_PI;
  double div = (2 * M_PI / 41);
  for (int i = 0; i < 42; i++) {

    Ag = Agnesi(x);
    Be = Bernoulli(x);
    he = hyperbola(x);
    printf("%.7lf |", x);
    if (Ag != Ag) {
      printf(" - |");

      printf(" %.7lf |", Ag);
    }
    if (Be != Be) {
      printf(" - |");
    } else {
      printf(" %.7lf |", Be);
    }
    if (he != he) {
      printf(" - |");
    } else {
      printf(" %.7lf\n", he);
    }
    x += div;
  }
}

double Agnesi(double x) { return (1 / (1 + pow(x, 2))); }

double Bernoulli(double x) {
  return (sqrt(sqrt(1 + 4 * pow(x, 2)) - pow(x, 2) - 1));
}

double hyperbola(double x) { return (1 / pow(x, 2)); }