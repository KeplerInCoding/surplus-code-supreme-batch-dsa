//medium
class Solution {

    void letters(string digits, map <char, string> m, string str, vector<string>& V){
        //base case
        if(!digits.size()) {
            V.push_back(str);
            return;
        } 

        //recursion condn
        string current = m[digits[0]];
        for(int i=0; i<current.size(); i++){
            letters(digits.substr(1, digits.size()-1), m, str+current[i], V);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        map <char, string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";

        vector<string> V;
        string str = "";

        letters(digits, m, str, V);

        return V;
        
    }
};