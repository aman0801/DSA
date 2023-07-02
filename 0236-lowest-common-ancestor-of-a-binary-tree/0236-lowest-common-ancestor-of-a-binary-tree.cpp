class Solution {
public:
    bool path(TreeNode* root, vector<TreeNode*>& Path, TreeNode* target) {
        if (root == NULL) {
            return false;
        }
        
        Path.push_back(root);
        if (root == target) {
            return true;
        }
        
        if (path(root->left, Path, target) || path(root->right, Path, target)) {
            return true;
        }
        
        Path.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;
        
        if (!path(root, path1, p) || !path(root, path2, q)) {
            return NULL;
        }
        
        TreeNode* ans = NULL;
        for (int i = 0; i < path1.size() && i < path2.size(); i++) {
            if (path1[i] == path2[i]) {
                ans = path2[i];
            }
        }
        return ans;
    }
};
