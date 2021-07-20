//https://cses.fi/problemset/task/1640

#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;
// const lli mod = 1e9 + 7;

int main(){
    int n,x,temp;
    cin>>n>>x;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        cin>>temp;
        v.push_back(make_pair(temp,i+1));
    }
    
    sort(v.begin(),v.end());
    int left=0,right=n-1;

    while(left<right){
        temp=v{left}.first+v{right}.first;
        if (temp==x){
            cout<<v{left}.second<<" "<<v{right}.second;
            break;
        }
        else if (x<temp)
            right--;
        else
            left++;
    }
    if (left>=right)
        cout<<"IMPOSSIBLE"; 
    return 0;
}