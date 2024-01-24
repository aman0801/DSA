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
    int ans = 0;
        
    void solve(TreeNode* root, vector<int>& arr){
            if(root == NULL){
                    return;
            }
            arr[root->val]++;
            
            if(root->left == NULL && root->right == NULL){
                    int odd = 0;
                    for(int i=0; i<=9; i++){
                            if(arr[i]%2 == 1){
                                    odd++;
                            }
                    }
                    if(odd<=1){
                            ans++;
                    }
            }
            solve(root->left, arr);
            solve(root->right, arr);
            arr[root->val]--;
    }    
        
    int pseudoPalindromicPaths (TreeNode* root) {
            vector<int>arr(10, 0);
            solve(root, arr);
            return ans;
    }
};