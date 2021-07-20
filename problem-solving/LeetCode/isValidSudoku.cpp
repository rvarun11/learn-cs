//

#include <bits/stdc++.h>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    
    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            if (board{i}{j}=='.') continue;
            
            if (!isSafe(board,i,j,board{i}{j})) return false;
        }
    }
    return true;
}

bool isSafe(vector<vector<char>>& board,int row,int col,char c) {
    
    // check if the i row and j col has the value c or not.
    for (int i=0;i<9;i++){
        if (board[i][col]==c) return false;
        if (board[row][i]==c) return false;
    }
    
    // the starting position of the sub-grid
    int grid_row = row - row%3;
    int grid_col = col - col%3;
    
    // check for that particular grid
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            if (board[grid_row+i][grid_col+j]==c) return false;
    
    return true;
}

int main(){

    vector<vector<char>> s = {{"5","3",".",".","7",".",".",".","."}
,{"6",".",".","1","9","5",".",".","."}
,{".","9","8",".",".",".",".","6","."}
,{"8",".",".",".","6",".",".",".","3"}
,{"4",".",".","8",".","3",".",".","1"}
,{"7",".",".",".","2",".",".",".","6"}
,{".","6",".",".",".",".","2","8","."}
,{".",".",".","4","1","9",".",".","5"}
,{".",".",".",".","8",".",".","7","9"}};

    return 0;
}