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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root){
            return {};
        }

        vector<int> concatenated;
        
        vector<int> left = postorderTraversal(root->left);

        for(auto i = left.begin(); i != left.end();  i++){
            concatenated.push_back(*i);
        }

        vector<int> right = postorderTraversal(root->right);
        
        for(auto i = right.begin(); i != right.end();  i++){
            concatenated.push_back(*i);
        }

        concatenated.push_back(root->val);

        return concatenated;
    }
};