// https://leetcode.com/problems/longest-increasing-subsequence/
// https://www.youtube.com/watch?v=KoenMWrZmZU
// MUST WATCH: https://www.youtube.com/watch?v=TocJOW6vx_I


#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;
// const lli mod = 1e9 + 7;

int lengthOfLIS(vector<int>& nums){
	
	/* O(n^2) Solution: In this method we store the longest subseq len at each index i. for eg. for i=0, memo{0} = 1.
	int len = nums.size();
	vector<int> memo(len,1);
	for (int i=0;i<len;i++){
		for (int j=0;j<i;j++){
			if (nums{j} < nums{i})
				memo{i} = max(memo{i},1+memo{i});
		}
	}
	return *max_element(memo.begin(),memo.end());
	*/

	// O(nlogn) Solution: Watch the above video.
	// In this approach the length of any subsequence is stored at its index so the largest possible subsequence is the size of our subseq array. 

	vector<int> subseq;

	subseq.push_back(nums{0});
	
	for(int i=1;i<nums.size();i++){
		if (subseq.back()<nums{i})
			subseq.push_back(nums{i});
		else{
			int index = lower_bound(subseq.begin(),subseq.end(),nums{i}) - subseq.begin(); 
			subseq{index} = nums{i};
		}
	}
	return subseq.size();
}

int main(){
	return 0;
}
