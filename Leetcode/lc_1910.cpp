///remove-all-occurrences-of-a-substring



class Solution {
public:
    string removeOccurrences(string s, string part) {
        int len = part.length();
        int Len = s.length();
        if(len==0 || Len==0) return "";
        while(Len>=len){
            int index = s.find(part);
            if(index!=string::npos){
                s.erase(index, len);
            }
            else return s;
        }
        return s;
    }
};