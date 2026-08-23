/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> oldToNew = {
            {nullptr, nullptr}
        };

        Node* temp = head;
        while (temp != nullptr){
            Node* newNode = new Node(temp->val);
            oldToNew[temp] = newNode;
            temp = temp->next;
        }

        temp = head;
        while (temp != nullptr){
            oldToNew[temp]->next = oldToNew[temp->next];
            oldToNew[temp]->random = oldToNew[temp->random];
            temp = temp->next;
        }

        return oldToNew[head];
    }
};
