//https://cses.fi/problemset/task/1141

#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;
// const lli mod = 1e9 + 7;

int main(){
    int n,x;
    cin>>n;
    unordered_set<int> songs;
    int count = 0,max_seq=0;
    for (int i=0;i<n;i++){
        cin>>x;
        if (songs.find(x)!=songs.end()){
            count=0;
            songs.clear();
        }
        songs.insert(x);
        count++;
        max_seq = max(max_seq,count);
    }
    cout<<max_seq;
	return 0;
}