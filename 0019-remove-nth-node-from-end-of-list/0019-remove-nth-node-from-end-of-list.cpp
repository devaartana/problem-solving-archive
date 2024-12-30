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

    pair<ListNode*, int> helper(ListNode* head, int n) {
        if(!head) return make_pair(head, 1);

        pair<ListNode*, int> result = helper(head->next, n);

        head->next = result.first;

        result.first = (result.second == n) ? head->next : head;
        result.second++;
        return result;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return helper(head, n).first;
    }
};