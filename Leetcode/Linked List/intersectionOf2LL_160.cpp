//EASY



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tempA, *tempB;
        int diff=0;
        tempA=headA;
        tempB=headB;
        

        while(tempA->next!=NULL && tempB->next!=NULL){
            tempA=tempA->next;
            tempB=tempB->next;
        }
        

        if(tempA->next!=NULL){
            while(tempA->next!=NULL){
                tempA=tempA->next;
                diff++;
            }
            tempA=headA;
            while(diff--){
                tempA=tempA->next;
            }
            tempB=headB; 
        }
        else if(tempB->next!=NULL){
            while(tempB->next!=NULL){
                tempB=tempB->next;
                diff++;
            }
            tempB=headB;
            while(diff--){
                tempB=tempB->next;
            }
            tempA=headA;
            
        }
        else{
            tempA=headA;
            tempB=headB;
        }
        
        while(tempA!=tempB){
            if(tempA==NULL || tempB==NULL) return 0;
            tempA=tempA->next;
            tempB=tempB->next;
            
        }
        return tempA;     
    }
};