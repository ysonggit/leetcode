#include "utils.h"

using namespace std;

/*
  idea : Flood-Fill Algorithm
         BFS "o" on the borders  
         for any "o" on the borders has neighbor "o", mark as "y"
         
         replace remaining "o" with 'x'
         replace all 'y' with 'o'
*/
struct Coord{
  Coord(int _x, int _y): x(_x), y(_y) {}
  int x;
  int y;
};

bool validCoord(const vector<vector<char> > &board, int x, int y){
  int max_row_idx = board.size()-1;
  int max_col_idx = 0;
  if(max_row_idx>=0){
    max_col_idx = board[0].size()-1;
  }
  if(x <0 || x > max_row_idx) return false;
  if(y <0 || y > max_col_idx) return false;
  return true;
}

void addNeighbors(vector<vector<char> > &board, int x, int y, queue<Coord> & q){
  if(validCoord(board, x, y)){
    if(board[x][y] != 'Y' && board[x][y]=='O'){
      q.push(Coord(x, y));
      board[x][y] = 'Y';
    }
  }
}

void floodfillBorder(vector<vector<char> > &board, int row, int col){
  if(board[row][col] !='O') return;
  // replace 'O' with 'Y'
  board[row][col] = 'Y'; // visited
  queue<Coord> q;
  q.push(Coord(row, col));
  while(!q.empty()){
    Coord top = q.front();
    q.pop();
    // add top's unvisited neighbors coords to q
    addNeighbors(board, top.x-1, top.y, q);
    addNeighbors(board, top.x+1, top.y, q);
    addNeighbors(board, top.x, top.y-1, q);
    addNeighbors(board, top.x, top.y+1, q);
  }
    
}

void solve(vector<vector<char>> &board) {
  if(board.size()==0) return;
  // fill first/last row (top/bottom border)
  int rows = board.size();
  int cols = board[0].size();
  for(int i=0; i<cols; i++){
    floodfillBorder(board, 0, i);
    floodfillBorder(board, rows-1, i);
  }
  for(int j=0; j<rows; j++){
    floodfillBorder(board, j, 0);
    floodfillBorder(board, j, cols-1);
  }
  for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
      if(board[i][j] == 'O'){
        board[i][j] = 'X';
      }
    }
  }
  for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
      if(board[i][j] == 'Y'){
        board[i][j] = 'O';
      }
    }
  }
    
}


int main(){
  vector<vector<char> > board;
  vector<char> row(4,'X');
  for(int i=0; i<4; i++)
    board.push_back(row);
  board[3][1] = 'O';
  board[2][1] = 'O';
  board[2][0] = 'O';
  board[1][2] = 'O';
  print2DVector(board);
  cout<<endl;
  solve(board);
  print2DVector(board);
  return 0;
}
