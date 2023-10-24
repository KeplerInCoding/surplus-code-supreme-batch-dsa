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

    ListNode* findMid(ListNode* head){
        ListNode *fast=head, *slow=head;
        while(fast->next && fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }


    ListNode* merge(ListNode* left, ListNode* right){
        if(!left) return right;
        if(!right) return left;

        ListNode *link=NULL;
        ListNode *head=NULL;

        if(left->val<=right->val){
            link = left;
            left = left->next;
        }
        else{
            link = right;
            right = right->next;
        }

        head=link;
        
        while(left && right){
            if(left->val<=right->val){
                link->next = left;
                left = left->next;
            }
            else{
                link->next = right;
                right = right->next;
            }
            link = link->next;

        }

        while(left){
            link->next = left;
            left = left->next;
            link = link->next;
        }

        while(right){
            link->next = right;
            link = link->next;
            right = right->next;
        }

        link->next = NULL;

        return head;
    }

    


    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        //get mid and split
        ListNode *mid = findMid(head);
        ListNode *left = head;
        ListNode *right = mid->next;
        mid->next = NULL;

        //sort left-right
        left = sortList(left);
        right = sortList(right);


        //merge left-right
        head = merge(left, right);

        return head;
        
    }
};