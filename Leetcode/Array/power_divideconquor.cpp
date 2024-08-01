//gfg potd beats 100% user in cpp


class Solution {
public:
    double myPow(double x, int n) {
        double prod = 1;
        if(x==1 || n==0) return 1;
        if(n==1) return x;
        if(n==-1) return 1/x;
        if(n%2==0) {
            double r = myPow(x, n/2);
            prod = r*r;
        }
        else {
            double r = myPow(x, (n-1)/2);
            if(n==-1) prod = r*r/x;
            else prod = r*r*x;
        }
        return prod;
    }
};