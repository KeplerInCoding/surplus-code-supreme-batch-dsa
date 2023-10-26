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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector <int> a{-1, -1};
        int minDist = INT_MAX, maxDist=0;
        int mintrack=-1, maxtrack=0;
        ListNode *temp = head;
        while(temp->next->next){
            int pre = temp->val;
            int curr = temp->next->val;
            int nxt = temp->next->next->val;
            if((curr>pre && curr>nxt) || (curr<pre && curr<nxt)){
                //critical
                if(mintrack!=-1){
                    minDist = min(minDist, mintrack);
                    maxDist = max(maxtrack, maxDist);
                }
                mintrack = 0;
            }
            //not critical
            // cout<<"curr : "<< curr<<" "<<"  max : "<<maxtrack<<"  min : "<< mintrack<<endl;
            temp=temp->next;
            if(mintrack!=-1){
                mintrack++;
                maxtrack++;
            }
        }
        if(minDist==INT_MAX) return a;
        a[0]=minDist;
        a[1]=maxDist;
        return a;

        
    }
};