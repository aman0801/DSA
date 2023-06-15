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
    
//     // int ans = 0;
//     // int maxi = INT_MIN;
//     void solve(TreeNode* root){
//         if(root == NULL){
//             return;
//         }
//         int sum = 0;
//         int lvl = 0;
//         // int sumAtCurrentLevel = 0;
//         queue<TreeNode*>q;
//         q.push(root);
//         sum = sum + root->val;
//         while(q.empty() == false){
//           lvl++;
//             TreeNode* node = q.front();
        
//             q.pop();
 
//             if (node->left != NULL)
//             q.push(node->left);
//             // sum = sum + node->left->val;
        
//             if (node->right != NULL)
//             q.push(node->right);
//             // sum = sum + node->right->val;
            
//         }
        
//         if(sum > maxi){
//             maxi = sum;
//             ans = lvl;
//         }
        
//     }
    
    int maxLevelSum(TreeNode* root) {
 queue<TreeNode*> q;
    q.push(root);
    int level = 0;
    int store = INT_MIN;
    int res = 0;
    
    while(!q.empty())
    {
        int size = q.size();
        int sum = 0;
        level++;
        
        for(int i = 0; i < size; i++)
        {
            TreeNode* curr = q.front();
            q.pop();
            
            sum = sum + curr->val;
            
            if(curr->left)
                q.push(curr->left);
            
            if(curr->right)
                q.push(curr->right);
            
            
        }
        
        if(sum > store)
        {
            store = sum;
            res = level;
        }
        
    }
    
    return res;
    }
};