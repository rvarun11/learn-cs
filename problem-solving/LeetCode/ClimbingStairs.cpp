//https://leetcode.com/problems/maximum-subarray/

#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;
// const lli mod = 1e9 + 7;

int climbStairs(int n) {   
    if (n<=3)
        return n;
    
    int steps{n};
    steps{0}=1;
    steps{1}=2;
    steps{2}=3;

    for (int i=3;i<n;i++)
        steps{i} = steps{i-1} + steps{i-2};

    return steps{n-1};
}

int main(){
    cout<<climbStairs(5);
	return 0;
}