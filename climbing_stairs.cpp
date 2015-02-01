#include "utils.h"

using namespace std;
/*
  # of ways to climb n stairs = # of ways to climb n-1 stairs
                              + # of ways to climb n-2 stairs
  f(n) = f(n-1) + f(n-2)
  be careful of base case
  1) recursive fib(n){ if(n<0) return 0; if (n<=1) return 1; return fib(n-1)+fib(n-2);}
     Time Limit Exceeded

  2) use map 3ms
  3) iterative fib(n) 2ms
 */
/*
unordered_map<int, int> cache;

int climbStairs(int n){
    if(n<0) return 0;
    if(n<=1) return 1; // n=1 should have only 1 way, n=2, 2 ways
    if(cache.find(n) != cache.end()){
        return cache[n];
    }else{
        cache[n] = climbStairs(n-1) + climbStairs(n-2);
    }
    return cache[n];
    }*/

int climbStairs(int n){
    if(n<0) return 0;
    if(n<=1) return 1;
    // n>=2
    int climb_n_1 = 1, climb_n_2 = 0;
    int climb_n;
    for(int i=1; i<=n; i++){
        climb_n = climb_n_1 + climb_n_2;
        climb_n_2 = climb_n_1;
        climb_n_1 = climb_n;
    }
    return climb_n;
}

int main(int argc, char *argv[]){
    cout<<climbStairs(2)<<endl;
    return 0;
}
