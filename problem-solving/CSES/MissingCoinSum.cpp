// https://cses.fi/problemset/task/2183
//https://www.geeksforgeeks.org/find-smallest-value-represented-sum-subset-given-array/

#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;
// const lli mod = 1e9 + 7;

int main(){
    int n;
    cin>>n;
    vector<int> coins(n);
    lli ans=1;
    for(int i=0;i<n;i++)
        cin>>coins{i};
    
    sort(coins.begin(),coins.end());

    for (int i=0;i<n;i++)
        if (coins{i}<=ans)
            ans+=coins{i};

    cout<<ans;

    return 0;

}
