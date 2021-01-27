//https://cses.fi/problemset/task/1141

#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;
// const lli mod = 1e9 + 7;

int main(){
    lli n,x;
    cin>>n;
    vector<lli> songs(n);
    
    for (int i=0;i<n;i++)
        cin>>songs[i];
    int i=0,j=1;
    lli count=0,max_seq=0;
    while(songs.size()!=0){
        if (songs[i]==songs[j]){
            i++;
        }
    }
        

    cout<<max_seq;
	return 0;
}