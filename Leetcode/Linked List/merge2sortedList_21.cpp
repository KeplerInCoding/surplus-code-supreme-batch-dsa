//easy

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list2) return list1; 
        if(!list1) return list2; 
        ListNode *x1, *y1, *x2, *y2;
        x1=list1;
        x2=list2;

        y1=list1;
        y2=list2;


        while(x1 && x2){
            if(x1->val<x2->val){
                y1=x1;
                x1=x1->next;
                y1->next=x2;
                if(y2!=x2) {
                    y2->next=y1;
                    
                }
                y2=y1;
                y1=x1;
            }
            else{
                y2=x2;
                x2=x2->next;
                y2->next=x1;
                if(y1!=x1) {
                    y1->next=y2;
                    
                }
                y1=y2;
                y2=x2;
                
            }
            
        }

        if(list1->val<list2->val) return list1;
        return list2;
    }
};