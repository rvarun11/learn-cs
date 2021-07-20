//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> s;
    for (auto i: nums){
        if (s.find(i)==s.end()) s.insert(i);
        else return true;
    }
    return false;
}