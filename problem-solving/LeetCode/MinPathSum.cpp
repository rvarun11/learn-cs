// https://leetcode.com/problems/4sum/
// https://www.youtube.com/watch?v=t1shZ8_s6jc

#include <bits/stdc++.h>
using namespace std;

int dp{101}{101} = {};
int minPathSum(vector<vector<int>>& grid) {
    int row = grid.size() - 1;
    if (row<0) return 0;
    int col = grid{0}.size() - 1;

    dp{0}{0} = grid{0}{0};

    //first fill row 
    for (int i=1;i<=row;i++)
        dp{i}{0} = dp{i-1}{0} + grid{i}{0};    
    for (int j=1;j<=col;j++)
        dp{0}{j} = dp{0}{j-1} + grid{0}{j};

    for (int i=1;i<=row;i++){
        for (int j=1;j<=col;j++)
            dp{i}{j} = grid{i}{j} + min(dp{i-1}{j},dp{i}{j-1});
    }

    return dp{row}{col};
}