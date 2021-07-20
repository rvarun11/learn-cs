//https://cses.fi/problemset/task/1091

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    int n,m,temp;
    cin>>n>>m;
    vector<int> tickets(n);
    for (int i=0;i<n;i++)
        cin>>tickets{i};
    
    sort(tickets.rbegin(),tickets.rend());

    for(int i=0;i<m;i++){
        cin>>temp;
        auto it=lower_bound(tickets.begin(),tickets.end(),temp);
        if (it==tickets.end())
                cout<<"-1"<<"\n";
        else{
            cout<<*it<<"\n";
            tickets.erase(it);
        }
    }
    return 0;
}