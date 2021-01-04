// https://www.codechef.com/JAN21C/
#include<bits/stdc++.h>
using namespace std;
#define L long long int

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> arr,brr;
        L suma=0,sumb=0;
        for (int i=0;i<n;i++){
            L x;
            cin>>x;
            suma+=x;
            arr.push_back(x);
        }
        for (int i=0;i<m;i++){
            L x;
            cin>>x;
            sumb+=x;
            brr.push_back(x);
        }
        if (suma>sumb){
            cout<<0<<endl;
            break;
        }
        int s=0;
        while(suma<=sumb){
            L mina=*min_element(arr.begin(),arr.end());
            L maxb=*max_element(brr.begin(),brr.end());
    
        }

        }


    }
    return 0;
}
