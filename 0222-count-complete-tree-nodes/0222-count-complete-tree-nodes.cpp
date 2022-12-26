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
    void ans(TreeNode* root, int &count){
        while(root == NULL)return;
        TreeNode* leftA = root;
        TreeNode* rightA = root;
        
        while(leftA){
            leftA = leftA->left;
            count++;
        }
        while(rightA){
            rightA = rightA->right;
            count++;
        }
    }
    int countNodes(TreeNode* root) {
        int count = 0;
        // ans(root, count);
        // return count;
        while(root == NULL)return 0;
        TreeNode* leftA = root;
        TreeNode* rightA = root;
        
        while(leftA){
            leftA = leftA->left;
            count++;
        }
        while(rightA){
            rightA = rightA->right;
            count++;
        }
        // if(hl==hr) return pow(2,hl)-1;

        return 1+countNodes(root->left)+countNodes(root->right);
    }
};