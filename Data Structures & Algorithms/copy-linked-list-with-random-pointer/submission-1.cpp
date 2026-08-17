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
        //first i will create all of the copy nodes and put them in a map where original -> copy

        if(head == nullptr) { return head; }
        map<Node*, Node*> nodeMap;
        Node* copyHead = new Node(head->val);
        nodeMap.insert({head, copyHead});

        Node* curr = head->next;
        Node* copyCurr = copyHead;
        while(curr != nullptr) {
            copyCurr->next = new Node(curr->val);
            copyCurr = copyCurr->next;
            nodeMap.insert({curr, copyCurr});
            curr = curr->next;

        }

        //now that we have all the original->copy pairs in our map, and our deep copy established with the correct next nodes, we need to establish the random nodes in our new list.
        curr = head;
        copyCurr = copyHead;
        while(curr != nullptr) {
            //find the original random in the list which will return the copied random then connect it in the copied list
            copyCurr->random = nodeMap[curr->random];
            curr = curr->next;
            copyCurr = copyCurr->next;
        }
        return copyHead;
    }
};
