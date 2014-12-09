#include "utils.h"

using namespace std;

bool find(const vector<vector<int> > &matrix, int target, int row, int col){
  if(row>=matrix.size() || col < 0) {
    cout<<"row= "<<row<<" col= "<<col<<endl;
    return false;
  }
  int num = matrix[row][col];
  if(num == target) return true;
  if(num < target){
    // pass by this column
    return find(matrix, target, row+1, col);
  }
  // pass by this row 
  return find(matrix, target, row, col-1);
}
bool searchMatrix(vector<vector<int> > &matrix, int target) {
  int rows = matrix.size();
  if(rows==0) return false;
  int cols = matrix[0].size();
  //binary search from upper right corner
  return find(matrix, target, 0, cols-1);
}

int main(){
  vector<vector<int> > matrix;
  vector<int> row1({1,3});
  matrix.push_back(row1);
  if(searchMatrix(matrix, 1)){
    cout<<"find"<<endl;
  }else{
    cout<<"not find"<<endl;
  }
  return 0;
}
