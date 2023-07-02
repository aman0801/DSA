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
    
    int height(TreeNode* root){ 
        if(root == NULL){
            return 0;
        }
        
        return 1 + max(height(root->left), height(root->right));
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        
        int Lh = height(root->left);
        int Rh = height(root->right);
        
        int diff = abs(Lh-Rh);
        bool ans;
        if(diff<=1){
            ans = true;
        }else{
            ans = false;
        }
        
        bool La = isBalanced(root->left);
        bool Ra = isBalanced(root->right);
        
        if(ans && La && Ra){
            return true;
        }else{
            return false;
        }
        
    }
};