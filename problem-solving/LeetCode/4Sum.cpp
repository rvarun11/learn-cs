// https://leetcode.com/problems/4sum/
// https://www.youtube.com/watch?v=4ggF3tXIAp0

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    if (nums.empty()) return ans;
    
    int n = nums.size();
    sort(nums.begin(),nums.end());

    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            int partial_sum = target - nums{i} - nums{j};
            int front = j+1;
            int back = n-1;

            while (front<back){
                int two_sum = nums{front} + nums{back};

                if (two_sum < partial_sum) front++;
                else if (two_sum > partial_sum) back--;
                else {  
                    vector<int> quad(4,0);
                    quad{0} = nums{i};
                    quad{1} = nums{j};
                    quad{2} = nums{front};
                    quad{3} = nums{back};
                    ans.push_back(quad);

                    while (front<back && nums{front}==quad{2}) ++front;
                    while (front<back && nums{back}==quad{3}) --back;
                }   
            }
            while (j+1<n && nums{j}==nums{j+1}) ++j;
        }
        while (i+1<n && nums{i}==nums{i+1}) ++i;
    }
    return ans;
}

int main(){
    vector<int> v = {-3,-2,-1,0,0,1,2,3};
    vector<vector<int>> ans = fourSum(v,0);
    return 0;
}