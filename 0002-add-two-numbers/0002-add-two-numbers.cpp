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
        if(!l1 && !l2) {
            if(carry) return new ListNode(carry);
            else return nullptr;
        }

        
        int sum;
        if(l1 && l2)sum = l1->val + l2->val;
        else if(l1) sum = l1->val;
        else if(l2) sum = l2->val;
        

        ListNode *newNode = new ListNode((sum + carry) %10);
    
        if(l1 && l2)newNode->next = recursive(l1->next, l2->next, sum + carry  > 9);
        else if(l1) newNode->next = recursive(l1->next, l2, sum + carry > 9);
        else if(l2) newNode->next = recursive(l1, l2->next, sum + carry  > 9);

        return newNode;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return recursive(l1, l2, false);
    }
};