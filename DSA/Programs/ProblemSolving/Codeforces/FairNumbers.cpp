// Technocup 2021 - ER 3
//https://codeforces.com/contest/1411
// Sol.:
#include<bits/stdc++.h>
using namespace std;
#define L long long int
void solve(L n){
    L temp = n;
    while (n){
        int d = n%10;
        if (temp%d!=0){
            temp++;
            n++;
        }
        n/=10;
    }

}

int main(){
    int t;
    cin>>t;
    while (t--){
        L n;
        cin>>n;
        solve(n);
    }
    return 0;
}