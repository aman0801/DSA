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
    
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int inst, int inend, int& preidx){
        if(preidx > preorder.size() || inst>inend){
            return NULL;
        }
        
        int ele = preorder[preidx++];
        TreeNode* ans = new TreeNode(ele);
         // int found = search(ele, inorder);
        int pos;
          for (int i=0; i< inorder.size(); i++){            
               if (ele == inorder[i]){   
                   pos= i;
                   break; 
               }
          }
        TreeNode* left = solve(preorder, inorder, inst, pos - 1, preidx);
        TreeNode* right = solve(preorder, inorder, pos + 1, inend, preidx);
        
        ans->left = left;
        ans->right = right;
        return ans;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int inst = 0;
        int inend = inorder.size()-1;
        int preidx = 0;
        return solve(preorder, inorder, inst, inend, preidx);
    }
};