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
    TreeNode *ans = nullptr;

    void inOrderTraversal(TreeNode* root){
        if(!root) return;

        inOrderTraversal(root->right);
        
        TreeNode *node = new TreeNode(root->val);
        node->right = ans;
        ans = node;

        inOrderTraversal(root->left);
    }

    TreeNode* increasingBST(TreeNode* root) {
        inOrderTraversal(root);

        return ans;
    }
};