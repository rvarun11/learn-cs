//https://cses.fi/problemset/submit/1090/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int solve(vector<int> w,int n,int x){
    int left=0,right=n-1,g=0;
    while(left<=right){
        if (w{left}+w{right}<=x){
            left++;
            right--;
        }
        else{
            right--;
        }
        g++;
    }
    return g;
}

int main(){
    int n,x;   
    cin>>n>>x;
    vector<int> w(n);
    for(int i=0;i<n;i++)
        cin>>w{i};

    sort(w.begin(),w.end());
    
    cout<<solve(w,n,x)<<"\n";
    return 0;
}