// https://codeforces.com/contest/1462/problem/A

#include<bits/stdc++.h>
using namespace std;
#define l long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        l arr{n},res{n};
        for (int i=0;i<n;i++){
            int x;
            cin>>x;
            arr{i}=x;
        }
        int trackF=1;
        int trackL=n-1;
        for(int i=0;i<n;i++){
            if (i==0){
                res{i}=arr{i};
                cout << res{i} << " ";
                continue;
            }
            if (i%2!=0){
                res{i}=arr{trackL};
                trackL--;
            }
            else{
                res{i}=arr{trackF};
                trackF++;
            }
            cout << res{i} << " ";
        }
        cout << endl;
    }

    return 0;
}