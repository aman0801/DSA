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
    
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int inst, int inend, int& poidx){
        if(inst>inend || poidx<0){
            return NULL;
        }
        
        int ele = postorder[poidx--];
        TreeNode* ans = new TreeNode(ele);
        int pos = -1;
        for(int i=0; i<inorder.size(); i++){
            if(ele == inorder[i]){
                pos = i;
                break;
            }
        }
        
        ans->right = solve(inorder, postorder, pos+1, inend, poidx);
        ans->left = solve(inorder, postorder, inst, pos-1, poidx);
        return ans;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int inst = 0;
        int inend = inorder.size()-1;
        int poidx = postorder.size()-1;
        
        return solve(inorder, postorder, inst, inend, poidx);
    }
};