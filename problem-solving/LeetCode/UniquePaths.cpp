// https://leetcode.com/problems/unique-paths/
// https://leetcode.com/problems/unique-paths/discuss/1047684/Dynamic-Programming-with-Memoization-and-Recursion
//https://www.youtube.com/watch?v=oBt53YbR9Kk

#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;

int memo{101}{101} =  {};

int uniquePaths(int m,int n){
        
    if (m==0 || n==0) return 0;     
    if (m==1 && n==1) return 1;

    int &curr = memo{m}{n};

    if (curr) return memo{m}{n};

     memo{m}{n} = uniquePaths(m-1,n) + uniquePaths(m,n-1);
     return memo{m}{n};
}


int main(){
    cout<<uniquePaths(3,7)<<"\n";
	return 0;
}