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

    void helper(TreeNode *node, vector<string> &ans, string path){
        if(!node->right && !node->left) {
            ans.push_back(path);
        }

        if(node->right) helper(node->right, ans, path + "->" + to_string(node->right->val));
        if(node->left) helper(node->left, ans, path + "->" + to_string(node->left->val));
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        helper(root, ans, to_string(root->val));

        return ans;
    }
};