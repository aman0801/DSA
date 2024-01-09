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
        
    void solve(TreeNode* root, vector<int>& tree){
            if(root == NULL){
                    return;
            }
            if(root->left == NULL && root->right == NULL){
                    tree.push_back(root->val);
            }
            solve(root->left, tree);
            solve(root->right, tree);
    }    
        
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
            vector<int>tree1, tree2;
            solve(root1, tree1);
            solve(root2, tree2);
            return tree1 == tree2;
    }
};