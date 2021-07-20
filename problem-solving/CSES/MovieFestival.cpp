// https://cses.fi/problemset/task/1629

#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;
// const lli mod = 1e9 + 7;

int main(){
    int n,start,end,maxMovies=1;
    cin>>n;
    vector<pair<int,int>> v;

    for (int i=0;i<n;i++){
        cin>>start>>end;
        v.push_back(make_pair(end,start));
    }
    sort(v.begin(),v.end());

    pair<int,int> lastWatched = v{0};
    for(int i=0;i<n;i++){
        if (v{i}.second >= lastWatched.first){
            maxMovies++;
            lastWatched=v{i};
        }
    }
    cout<<maxMovies<<"\n";
    return 0;
}

