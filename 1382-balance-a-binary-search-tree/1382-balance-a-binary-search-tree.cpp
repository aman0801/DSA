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
    void find(TreeNode* root, vector<int> &arr)
    {
        if(!root) return;
        find(root->left,arr);
        arr.push_back(root->val);
        find(root->right,arr);        
    }
    TreeNode* ans(int s, int e, vector<int>&arr){
        if(s>e)return NULL;
        int mid = (s+e)/2;
        
        TreeNode* node = new TreeNode(arr[mid]);
        node->left = ans(s, mid-1, arr);
        node->right = ans(mid+1, e, arr);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>arr;
        find(root, arr);
        for(int i=0;i<arr.size();i++){
            cout<<arr[i];
        }
        return ans(0, arr.size()-1, arr);
        
    }
};