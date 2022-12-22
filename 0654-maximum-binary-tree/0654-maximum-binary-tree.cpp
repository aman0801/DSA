/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* ans(vector<int>&nums, int left, int right){
        if(left > right)return NULL;
        int Max = INT_MIN;
        int ind = 0;
        for(int i=left;i<=right;i++){
            if(nums[i] > Max){
                Max = nums[i];
                ind = i;
            }
        }
        
        TreeNode* solve = new TreeNode(Max);
        solve->left = ans(nums, left, ind-1);
        solve->right = ans(nums, ind+1, right);
        return solve;
        
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        return ans(nums, 0, n-1);
    }
};