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
    int helper(TreeNode* root, int &sum){
        if(!root) return 0;

        int right = helper(root->right, sum);
        int left = helper(root->left, sum);

        sum += abs(right - left);        

        return root->val + right + left;
    }
    
    int findTilt(TreeNode* root) {
        int sum = 0;
        helper(root, sum);

        return sum;
    }
};