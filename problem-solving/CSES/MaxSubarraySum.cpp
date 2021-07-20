// https://cses.fi/problemset/task/1643
// Kadane's Algorithm

#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;
// const lli mod = 1e9 + 7;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i=0;i<n;i++)
        cin>>v{i};
    
    lli currSum=0,maxSum=INT_MIN;
    
    for(int i=0;i<n;i++){
        currSum+=v{i};
        if (currSum<v{i})
            currSum=v{i};

        if (currSum>maxSum)
            maxSum=currSum;  
    }
    cout<<maxSum;
    return 0;
}