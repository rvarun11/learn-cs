// https://cses.fi/problemset/task/1084/

#include<bits/stdc++.h>
using namespace std;
#define lli long long int

int main(){
    int n,m,k,ans=0; 
    cin>>n>>m>>k;
    vector<int> a(n),h(m);

    for (int i=0;i<n;i++)
        cin>>a{i};
    for(int i=0;i<m;i++)
        cin>>h{i};
    
    sort(a.begin(),a.end());
    sort(h.begin(),h.end());

    int i=0,j=0;
    while(i<n && j<m){
    if (abs(a{i}-h{j})<=k){
        ans++;
        i++;
        j++;
    }
    else if (a{i}<h{j})
        i++;
    else
        j++;    
    }
    cout<<ans;
    return 0;
}