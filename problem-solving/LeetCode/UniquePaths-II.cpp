// https://leetcode.com/problems/unique-paths-ii/
// https://leetcode.com/problems/unique-paths/discuss/1047684/Dynamic-Programming-with-Memoization-and-Recursion

#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double

using namespace std;

int dp{101}{101} = {};

int helper(vector<vector<int>>& obstacleGrid, int row, int col){
    
    if (row<0 || col<0 || obstacleGrid{row}{col}==1) return 0;
    if (row==0 && col==0) return 1;

    int &curr = dp{row}{col};
    if (curr) return  dp{row}{col};

    dp{row}{col} = helper(obstacleGrid,row-1,col) + helper(obstacleGrid,row,col-1);
    
    return dp{row}{col};
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
    int rows = obstacleGrid.size();
    int cols = obstacleGrid{0}.size();
    int row = rows - 1, col = cols - 1;
    
    //deal with these edge cases separately.
    if (obstacleGrid{row}{col}==1) return 0;
    if (rows==1 && cols==1 && obstacleGrid{row}{col}==0) return 1;

    dp{row}{col} = helper(obstacleGrid,row-1,col) + helper(obstacleGrid,row,col-1);

    return dp{row}{col};
}

int main(){
    vector<vector<int>> oG = {{0}};
    cout<<uniquePathsWithObstacles(oG);
    return 0;
}