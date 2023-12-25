//medium
class Solution {
public:
    stack <char> st;
    bool check(stack <char> &st){
        if(st.empty()) return false;
        while(!st.empty()){
            if(st.top()=='c'){
                st.pop();
                while(!st.empty() && st.top()!='b'){
                    if(!check(st)) return false;
                    continue;
                }
                if(!st.empty() && st.top()=='b'){
                    st.pop();
                    while(!st.empty() && st.top()!='a'){
                        if(!check(st)) return false;
                        continue;
                    }
                    if(!st.empty() && st.top()=='a'){
                        st.pop();
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
    bool isValid(string s) {
        for(int i=0; i<size(s); i++){
            st.push(s[i]);
        }
        bool a;
        a = check(st);
        while(!st.empty() && a){
            a=check(st);}
        return a;
    }
};