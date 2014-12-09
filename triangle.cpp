#include "utils.h"
using namespace std;

int minSum(vector<vector<int> > & triangle, int i, vector<int> min_sum){ 
  
  vector<int> row_min_sum;
  // on the N^th row, there are N elements
  // compute row_min_sum 
  for(int j=0; j<triangle[i].size(); j++){
    if(j==0){
      row_min_sum.push_back(min_sum[j] + triangle[i][j]);
    }else{
      if(j != triangle[i].size()-1 && i> 0)
        row_min_sum.push_back(std::min(min_sum[j-1], min_sum[j]) + triangle[i][j]);
      else
        row_min_sum.push_back(min_sum[j-1] + triangle[i][j]);
    }
  }
  if(false){
    printVector(row_min_sum);
  }
  return (i==triangle.size()-1) ? (*min_element(row_min_sum.begin(), row_min_sum.end())) : minSum(triangle, i+1, row_min_sum);
  
}
    
int minimumTotal(vector<vector<int> > &triangle) {
  if(triangle.size()==0) return 0;
  //for row i, min_sum stores all the mini sum for every element the (i-1)^th row
  vector<int> min_sum;
  min_sum.push_back(0);
  return minSum(triangle, 0, min_sum);
}


int main(){
  vector<vector<int> > T({{-1}, {-2, -3}});
  cout<<minimumTotal(T)<<endl;
  vector<vector<int> > T1({{1}, {2, 3}});
  cout<<minimumTotal(T1)<<endl;
  vector<vector<int> > T2({{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}});
  cout<<minimumTotal(T2)<<endl;
  return 0;      
}
