// https://www.codechef.com/CSTR2020/problems/SUBTRACT
#include<bits/stdc++.h>
using namespace std;
#define l long long int
int main(){
    l n;
    int k;
    cin>>n>>k;
    while(k!=0){
        if (n%10==0)
            n/=10;
        else
            n--;
        k--;
        }
    cout<<n<<endl;
    return 0;
}