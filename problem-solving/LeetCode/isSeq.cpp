//https://leetcode.com/problems/is-subsequence/

#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;
// const lli mod = 1e9 + 7;

bool isSubsequence(string s, string t) {
    // substring pointer
    int i=0;
    // main string ptr
    int j=0;

    while(i<s.size() && j<t.size()){
        if (s{i}==t{j})
            i++;
        j++;
    }
    
    return i==s.size();
}