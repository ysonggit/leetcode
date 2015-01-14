#include "utils.h"

using namespace std;

vector<vector<int> > generateMatrix(int n) {
    vector<vector<int> > M;
    if(n<=0) return M;
    M.resize(n, vector<int>(n));
    int start_row = 0, end_row = n-1, start_col = 0, end_col = n-1;
    int k = 1;
    while(true){
        // fill top row from left to right
        for(int j=start_col; j<=end_col; j++){
            M[start_row][j] = k++;
        }
        // fill right col from top to down
        for(int i=start_row+1; i<=end_row; i++){
            M[i][end_col] = k++;
        }
        // fill bottom row from right to left
        for(int j=end_col-1; j>=start_col; j--){
            M[end_row][j] = k++;
        }
        // fill left col from bottom to top
        for(int i=end_row-1; i>=start_row+1; i--){
            M[i][start_col] = k++;
        }
        if(end_col-- < start_col) break;
        if(end_row-- < start_row ) break;
        if(start_col++ > end_col) break;
        if(start_row++ > end_row) break;
    }
    return M;
}

int main(int argc, char *argv[])
{
    print2DVector(generateMatrix(3));
    print2DVector(generateMatrix(4));
    return 0;
}


