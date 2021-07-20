//Nth Fibonnaci with Memoization

#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;


int fib(int n){
    if (n==0) return 0;
    if (n==1) return 1;

    int memo{n+1};
    memo{0}=0;
    memo{1}=1;

    for (int i=2;i<=n;i++)
        memo{i} = memo{i-1} + memo{i-2};

    return memo{n};
    
}


int main(){
    cout<<fib(3)<<"\n";
	return 0;
}