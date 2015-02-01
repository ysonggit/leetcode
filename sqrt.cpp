#include "utils.h"

using namespace std;

/*
   Newton's method   

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
    }*/
/*
  note that the returned type is int
  means using divide and conquer can be more efficient 

  x < 0? return ?
  overflow?
*/
int sqrt(int x){
    if(x<0) return -1;
    if(x==0) return 0;
    int left = 1, right = x/2+1;
    while(left <= right){
        int mid = (int)(left+right)/2;
        // do not use mid * mid == x due to overflow
        // check if x/mid satisfy both lower and upper bound [mid, mid+1)
        if(x/mid >= mid && x/(mid+1) < mid+1){
            return mid;
        }
        if(x/mid < mid){
            // mid is greater 
            right = mid-1;
        }else if(x/mid > mid){
            left = mid +1;
        }
    }
    return 1;
}

int main(){
    for(int i=0; i<10; i++){
        cout<<sqrt(i)<<endl;
    }
    cout<<sqrt(INT_MAX)<<endl;
    return 0;
}
