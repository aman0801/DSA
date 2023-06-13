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
    
    vector<int>arr;
    
    void solve(TreeNode* root){
        if(root == NULL){
            return;
        }
        solve(root->left);
        arr.push_back(root->val);
        solve(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        solve(root);
        TreeNode*temp = new TreeNode(arr[0]);
        TreeNode*ans = temp;
        for(int i=1; i<arr.size(); i++){
            temp->right = new TreeNode(arr[i]);
            temp = temp->right;
        }
        return ans;
    }
};
