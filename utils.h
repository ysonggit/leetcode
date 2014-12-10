#include <utility> //pair
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>

template <typename T>
void printVector(std::vector<T> v){
   for(T i : v){
      std::cout<<i<<" ";
   }
   std::cout<<std::endl;
}

template <typename T>
void print2DVector(std::vector<std::vector<T> > vv){
     for(std::vector<T> v: vv){
	  printVector(v);
     }
}
