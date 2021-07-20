// https://cses.fi/problemset/task/1619

#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;
// const lli mod = 1e9 + 7;

int main(){
    int n,entry,exit,maxCust=0,curr=0;
    cin>>n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        cin>>entry>>exit;
        v.push_back(make_pair(entry,0));
        v.push_back(make_pair(exit,1));
    }

    sort(v.begin(),v.end());
    
    for (auto i: v){
        if (i.second==0){
            curr++;
            maxCust=max(curr,maxCust);
        }
        else
            curr--;
    }

    cout<<maxCust<<"\n";
        
    return 0;
}