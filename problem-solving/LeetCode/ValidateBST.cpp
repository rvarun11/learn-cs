// https://leetcode.com/problems/validate-binary-search-tree/
// https://www.youtube.com/watch?v=TKvbwPIOGCM
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
};

bool isValidBST(TreeNode* root) {
    long int minVal = LONG_MIN;
    long int maxVal = LONG_MAX;
    if (!root) return true;
    if (helper(root->left,minVal,root->val) && helper(root->right,root->val,maxVal)) return true;
    return false;
}

bool helper(TreeNode* root, long int minVal, long int maxVal){
    if (!root) return true;

    if (root->val > minVal && root->val < maxVal)
        return helper(root->left,minVal,root->val) && helper(root->right,root->val,maxVal);
    
    return false;
}

int main(){

    return 0;
}