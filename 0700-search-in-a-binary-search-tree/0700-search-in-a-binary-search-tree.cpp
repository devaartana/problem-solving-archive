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
    TreeNode* searchBST(TreeNode* root, int val) {
        ios::sync_with_stdio(false);cin.tie(0);
        TreeNode* current = root;
        while(current != NULL){
            if(val > current->val){
                current = current->right;
            }else if(val < current->val){
                current = current->left;
            }else {
                return current;
            }
        }

        return NULL;
    }
};