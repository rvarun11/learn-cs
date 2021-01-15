#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int solve(vector<int> w,int n,int x){
    int g=0,tw=0;

    for (int i=0;i<n;i++){
    
        if ((tw+w[i])<=x)
            tw+=w[i];
        else{
            g++;
            tw=0;
            i-=1;
        }
    }
    return g+1;
}

int main(){
    int n,x;   
    cin>>n>>x;
    vector<int> w(n);
    for(int i=0;i<n;i++)
        cin>>w[i];

    sort(w.begin(),w.end());
    
    cout<<solve(w,n,x)<<"\n";
    return 0;
}