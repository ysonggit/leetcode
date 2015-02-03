#include "utils.h"

/*
  divide and conquer
  pow(x,n) = pow(x, n/2) * pow(x, n/2) * x^{n%2}

  n is negative
  1/pow(x, abs(n))
*/
double pow(double x, int n){
    if(n==0) return 1;
    if(n==1) return x;
    double v = pow(x, abs(n)>>1);
    double vv = v * v;
    if(n&1){
        vv *= x;
    }
    return (n<0) ? 1/vv : vv;
}

int main(int argc, char *argv[]){
    for(int i=0; i<10; i++){
        std::cout<<pow(2.0, i)<<std::endl;
        std::cout<<pow(2.0, -i)<<std::endl;
    }
    return 0;
}


