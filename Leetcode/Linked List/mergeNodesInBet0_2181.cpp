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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *ptr = head, *temp = head;
        int sum = -1;
        while(temp){
            if(!temp->val){
                if(sum==-1) {
                    sum = 0;
                    ptr = temp;
                }
                else if(ptr->val == 0){
                    temp->val = sum;
                    head = temp;
                    ptr = temp;
                    sum = 0;
                }
                else{
                    temp->val = sum;
                    ptr->next = temp;
                    ptr = temp;
                    sum = 0;
                }

            }
            else{
                sum = sum + temp->val;
            }
            
            temp = temp->next;
        }
        return head;
        
    }
};