// https://www.codechef.com/CSTR2020/problems/MALLTILE
#include<bits/stdc++.h>
using namespace std;
#define l long long int

int main(){
    int t;
    cin>>t;
    while(t--){
    int n,sum=0;
    l k;
    cin>>n>>k;
    vector<l> d;
    for (int i=0;i<n;i++){
        l x;
        cin>>x;
        d.push_back(x);
        sum+=x;
    }
    if (sum%k!=0){
        int t=0;
        while(sum%k!=0){
            sum+=1;
            t+=1;
        }
        cout<<t<<endl;
    }
    else{
        cout<<0<<endl;
    }
    }
    return 0;
}
