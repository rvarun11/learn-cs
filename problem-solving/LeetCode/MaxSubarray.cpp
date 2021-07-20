//https://leetcode.com/problems/maximum-subarray/

#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;
// const lli mod = 1e9 + 7;

int maxSubArray(vector<int>& nums){
    int maxCurrent = nums{0};
    int maxGlobal = nums{0};

    for (int i=i;i<nums.size();i++){
        maxCurrent = max(nums{i},nums{i}+maxCurrent);
        if (maxCurrent > maxGlobal){
            maxGlobal = maxCurrent;
        }
    }
    return maxGlobal;
}

int main(){
	return 0;
}