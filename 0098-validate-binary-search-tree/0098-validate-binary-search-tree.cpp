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
    vector<int>ans;
    void find(TreeNode* root){
        if(!root)return;
        find(root->left);
        ans.push_back(root->val);
        find(root->right);
    }
    bool isValidBST(TreeNode* root) {
        find(root);
         for (int i=0; i<ans.size()-1; i++) {
            if (ans[i] >= ans[i+1]) {
                return false;
            }
        }
        return true;
    }
};
