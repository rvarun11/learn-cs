// https://www.codechef.com/UWCOI21/problems/UWCOI21B
// https://discuss.codechef.com/t/uwcoi21b-array-swaps-editorial/82418
#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m, a, mini = INT_MAX, ans;

signed main() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> a;
        mini = min(mini, a);
    }
    for (int i=0; i<m; i++) {
        cin >> a;
        if (a < mini) ans++;
    }
    cout << ans*n << endl;
}