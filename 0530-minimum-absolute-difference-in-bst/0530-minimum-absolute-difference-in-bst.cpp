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
    vector<int>nums;
    void solve(TreeNode* node) {
        if (!node) {
            return;
        }
        
        solve(node->left);
        
        nums.push_back(node->val);
        
        solve(node->right);
    }
    int getMinimumDifference(TreeNode* root) {
        solve(root);
        sort(nums.begin(),nums.end());

        int min=INT_MAX;

        for(int i=nums.size()-1;i>0;i--){

            if(nums[i]-nums[i-1]<min){

                min=abs(nums[i]-nums[i-1]);}}

        return min;

    }
};