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
    void find(TreeNode* root, int targetSum, int y, vector<vector<int>>&ans, vector<int>&path){
        if(root == NULL)return;
        y = y+root->val;
         path.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(y == targetSum){
            ans.push_back(path);
            }
        }else{
            find(root->left, targetSum, y, ans, path);
            find(root->right, targetSum, y, ans, path);
        }
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        // int y = 0;
        vector<vector<int>>ans;
        vector<int>path;
        // ans.clear();
        find(root, targetSum, 0, ans, path);
        return ans;
    }
};
