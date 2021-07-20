// https://leetcode.com/problems/richest-customer-wealth/

#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int currSum = 0;
        int maxSum = 0;
        for (int i=0;i<accounts.size();i++){
            for (int j=0;j<accounts{i}.size();j++){
                currSum+=accounts{i}{j};
            }
            maxSum = max(maxSum,currSum);
            currSum = 0;
        }
        
        return maxSum;
    }
};