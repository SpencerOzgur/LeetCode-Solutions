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
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        int carry = 0;

        while(l1 != nullptr or l2 != nullptr or carry != 0){
            int l1Val = (l1 != nullptr) ? l1->val : 0;
            int l2Val = (l2 != nullptr) ? l2->val : 0;

            int newDig = (l1Val + l2Val + carry) % 10;
            carry = (l1Val + l2Val + carry) / 10;

            ListNode* newNode = new ListNode(newDig);
            temp->next = newNode;
            temp = temp->next;
            
            if (l1 != nullptr){
                l1 = l1->next;
            }

            if (l2 != nullptr){
                l2 = l2->next;
            }
        }

        return dummy->next;
    }
};
