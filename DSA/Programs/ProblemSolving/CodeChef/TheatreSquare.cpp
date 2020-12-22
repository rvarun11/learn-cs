// https://www.codechef.com/CSTR2020/problems/MALLTILE
// https://www.geeksforgeeks.org/minimum-squares-to-cover-a-rectangle/
#include<bits/stdc++.h>
using namespace std;
#define l long long int

int main(){
    l n,m,a;
    cin>>n>>m>>a;
    l ans = ceil(n / (double)a) * ceil(m / (double)a);
    cout << ans << endl;
    return 0;
}