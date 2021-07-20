//https://leetcode.com/problems/search-insert-position/

#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size() - 1;
    
    while (l<=r){
        int mid = (l+ r) / 2;
        if (target == nums{mid})
            return mid;
        if (target >= nums{mid})
            l = mid + 1;
        else 
            r = mid - 1;
    }
        return l;
}

int main(){
    vector<int> nums = {1,3,5,6};
    cout<<searchInsert(nums,2);
    return 0;
}