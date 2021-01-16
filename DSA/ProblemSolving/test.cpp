#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;
const lli mod = 1e9 + 7;

int main()
{
    vector<int> v={5,4,3,2,1};
    multiset<int,greater<int>> s;
    s.insert(5);
    s.insert(4);
    s.insert(3);
    s.insert(2);
    s.insert(1);
    auto i1 = lower_bound(v.begin(),v.end(),2);
    auto i2 = s.lower_bound(2);
    cout<<*i1<<" "<<*i2<<endl;

    return 0;
}