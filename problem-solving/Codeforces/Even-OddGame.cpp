// https://codeforces.com/problemset/problem/1472/D

#include<bits/stdc++.h>
using namespace std;
#define L long long int

int main(){
    int t;
    cin>>t;
    while(t--){
        L n,as=0;
        cin>>n;
        vector<L> v;
        for (int i=0;i<n;i++){
            L x;
            cin>>x;
            v.push_back(x);
            }
        sort(v.rbegin(),v.rend());
        for(int i=0;i<n;i++){
            if (!(i&1)){
                if (!(v{i}&1))
                    as+=v{i};
            }
            else{
                if (v{i}&1)
                    as-=v{i};
            }
        }
        if (as==0)
            cout<<"Tie"<<"\n";
        else if (as>0)
            cout<<"Alice"<<"\n";
        else
            cout<<"Bob"<<"\n";

    }
    return 0;
}
