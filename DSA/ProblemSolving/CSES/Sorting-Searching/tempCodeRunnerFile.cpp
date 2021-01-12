// https://cses.fi/problemset/task/1621/

#include<bits/stdc++.h>
using namespace std;
#define L long long int

int main(){
    L n,c=0;
    cin>>n;
    vector<L> v;
    for (int i=0;i<n;i++){
        L x;
        cin>>x;
        if (find(v.begin(),v.end(),x)==v.end()){
            v.push_back(x);
            c++;
        }
    }
    cout<<c<<endl;
    return 0;
}
