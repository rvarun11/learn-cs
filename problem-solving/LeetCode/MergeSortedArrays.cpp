//https://leetcode.com/problems/merge-sorted-array/

#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //Only for sorted arrays.
    int i = m-1;
    int j = n-1;

    for (int k=n+m-1;k>=0;k--){
        if (j<0) break;

        if (i>=0 && nums1{i}>nums2{j}){
            nums1{k} = nums1{i};
            i--;
        }
        else{
            nums1{k} = nums2{j};
            j--;
        }
    }
}

int main(){
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    merge(nums1,3,nums2,3);
    for (auto i: nums1){
        cout<<i<<" ";
    }
    return 0;
}