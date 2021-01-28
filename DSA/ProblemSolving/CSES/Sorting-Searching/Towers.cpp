//https://cses.fi/problemset/task/1073

#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;
// const lli mod = 1e9 + 7;

int main(){
    int n;
    cin>>n;
    multiset<int> cubes;
    
    for (int i=0,x;i<n;i++){
        cin>>x;
        auto it = cubes.upper_bound(x);
        if (it==cubes.end())
            cubes.insert(x);
        else{
            cubes.erase(it);
            cubes.insert(x);
        }
    }
    cout<<cubes.size();
    return 0;
}
