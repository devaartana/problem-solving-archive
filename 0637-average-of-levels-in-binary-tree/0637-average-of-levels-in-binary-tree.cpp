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
    
    vector<double> averageOfLevels(TreeNode* root) {
        unordered_map<int, double> sum;
        unordered_map<int, int> cnt;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()) {
            auto temp = q.front();
            q.pop();

            sum[temp.second] += temp.first->val;
            cnt[temp.second]++;

            if(temp.first->left) q.push({temp.first->left, temp.second+1});
            if(temp.first->right) q.push({temp.first->right, temp.second+1});
        }

        vector<double> ans(cnt.size());

        for(int i=0; i < cnt.size(); i++) {
            ans[i] = sum[i] / cnt[i];
        }

        return ans;
    }
};