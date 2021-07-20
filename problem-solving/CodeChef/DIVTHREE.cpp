// https://www.codechef.com/JAN21C?order=desc&sortBy=successful_submissions
#include<bits/stdc++.h>
using namespace std;
#define l long long int

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k,d;
        cin>>n>>k>>d;
        l x,cp=0;
        for(int i=0;i<n;i++){
            cin>>x;
            cp+=x;
        }
        if(cp<k)
            cout<<0<<endl;
        else{
            int c=cp/k;
            if (c<=d)
                cout<<c<<endl;
            else
                cout<<d<<endl;
        }
    }
    return 0;
}
