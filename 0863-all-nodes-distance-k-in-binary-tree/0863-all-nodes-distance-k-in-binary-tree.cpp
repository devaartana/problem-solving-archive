/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, bool> visited;
    unordered_map<TreeNode*, TreeNode*> parent;

    void traverse(TreeNode* root, TreeNode *target){
        if(root == NULL || root == target) return;
        
        if(root->left){
            parent[root->left] = root; 
        }

        if(root->right){
            parent[root->right] = root; 
        }

        traverse(root->left, target);
        traverse(root->right, target);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        traverse(root, target);
        TreeNode *current = target;
        parent[root] = NULL;

        queue<pair<TreeNode*,int>> q;
        while(current != NULL && k >= 0){
            q.push({current, k--});
            visited[current] = true;
            current = parent[current];
        }

        vector<int> result;
        while(!q.empty()){
            auto temp = q.front();
            TreeNode *current = temp.first;
            q.pop();

            if(temp.second == 0){
                result.push_back(current->val);
                continue;
            }
        
            if(current->left && !visited[current->left]){
                q.push({current->left, temp.second - 1});    
                visited[current->left] = true;
            }

            if(current->right && !visited[current->right]){
                q.push({current->right, temp.second - 1});    
                visited[current->right] = true;
            }
        }

        return result;
    }
};