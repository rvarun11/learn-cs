// https://leetcode.com/problems/longest-palindromic-substring/

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){
    string temp = s;
    reverse(temp.begin(),temp.end());
    return temp == s;
}

string longestPalindrome(string s) {
    
}

int main(){
    cout<<longestPalindrome("ac");
    return 0;
}