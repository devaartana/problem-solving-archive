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
    unordered_set<int> ust;

    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;

        bool left = findTarget(root->left, k);

        if(ust.find(k - root->val) != ust.end()) return true;
        ust.insert(root->val);

        bool right = findTarget(root->right, k);
  
        return left || right;  
    }
};