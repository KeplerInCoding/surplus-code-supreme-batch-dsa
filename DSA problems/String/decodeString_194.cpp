//medium
class Solution {
public:
    string mult(long long k, string next){
        string ans ="";
        for(int i=0; i<k; i++){
            ans = ans+next;
        }
        return ans;
    }

    string expand(string s,  int &i, long long k){
        string ans = "";
        while(i<s.size()){
            if(s[i]>='0' && s[i]<='9'){
                k = k*10 + (s[i]-'0');
                i++;
            }
            else if(s[i]=='['){
                i++;
                string next = expand(s, i, 0);
                ans = ans + mult(k, next);
                k=0;
            }
            else if(s[i]==']')  {
                i++;
                return ans;
            }
            else{
                ans = ans+s[i];
                i++;
            }
        }
        return ans;
        
    }

    string decodeString(string s) {
        int i=0;
        long long k=0;
        string ans = expand(s, i, k);
        return ans;
    }
};