//easy

class Solution {
public:
    string removeDuplicates(string s) {
        stack <char> st;
        for(int i=0; i<s.size(); i++){
            if(st.empty() || st.top()!=s[i]){
                st.push(s[i]);
            }
            else st.pop();
        }
        s="";
        while(!st.empty()){
            s=st.top()+s;
            st.pop();
        }
        return s;
    }
};






class Solution {
public:
    string removeDuplicates(string s) {

        //string in place of stack
         string result;
    for (char ch : s) {
        if (!result.empty() && ch == result.back()) {
            result.pop_back(); 
        } else {
            result.push_back(ch);
        }
    }
    return result;
    }