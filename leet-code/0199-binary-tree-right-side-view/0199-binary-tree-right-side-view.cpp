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

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans = {};

        queue<pair<TreeNode*, int>> q;
        if(root) q.push({root, 1});

        int currentLevel = 0;
        while(!q.empty()){
            auto temp = q.front();
            q.pop();

            if(currentLevel != temp.second) {
                ans.push_back(temp.first->val);
                currentLevel++;
            }

            if(temp.first->right) q.push({temp.first->right, temp.second + 1});
            if(temp.first->left) q.push({temp.first->left, temp.second + 1});
        }

        return ans;
    }
};