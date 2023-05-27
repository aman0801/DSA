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
    
    TreeNode* solve(TreeNode* root, vector<int>&res, int l, int h){
        if(l>h) return nullptr;
        int mid = l + ((h - l)/2);
        
        TreeNode* ans = new TreeNode(res[mid]);
        ans->left = solve(root, res, l, mid-1);
        ans->right = solve(root, res, mid+1, h);
        return ans;
        
    }
    
    void insert(TreeNode* root, vector<int>&res){
        if(root == NULL){
            return;
        }
        
         insert(root->left, res);
         res.push_back(root->val);
         insert(root->right, res);
        
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>res;
        insert(root, res);
        return solve(root, res, 0, res.size()-1);
    }
};