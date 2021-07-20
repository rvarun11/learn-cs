// https://www.codechef.com/JAN21C/
#include<bits/stdc++.h>
using namespace std;
#define L long long int

int binToDec(int b){
    int dec_value = 0, base = 1;
 
    int temp = b;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
 
        dec_value += last_digit * base;
 
        base = base * 2;
    }
 
    return dec_value;
}

char solve(string s){
    stringstream ss(s);
    int y=0;
    ss>>y;
    y = binToDec(y);
    return (97+y);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        L n;
        cin>>n;
        string x;
        cin>>x;
        for (int i=0;i<n;i+=4){
            string sub = x.substr(i,4);
            cout<<solve(sub);
        }
        cout<<endl;
    }
    return 0;
}
