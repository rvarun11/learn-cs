// Technocup 2021 - ER 3
//https://codeforces.com/contest/1411

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll solve(ll n){
    ll temp=n;      
    while(temp){
        int digit=temp%10;
        temp/=10;
        if (digit==0)
            continue;

        if (n%digit==0)
            continue;
        else{
            n++;
            temp=n;
        }
    }
    return n;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        ll n;
        cin>>n;
        cout<<solve(n)<<"\n";
    }
    return 0;
}