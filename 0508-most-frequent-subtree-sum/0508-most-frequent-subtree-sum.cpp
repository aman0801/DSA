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
        unordered_map<int, int>mp;
        int freq = -1;
    int getmost(TreeNode* root){
        if(root == NULL)return 0;
        
        int sum = root->val + getmost(root->left) + getmost(root->right);
        // cout<<sum;
        mp[sum]++;
        freq = max(freq, mp[sum]);
        
        return sum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        getmost(root);
        vector<int> ans;
        for (auto p : mp) {
            if (p.second == freq) ans.push_back(p.first);
        }
        return ans;
    }
};