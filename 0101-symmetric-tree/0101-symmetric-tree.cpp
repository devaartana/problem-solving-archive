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

    bool sameTree(TreeNode* leftTree, TreeNode* rightTree){
        if((!leftTree && rightTree) || (leftTree && !rightTree)){
            return false;
        }

        if(!leftTree || !rightTree){
            return true;
        }

        return sameTree(leftTree->left, rightTree->right) && leftTree->val == rightTree->val && sameTree(leftTree->right, rightTree->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(!root){
            return NULL;
        }

        return sameTree(root->left, root->right);
        
    }
};