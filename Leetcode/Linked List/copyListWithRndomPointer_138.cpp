//medium

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

        if(!head) return head;
        map <Node*, Node*> mp;
        Node* temp = head;
        Node* head1 = new Node(head->val);
        Node* temp1 = head1;
        while(temp){
            if(temp!=head) {
                Node* newNode = new Node(temp->val);
                temp1->next = newNode;
                temp1 = temp1->next;
            }
            mp[temp]=temp1;
            temp=temp->next;
        }

        temp = head;
        temp1 = head1;
        while(temp){
            temp1->random = mp[temp->random];
            temp = temp->next;
            temp1 = temp1->next;
        }

        return head1;
        
    }
};