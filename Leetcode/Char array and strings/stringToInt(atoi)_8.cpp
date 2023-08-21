//meduim
class Solution {
public:
    int myAtoi(string s) {
        double ans = 0;
        int sign = 1, i=0, n = s.size();

        while(i<n && s[i]==' ' ) i++;

        if(s[i]=='-' || s[i]=='+'){
            if(s[i]=='-') sign = -1;
            i++;
        }

        while(i<n && isdigit(s[i])){
            ans = ans*10 + (s[i]-'0');
            i++;
        }

        if((ans*sign) <= INT_MIN) return INT_MIN;
        if(ans>INT_MAX) return INT_MAX;

        return ans*sign;
    }
};