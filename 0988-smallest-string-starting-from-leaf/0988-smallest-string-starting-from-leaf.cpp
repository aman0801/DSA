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
        
    void solve(TreeNode* root, vector<string>& arr, string tmp){
            if(root == NULL){
                    return;
            }
            tmp.push_back('a'+root->val);
            if(root->left==NULL && root->right==NULL){
                    reverse(begin(tmp), end(tmp));
                    arr.push_back(tmp);
                    return;
            }
            solve(root->left, arr, tmp);
            solve(root->right, arr, tmp);
    }    
        
    string smallestFromLeaf(TreeNode* root) {
            vector<string>arr;
            string tmp;
            solve(root, arr, tmp);
            sort(begin(arr), end(arr));
            return arr[0];
    }
};