//medium
class Solution {
public:
    int compress(vector<char>& chars) {

        if(chars.size()==1) return 1;

        vector <char> cp;
        cp.push_back(chars[0]);
        int count=1;

        for(int i = 1; i<chars.size(); i++){
            if(cp[cp.size()-1]==chars[i]) {
                count++;
                continue;
            }

            if(count>1){
                string s = to_string(count);
                for (char c : s) {
                    cp.push_back(c);
                }
                count = 1;
            }
            cp.push_back(chars[i]);            
        }

        if(count>1){
                string s = to_string(count);
                for (char c : s) {
                    cp.push_back(c);
                }
            }
        // for(int i=0; i<cp.size();i++){
        //     cout<<cp[i];
        // }

        chars=cp;

        return cp.size();


        
    }
};