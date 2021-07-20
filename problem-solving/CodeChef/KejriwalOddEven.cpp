// https://www.codechef.com/CSTR2020/
#include<bits/stdc++.h>
using namespace std;
#define l long long int

int main(){
    int n;
    cin>>n;
    while(n--){
        string cno;
        cin>>cno;
        int ceven=0,codd=0;
        for (int i=0;i<cno.size();i++){
            int num = int(cno{i});
            if (num%2==0)
                ceven+=num;
            else
                codd+=num;
        }
        if (ceven%4==0 || codd%3==0)
            cout << "Yes" << " ";
        else   
            cout <<"No"<< " ";
    }
    cout<<endl;
    return 0;
}
