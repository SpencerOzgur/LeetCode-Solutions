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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0){return nullptr;}

        while (lists.size() > 1){
            vector<ListNode*> mergedLists;

            for (int i = 0; i < lists.size(); i += 2){
                ListNode* l1 = lists[i];
                ListNode* l2 = (i + 1 < lists.size()) ? lists[i + 1] : nullptr;
                mergedLists.push_back(mergeLists(l1, l2));
            }
            lists = mergedLists;
        }
        return lists[0];
    }

    ListNode* mergeLists(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;

        while (l1 != nullptr && l2 != nullptr){
            if (l1->val < l2->val){
                tail->next = l1;
                l1 = l1->next;
                tail = tail->next;
            }

            else{
                tail->next = l2;
                l2 = l2->next;
                tail = tail->next;
            }
        }

        while(l1 != nullptr){
            tail->next = l1;
            l1 = l1->next;
            tail = tail->next;
        }

        while(l2 != nullptr){
            tail->next = l2;
            l2 = l2->next;
            tail = tail->next;
        }

        return dummy->next;
    }
};
