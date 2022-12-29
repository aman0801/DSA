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
    TreeNode* minVal(TreeNode* root){
        TreeNode* temp = root;
        while(temp->right!=NULL){
            temp = temp->right;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)return root;
        
        if(root->val == key){
            //0child
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            //1child
            if(root->left != NULL && root->right == NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            if(root->left == NULL && root->right != NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            //2child
             if (root->left && root->right) {
                TreeNode *tmp = root->right;
                while (tmp->left) {
                    tmp = tmp->left;
                }
                root->val = tmp->val;
                root->right = deleteNode(root->right, root->val);
            }
        }else if(root->val > key){
            root->left = deleteNode(root->left, key);
            // return root;
        }
        else{
            {
            root->right = deleteNode(root->right, key);
            // return root;
        }
        }
        return root;
    }
};
