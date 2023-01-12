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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return partitionAndResolve(0, preorder.size()-1, preorder);
    }

private:
    TreeNode* partitionAndResolve(int low, int high, vector<int>& preorder) {
        if (low > high) return nullptr;

        int pivot = findPivot(low, high, preorder);
        TreeNode* root = new TreeNode(preorder[low]);
        root->left = partitionAndResolve(low + 1, pivot, preorder);
        root->right = partitionAndResolve(pivot + 1, high, preorder);

        return root;
    }

    int findPivot(int low, int high, vector<int>& preorder) {
        int element = preorder[low];
        low++;
        while (low <= high && element >= preorder[low]) {
            low++;
        }
        return low - 1;
    }
};
