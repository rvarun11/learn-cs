// https://cses.fi/problemset/task/1074

#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;
// const lli mod = 1e9 + 7;

int main(){
    int n;
    lli cost=0;
    cin>>n;
    vector<int> sticks(n);

    for (int i=0;i<n;i++)
        cin>>sticks{i};
    
    sort(sticks.begin(),sticks.end());

    int median = sticks{n/2};
    
    for (int i=0;i<n;i++)
        cost+=abs(sticks{i}-median);
    cout<<cost;
    return 0;
}