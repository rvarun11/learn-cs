#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,a,rd,cp=0;
        float max_att=0.0;
        scanf("%d",&n);
        rd=120-n;
        for (int i=0;i<n;i++){
            scanf("%1d",&a);
            if (a==1) cp++;  
        }
        max_att = float(cp+rd)/120.0;
        if (max_att>=.75)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}