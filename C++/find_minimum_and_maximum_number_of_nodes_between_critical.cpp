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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* cur = head->next;
        ListNode* prev = head;
        int i = 1;
        vector<int> vec;
        vector<int> res;
        int minDist = INT_MAX;

        while(cur != nullptr && cur->next != nullptr){
            if ((cur->val > cur->next->val && cur->val > prev->val) || (cur->val < cur->next->val && cur->val < prev->val)){
                if (!vec.empty() && minDist > i - vec[vec.size() - 1]){minDist = i - vec[vec.size() - 1];}
                vec.push_back(i);
            }
            i++;
            prev = cur;
            cur = cur->next;
        }

        if (vec.size() > 1){
            res.push_back(minDist);
            res.push_back(vec[vec.size() - 1] - vec[0]);
        }
        else{
            res.push_back(-1);
            res.push_back(-1);
        }

        return res;
    }
};
