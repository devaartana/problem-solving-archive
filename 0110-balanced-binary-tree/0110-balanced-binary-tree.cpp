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

    int helper(TreeNode* root){
        if(!root) return 1;

        int right = helper(root->right);
        int left  = helper(root->left);

        if(!right || !left) return 0;
        
        right++; left++;

        if(abs(right - left) > 1) return 0;
        else return max(left, right);
        
    }

    bool isBalanced(TreeNode* root) {
        return helper(root) ? true : false;
    }
};