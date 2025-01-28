class Solution {
public:
    Node* cloneGraph(Node* node) {

        std::unordered_map<Node*, Node*> visited;
        std::queue<Node*> q;
        if (node)
            q.push(node);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (visited.find(temp) == visited.end()) {
                visited[temp] = new Node(temp->val);
            }

            for (Node* neighbor : temp->neighbors) {
                if (visited.find(neighbor) == visited.end()) {
                    visited[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                visited[temp]->neighbors.push_back(visited[neighbor]);
            }
        }

        return visited[node];
    }
};
