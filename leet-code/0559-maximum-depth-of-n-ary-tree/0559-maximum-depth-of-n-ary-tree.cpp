/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        int max = 0, temp;

        for(auto child:root->children){
            temp = maxDepth(child);

            if(temp > max) max = temp;
        }

        return max + 1;
    }
};