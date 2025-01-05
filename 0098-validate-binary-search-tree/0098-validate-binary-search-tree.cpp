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
    long long temp = LLONG_MIN;
  
    bool helper(int a) {
        bool ans = a > temp;
        temp = a;
        return ans;
    }

    bool isValidBST(TreeNode *root) {
        if(!root) return true;

        return isValidBST(root->left) && helper(root->val) && isValidBST(root->right);
    }
};