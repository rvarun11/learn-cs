// https://cses.fi/problemset/task/1621/

#include<bits/stdc++.h>
using namespace std;
#define L long long int

int main(){
    L n,x;
    cin>>n;
    set<L> s;
    for (int i=0;i<n;i++){
        cin>>x;
        s.insert(x);
    }
    cout<<s.size()<<endl;
    return 0;
}
