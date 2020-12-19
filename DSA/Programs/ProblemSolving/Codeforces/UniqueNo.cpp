// https://codeforces.com/blog/entry/85594

#include <bits/stdc++.h>
using namespace std;

void solve(int x) {
 int sum=0,last=9;
 vector<int> ans;
 while (sum<x && last>0){
   int a = x-sum;
   ans.push_back(min(a,last));
   sum+=last;
   last--;
 }

 if (sum < x)
  cout<<-1<<endl;
 else{
    reverse(ans.begin(),ans.end());
  for (int i: ans){
    cout << i;
  }
  cout << endl;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    solve(x);
  }
}