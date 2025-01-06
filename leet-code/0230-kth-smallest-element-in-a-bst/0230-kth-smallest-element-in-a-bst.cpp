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
    int count = 0;
  
    int helper(TreeNode* root, int k) {
        if(++count == k) return root->val;
        return 0;
    }

    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;

        return kthSmallest(root->left, k) + helper(root, k) + kthSmallest(root->right, k);
    }

};