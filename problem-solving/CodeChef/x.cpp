// https://www.codechef.com/CSTR2020/problems/MALLTILE
#include<bits/stdc++.h>
using namespace std;
#define l long long int

int main(){
    l n;
    cin>>n;
    set<int> f;
    for (l i=0;i<n;i++){
        int x;
        cin>>x;
        f.insert(x);
    }
    for (l i=0;i<n+1;i++){
        int y;
        cin>>y;
        if(f.find(y)!=f.end())
            continue;
        else{
            cout<<y<<endl;
            break;
        }

    }
    return 0;
}