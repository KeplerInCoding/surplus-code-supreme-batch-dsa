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

    void getMax(ListNode* temp, vector <int> &ans, stack <int> &st, int k){
        //base case
        if(!temp->next) {
            ans.push_back(0);
            st.push(temp->val);
            return;
        }

        //recursive case
        ans.push_back(-1);
        getMax(temp->next, ans, st, k+1);
        while(st.top()!=0 && st.top()<=temp->val){
            st.pop();
        }
        ans[k]=st.top();
        st.push(temp->val);

    }

    vector<int> nextLargerNodes(ListNode* head) {
        vector <int> ans;
        stack <int> st;
        int k=0;
        st.push(0);
        getMax(head, ans, st, k);
        return ans;
        
    }
};