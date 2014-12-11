#include <iostream>
using namespace std;

/*
  
 */

double absval(double a){
    return (a<0)? -a : a;    
}

int sqrt(int x){
    double guess = x/2.0;
    double epsilon = 0.000001;
    while(absval(x-guess*guess) > epsilon*x){
        guess = 0.5*(x/guess+guess);
    }
    return (int)guess;
}

int main(){
    cout<<sqrt(4)<<endl;
    return 0;
}
