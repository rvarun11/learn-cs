void backtrack(vector<int>& nums,int idx,vector<int>& path,vector<vector<int>>& res){
    res.push_back(path);

    for (int i=idx;i < nums.size();i++){
        if (i>idx && nums[i]==nums[i-1])
            continue;
        path.push_back(nums[i]);
        backtrack(nums,i+1,path,res);
        path.pop_back();
    }
}
