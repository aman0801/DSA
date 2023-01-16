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
  TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
    map<int, TreeNode*> mp;
    for (auto it : descriptions) {
      TreeNode* parentNode, * childNode;
      if (mp.find(it[0]) != mp.end()) {
        parentNode = mp[it[0]];
      }
      else {
        parentNode = new TreeNode(it[0]);
        mp[it[0]] = parentNode;
      }


      if (mp.find(it[1]) != mp.end()) {
        childNode = mp[it[1]];
      }
      else {
        childNode = new TreeNode(it[1]);
        mp[it[1]] = childNode;
      }

 
      if (it[2] == 1) {
        parentNode->left = childNode;
      }
      else {
        parentNode->right = childNode;
      }
    }


    map<int, int> storeChild;
    for (auto it : descriptions) {
      storeChild[it[1]] = 1;
    }

    TreeNode* root;
    for (auto it : descriptions) {
      if (storeChild.find(it[0]) == storeChild.end()) {
        root = mp[it[0]];
      }
    }
    return root;
  }
};