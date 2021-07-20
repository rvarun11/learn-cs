//https://leetcode.com/problems/majority-element/
// https://leetcode.com/problems/merge-sorted-array/

#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;

int majorityElement(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    return nums{nums.size()/2};
}

int main(){
    vector<int> v = {3,2,3};
    cout<<majorityElement(v);
    return 0;
}