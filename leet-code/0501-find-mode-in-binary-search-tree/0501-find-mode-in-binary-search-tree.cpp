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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> freq;
        int maxFreq = 0;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            auto temp = q.front();
            q.pop();

            freq[temp->val]++;
            if(freq[temp->val] > maxFreq) maxFreq = freq[temp->val];

            if(temp->right) q.push(temp->right);
            if(temp->left) q.push(temp->left);
        }

        vector<int> ans;
        for(auto it = freq.begin(); it != freq.end(); it++){
            if(it->second == maxFreq) ans.push_back(it->first);
        }

        return ans;
    }
};