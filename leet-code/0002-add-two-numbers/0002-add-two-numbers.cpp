/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* recursive(ListNode* l1, ListNode* l2, bool carry) {
        if(!l1 && !l2 && !carry) return nullptr;

        int sum = carry;
        if(l1) sum += l1->val;
        if(l2) sum += l2->val;
        
        ListNode *newNode = new ListNode(sum % 10);
    
        ListNode *next1 = l1 ? l1->next : nullptr;
        ListNode *next2 = l2 ? l2->next : nullptr;

        newNode->next = recursive(next1, next2, sum / 10);
        
        return newNode;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return recursive(l1, l2, false);
    }
};