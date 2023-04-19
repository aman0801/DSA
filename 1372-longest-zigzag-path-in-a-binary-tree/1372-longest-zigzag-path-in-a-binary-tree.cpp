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
    
    int maxPath = 0;
    
    void find(TreeNode* root, int steps, bool goL){
        if(root == NULL){
            return;
        }
        maxPath = max(steps, maxPath);
        if(goL == true){
            find(root->left, steps+1, false);
            find(root->right, 1, true);
        }else{
            find(root->right, steps+1, true);
            find(root->left, 1, false);
        }
        
    }
    
    int longestZigZag(TreeNode* root) {
        bool goL = true;
        int steps = 0;
        find(root, steps, goL);
        
        return maxPath;
        
    }
};