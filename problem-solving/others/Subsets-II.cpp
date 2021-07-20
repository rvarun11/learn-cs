#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void backtrack(vector<int>& nums,int idx,vector<int>& path,vector<vector<int>>& res){
    res.push_back(path);

    for (int i=idx;i < nums.size();i++){
        if (i>idx && nums{i}==nums{i-1})
            continue;
        path.push_back(nums{i});
        backtrack(nums,i+1,path,res);
        path.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums){
    sort(nums.begin(),nums.end());
    vector<vector<int>> res;
    vector<int> path;
    backtrack(nums,0,path,res);
    return res;

}


int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(2);
    subsetsWithDup(arr);
    for (int i=0;i<arr.size();i++)
        cout << arr.at(i) << " ";
    return 0;
} 