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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int N = 0;
        ListNode* temp = head;

        while(temp != nullptr){
            N++;
            temp = temp->next;
        }

        int i = 0;
        temp = head;
        if (N == n){return head->next;}

        while(true){
            if (i == N - n - 1){
                temp->next = temp->next->next;
                return head;
            }

            i++;
            temp = temp->next;
        }
    }
};
