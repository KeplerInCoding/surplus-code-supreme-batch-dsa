//easy
class Solution {
public:
    string reverseVowels(string s) {
        int start =0; 
        int end = s.size()-1;
        vector <char> v = {'a','e','i','o','u'};

        while(start<end){
            char p = s[start];
            char q = s[end];
            vector<char>::iterator it1;
            vector<char>::iterator it2;
            it1 = find(v.begin(), v.end(), tolower(p));
            it2 = find(v.begin(), v.end(), tolower(q));
            if(it1 != v.end() && it2 != v.end()) {
                s[start]=q;
                s[end]=p;
                start++;
                end--;
            }
            else if(it1==v.end()) start++;
            else end--;
        }

        return s;
    }
};