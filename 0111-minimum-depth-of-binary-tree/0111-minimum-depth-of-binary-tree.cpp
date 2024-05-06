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

    int min(int a, int b){
        return (a < b)? a : b;
    }


    int minDepth(TreeNode* root) {
        if(!root){
            return 0;
        }

        int left = minDepth(root->left), right = minDepth(root->right);

        if(!left && !right){
            return 1;
        }else if(!left && right || !right && left){
            return 1 +( (!left) ? right : left);
        }

        return 1 + min(minDepth(root->left), minDepth(root->right));
    }

};