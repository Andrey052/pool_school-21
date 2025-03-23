#include <math.h>
#include <stdio.h>

int its_simple(int number);
int max_simple(int number_in);
int max_minus(int start_number, int minus);
int main(){
    int x;
    char t;
    int res;
    if (scanf("%d", &x) != 2){
        if (x>1){
            res = max_simple(x);
            if (res == 0){
                printf("n/a\n");
                return 0;
            }else{
                printf("%d\n", res);
                return 0;
            }
        }else if(x>=0) {
            printf("n/a\n");
            return 0;
        }else{
            res = max_simple(x*(-1));
            if (res == 0){
                printf("n/a\n");
                return 0;
            }else{
                printf("%d\n", res);
                return 0;
            }
        } 
    }else{
        printf("n/a\n");
    }
}

int max_simple(int number_in){
    int max = 0;
    for (int j = 2; j< number_in; j++){
        if (max_minus(number_in, j)==1){
            if (its_simple(j)==1){
                max = j;
            }
        }
    }
    return max;
}

int its_simple(int number){
    for (int i=2; i<number; i++){
        if (max_minus(number, i)==1){
            return 0;
        }
    }
    return 1;
}

int max_minus(int start_number, int minus)
{
    while(start_number>=0){
        if (start_number == 0){
            return 1;
        }
        start_number-=minus;
    }
    return 0;
}