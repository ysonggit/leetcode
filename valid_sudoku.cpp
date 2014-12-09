#include "utils.h"

using namespace std;

bool isValidGroup(const vector<char> & line){
    map<char, int> cache;
    for(char c : line){
	if(c!='.'){
	    if(cache.find(c)==cache.end()){
		cache[c] = 1;
	    }else{
		return false;   
	    }
	}
    } 
    return true;
}

bool isValidSudoku(vector<vector<char> > &board) {
    if(board.size() !=9 || board[0].size()!=9 ) return false;
    // check each row
    for(vector<char> row : board){
	if(!isValidGroup(row)){
	    cout<<"1"<<endl;
	    return false;
	}
    }
    // check each column
    for(int i=0; i<9; i++){
	// create column
	vector<char> col;
	for(int c=0; c<9; c++){
	    col.push_back(board[c][i]);
	}
	if(!isValidGroup(col)){
	    cout<<"2"<<endl;
	    return false;
	}
    }
    // check each sub-grid
    for(int i=0; i<9; i++){
	// create grid
	vector<char> grid;
	for(int j=0; j<9; j++){
	    int r = i/3*3+j/3, c = i%3*3+j%3;
	    grid.push_back(board[r][c]);
	}
	
	if(!isValidGroup(grid)){
	    printVector(grid);
	    return false;
	}
    }
    return true;
}

bool test(vector<vector<char> > &board){
    if(isValidSudoku(board)){
	cout<<"valid\n";
    }else{
	cout<<"false\n";
    }
    
}

int main(){
    char *a  = "....5..1..4.3..........3..18......2...2.7.....15...........2....2.9.......4......";
    vector<vector<char> > sudoku;
    for(int i=0; i<9; i++){
	vector<char> row;
	for(int j=0; j<9; j++){
	    int offset = i * 9 + j;
	    row.push_back(*(a+offset));	    
	}
	sudoku.push_back(row);
    }
    test(sudoku);
    
    return 0;
}
