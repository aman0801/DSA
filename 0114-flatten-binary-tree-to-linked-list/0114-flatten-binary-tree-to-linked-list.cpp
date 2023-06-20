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
    
    vector<TreeNode*>ans;
    
    void solve(TreeNode* root){
        if(root == NULL){
            return;
        }
        ans.push_back(root);
        solve(root->left);
        // ans.push_back(root);
        solve(root->right);
    }
    
    void flatten(TreeNode* root) {
        
        if(root==nullptr)
            return;
        
        solve(root);
        TreeNode* temp = nullptr;
        TreeNode* temp2=root;
        root=ans[0];
        
        for(int i=1;i<ans.size();i++)
        {
            root->right=ans[i];
            root->left=nullptr;
            root=root->right;
        }      
        
    }
};