class Solution {
public:
    int countPrimes(int n) {
        if(n<=1) return 0;
        vector <int> v(n,1);
        v[0]=0;
        v[1]=0;

        int k=2;
        int c=0;
        while(k*k < n){
            if(v[k]!=0){
                c++;
                for(int i=k*k; i < n; i=i+k){
                    v[i]=0;
                }
            }
            k++;
        }

        for(int i=k; i < n; i++){
            if(v[i]!=0)c++;
        }

        return c;    
    }
};