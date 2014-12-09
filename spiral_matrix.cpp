#include <vector>
#include <iostream>

using namespace std;
typedef vector<vector<int> > Matrix;

void recurLayer(vector<int> & result, Matrix & M, int row_start, int row_len, int col_start, int col_len){
  // base case
  if(row_len <= 0 || col_len <= 0) return;
  if(row_len == 1){
    // push element in current column
    for(int col=col_start; col<col_start+col_len; col++){
      result.push_back(M[row_start][col]);
    }
    return;
  } 
  if(col_len == 1){
    for(int row=row_start; row<row_start+row_len; row++){
      result.push_back(M[row][col_start]);
    }
    return;
  }
  // general case
  // 1. top row (row_start)
  for(int col= col_start; col<col_start+col_len; col++){
    result.push_back(M[row_start][col]);
  }
  // 2. right col
  int col_right = col_len + col_start - 1;
  for(int row = row_start+1; row<row_start+row_len; row++){
    result.push_back(M[row][col_right]);
  }
  // 3. bottom row
  int row_bottom = row_start+row_len - 1;
  for(int col= col_right - 1; col >= col_start; col--){
    result.push_back(M[row_bottom][col]);
  }
  // 4. left col (col_start)
  for(int row = row_bottom -1; row > row_start; row--){
    result.push_back(M[row][col_start]);
  }
  // recursive call to the inner layer
  row_len -= 2;
  col_len -= 2;
  recurLayer(result, M, row_start+1, row_len, col_start+1, col_len);
}
    
vector<int> spiralOrder(vector<vector<int> > &matrix) {
  vector<int> result;
  if(matrix.size()==0) return result;
  int row_len = matrix[0].size();
  int col_len = matrix.size();
  recurLayer(result, matrix, 0, row_len, 0, col_len);
  return result;
}

int main(){
  
}
