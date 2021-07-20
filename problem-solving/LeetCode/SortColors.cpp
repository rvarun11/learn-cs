//

#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
    // use counting sort
    
    int zeroes=0,ones=0,twos=0;
    for(int i=0;i<nums.size();i++){
        if (nums{i}==0) zeroes++;
        if (nums{i}==1) ones++;
        if (nums{i}==2) twos++;
    }
    for (int i=0;i<nums.size();i++){
        if (i<zeroes) nums{i}=0;
        else if (i>=zeroes && i<ones) nums{i}=1;
        else if (i>=ones && i<twos) nums{i}=2;
    }
}

int main(){
    vector<int> nums = {2,0,2,1,1,0};
    sortColors(nums);
    for (int i=0;i<nums.size();i++)
        cout << nums{i} << " ";
    return 0;
}