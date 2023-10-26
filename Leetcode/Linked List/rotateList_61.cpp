//medium

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!k || !head) return head;
        ListNode* temp = head;
        int n = 0;
        while(temp){
            n++;
            temp = temp->next;
        

        }
        if(k>=n) k=k%n;
        if(k==0 || n==1) return head;

        temp = head;
        n=n-k;


        while(n>1){
            temp=temp->next;
            n=n-1;
        }


        ListNode* temp2 = temp->next;
        ListNode* newHead = temp->next;
        temp->next=NULL;

        while(temp2->next){
            temp2 = temp2->next;
        }
        temp2->next=head;

        return newHead;
        
    }
};