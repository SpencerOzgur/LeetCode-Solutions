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
        ListNode* temp = head;
        int N = 0;

        while(temp != nullptr){
            N++;
            temp = temp->next;
        }

        if(n == N){return head->next;}
        temp = head;
        int i = 0;

        while(true){
            if (i == N - n - 1){
                temp->next = temp->next->next;
                return head;
            }
            i++;
            temp = temp->next;
        }        

        return nullptr;
    }
};
