#include <math.h>
#include <stdio.h>

double Agnesi(double x);
double Bernoulli(double x);
double hyperbola(double x);
void print(double y, double div, double y_min);

int main() {
  double Ag, Be, he;
  double y_ag_m, y_be_m, y_he_m, y_ag_mi=10, y_be_mi=10, y_he_mi=10;
  double x = (-1) * M_PI;
  double div = (2 * M_PI / 41);
  double div_y_ag, div_y_be, div_y_he;

  for (int i = 0; i < 42; i++) {

    Ag = Agnesi(x);
    Be = Bernoulli(x);
    he = hyperbola(x);
    y_ag_m = fmax(y_ag_m, Ag);
    y_be_m = fmax(y_be_m, Be);
    y_he_m = fmax(y_he_m, he);
    y_ag_mi = fmin(y_ag_mi, Ag);
    y_be_mi = fmin(y_be_mi, Be);
    y_he_mi = fmin(y_he_mi, he);
    x += div;
  }
  div_y_ag = (y_ag_m-y_ag_mi)/20;
  div_y_be = (y_be_m-y_be_mi)/20;
  div_y_he = (y_he_m-y_he_mi)/20;
  x = (-1) * M_PI;
  for(int i = 0; i < 42; i++){
    print(Ag = Agnesi(x), div_y_ag, y_ag_mi);
    x += div;
  } 
  for (int j=0; j<30; j++){
        printf("-");
    }
    printf("-\n");
  x = (-1) * M_PI;
  for(int i = 0; i < 42; i++){
    print(Be = Bernoulli(x), div_y_be, y_be_mi);
    x += div;
  } 
    for (int j=0; j<30; j++){
        printf("-");
    }
    printf("-\n");
    x = (-1) * M_PI;
  for(int i = 0; i < 42; i++){
    print(he = hyperbola(x), div_y_he, y_he_mi);
    x += div;
  } 


  //printf("%.7lf\n%.7lf\n%.7lf\n%.7lf\n%.7lf\n%.7lf\n", div_y_ag, y_ag_mi, y_be_m, y_be_mi, y_he_m, y_he_mi);
}

double Agnesi(double x) { return (1 / (1 + pow(x, 2))); }

double Bernoulli(double x) {
  return (sqrt(sqrt(1 + 4 * pow(x, 2)) - pow(x, 2) - 1));
}

double hyperbola(double x) { return (1 / pow(x, 2)); }

void print (double y, double div, double y_min){
    int count = (y - y_min)/div;
    for (int j=0; j<count; j++){
        printf(" ");
    }
    printf("*\n");
}