// https://www.codechef.com/RTCG2020/problems/RTCG001
#include<bits/stdc++.h>
using namespace std;
#define l long long int

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,c=0;
        cin>>n;
        while(n){
            int k = n%10;
            if (k!=0){
                if (n%k==0) c++;
            }
            n/=10;
        }
        cout<<c<<endl;
    }
    return 0;
}
