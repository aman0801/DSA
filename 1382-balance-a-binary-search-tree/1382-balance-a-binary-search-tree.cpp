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
// vector<int>ans;

class Solution {
public:
   void helper(TreeNode* root, vector<int>&ans){
     if(!root) 
            return; 
    helper(root->left, ans);
    ans.push_back(root->val);
    helper(root->right, ans);
}
    TreeNode* insert(vector<int>&ans,int s, int e){
        if(s>e)return NULL;
        int m = (s+e)/2;
        // TreeNode* node = ans[m];
        TreeNode* node = new TreeNode(ans[m]);

        node->left = insert(ans,s, m - 1);
        node->right = insert(ans,m + 1, e);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>ans;
        helper(root, ans);
        return insert(ans,0, ans.size()-1);
    }
};

