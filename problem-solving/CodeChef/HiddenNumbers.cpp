//https://www.codechef.com/UWCOI21/problems/UWCOI21A

#include <bits/stdc++.h> 
using namespace std;

void solve(int n){
    int check=0;
    for (int i=2;i<=sqrt(n);i++){
        if (n%i==0){
            int n1=i,n2=n/i;
            cout << n1 << " " << n2 << endl;
            check=1;
            break;
        }
    }
    if (check==0)
        cout << 1 << " " << n << endl;
}

int main()  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        solve(n);
    }
    return 0;
}