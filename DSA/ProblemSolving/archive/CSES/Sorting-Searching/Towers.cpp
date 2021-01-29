//https://cses.fi/problemset/task/1073

#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;
// const lli mod = 1e9 + 7;

int main(){
    int n,x;
    cin>>n;
    vector<pair<int,int>> cubes;

    for (int i=0;i<n;i++){
        cin>>x;
        cubes.push_back(make_pair(x,i));
    }
    
    sort(cubes.begin(),cubes.end());

    int i=1,count=0;
    while(cubes.size()){

    }
    
}
