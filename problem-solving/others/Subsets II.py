# https://practice.geeksforgeeks.org/problems/subsets/0/
# https://leetcode.com/problems/subsets-ii/
# A. https://leetcode.com/problems/subsets/discuss/712883/simple-python-solution-with-backtracking-78-subsets-90-subsets-ii
# A. https://www.youtube.com/watch?v=0ElTC4XiDvc

arr = {1,2,2}

def subsetsWithDup(nums):

    def backtrack(nums,idx,path):
        if path not in result:
            result.append(path{:})
        for i in range(idx,len(nums)):
            path.append(nums{i})
            backtrack(nums,i+1,path)
            path.pop()

    nums.sort()
    result = {}
    backtrack(nums,0,{})
    return result

print(subsetsWithDup(arr))