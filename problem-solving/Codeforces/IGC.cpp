// Technocup 2021 - ER 3
//https://codeforces.com/contest/1411
// Sol.:
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,cp=0;
        cin >> n;
        char msg{n};
        cin >> msg;
        for (int i=n-1;i>=0;i--){
            if (msg{i}==')'){
                cp+=1;
            }
            else
                break;
        }
        int rc=n-cp;
        if (cp>rc)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}