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
    void findBottomLeftValue(TreeNode* root, int& maxDep, int dep, int& Val){
        if(root == NULL)return;
        findBottomLeftValue(root->left, maxDep, dep+1, Val);
        findBottomLeftValue(root->right, maxDep, dep+1, Val);
        
        if(dep > maxDep){
             maxDep = dep;
            Val = root->val;
        }
        
    }
    int findBottomLeftValue(TreeNode* root) {
        int maxDep = 0;
        int Val = root->val;
        findBottomLeftValue(root, maxDep, 0, Val);
        return Val;
    }
};
