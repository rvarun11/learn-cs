//https://leetcode.com/problems/remove-k-digits/

#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n = num.size();
    stack<char> stk;

    for (char c: num){
        while(!stk.empty() && k>0 && stk.top()>c){
            stk.pop();
            k--;
        }
        // 0s should not be in the front...
        if (!stk.empty() || c!='0') stk.push(c);
    }

    // in case all the values are same in num or always increasing, eg. 1111111 OR 1234567 Then k will remain the same so for that...
    while (!stk.empty() && k--) stk.pop();
    if (stk.empty()) return "0";

    // storing the new value inside num itself.
    num = "";
    while (!stk.empty()){
        num+=stk.top();
        stk.pop();
    }
    reverse(num.begin(),num.end());

    return num;
}


int main(){
    string s = "10200";
    cout<<removeKdigits(s,1);
    return 0;
}