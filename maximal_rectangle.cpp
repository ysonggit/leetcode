#include "utils.h"

using namespace std;
/*https://leetcodenotes.wordpress.com/category/leetcode/
  define D[i,j] as the max number of continuous 1's ending at col j, in row i
         D[i,j] = D[i,j-1] + 1 if M[i,j] = 1
                  0            if M[i,j] = 0

  in matrix D, for each cell at D[i,j], it corresponds a width
     therefore, search the max height corresponds to this width by
     expanding current cell up and down, until the  width is smaller than current one

     given a cell in D : D[i][j]
     ---------------------------   ---
     |        ______           |
     |       |      |          |   upper_height
     |       |D(i,j)|          |  ------ row i
     |       |      |          |
     |       |_____ |          |   lower_height
     ---------------------------   ---
 */

int maximalArea(vector<vector<int> > &D, int i, int j){
    int cur_width = D[i][j];
    int upper_row_idx = i-1, lower_row_idx = i+1;
    int upper_height = 0, lower_height = 0;
    while(upper_row_idx >=0 && D[upper_row_idx][j]>= cur_width ){
        upper_height++;
        upper_row_idx--;
    }
    while(lower_row_idx < D.size() && D[lower_row_idx][j] >= cur_width){
        lower_height++;
        lower_row_idx++;
    }
    return cur_width*(1+upper_height+lower_height);
}

int maximalRectangle(vector<vector<char> > &matrix) {
    if(matrix.size()==0) return 0;
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int> > D(m, vector<int>(n,0));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] == '1'){
                D[i][j] = (j>0) ? D[i][j-1] + 1 : 1;
            }
        }
    }
    int max_rect = 0;
    //print2DVector(D);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(D[i][j]>0){
                // expand up and down
                max_rect = max(max_rect, maximalArea(D, i, j));
            }
        }
    }
    return max_rect;
}

int main(int argc, char *argv[]){
    vector<vector<char> > matrix = {
        {'0','0','1','0','0','1'},
        {'1','0','1','0','1','1'},
        {'1','1','1','0','1','1'},
        {'1','1','1','0','0','1'},
        {'0','1','1','1','0','0'},
        {'0','1','1','1','1','1'}
    };
    cout<<maximalRectangle(matrix)<<endl;
    return 0;
}


