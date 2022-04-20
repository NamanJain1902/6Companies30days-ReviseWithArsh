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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *rl = new ListNode(0);
        ListNode *head = rl;
        int carry = 0;
        while(carry || l1 || l2) {
            int num = l1->data + l2->data + carry;
            int base = num % 10;
            carry = num / 10;
            rl->next = new ListNode(base);
            rl = rl->next;
            
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        
    }
};