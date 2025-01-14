class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* temp = reverseList(head->next);

        head->next->next = head;
        head->next = nullptr;

        return temp;
    }

    void mergeList(ListNode* node1, ListNode* node2) {
        while (node1 && node2) {
            ListNode *temp1 = node1->next, *temp2 = node2->next;

            node1->next = node2;
            node2->next = temp1;

            node2 = temp2;
            node1 = temp1;
        }
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        
        ListNode *slowPointer = head, *fastPointer = head;

        while (fastPointer && fastPointer->next) {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
        }

        ListNode *reversed = reverseList(slowPointer->next);
        slowPointer->next = nullptr;

        mergeList(head, reversed);
    }
};
