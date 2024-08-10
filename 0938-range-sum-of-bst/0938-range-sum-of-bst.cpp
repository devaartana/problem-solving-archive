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

    void inorderTraversal(TreeNode* root, int low, int high, int &sum){
        if(!root) return;

        inorderTraversal(root->left, low, high, sum);
        if(root->val > high) return;
        else if(root->val >= low)sum += root->val;
        inorderTraversal(root->right, low, high, sum);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        inorderTraversal(root, low, high, sum);
        return sum;
    }
};