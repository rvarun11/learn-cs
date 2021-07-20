//https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int l = 0, r = 0;
    int max_len = 0;
    unordered_set<char> chars;
    while (r<s.size()){
        if (chars.find(s{r})==chars.end()){
            chars.insert(s{r});
            r++;
            int x = chars.size();
            max_len  = max(x,max_len);
        }
        else{
            chars.erase(s{l});
            l++;
        }
    }
    return max_len;
}

int main(){
    cout<<lengthOfLongestSubstring("bbbbbb");
    return 0;
}