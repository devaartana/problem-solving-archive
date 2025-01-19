/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return nullptr;

        std::unordered_map<Node*, Node*> ump;
        Node *ans = new Node(head->val), *tempCP = ans, *tempOG = head;
        ump[tempOG] = ans;

        tempOG = tempOG->next;
        while (tempOG) {
            Node* newNode = new Node(tempOG->val);
            ump[tempOG] = newNode;
            tempCP->next = newNode;

            tempOG = tempOG->next;
            tempCP = newNode;
        }

        tempCP = ans;
        tempOG = head;

        while (tempCP) {
            tempCP->random = ump[tempOG->random];

            tempCP = tempCP->next;
            tempOG = tempOG->next;
        }

        return ans;
    }
};
