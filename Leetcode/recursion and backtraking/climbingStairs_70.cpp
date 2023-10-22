// class Solution {
// //4-> 4/2=2;;;; 

// //6->222 2211 2112 21111 1122 11211 11112 111111 1221 
// // 11112  
// //divide-> solve individually-> multiply-> still some cases left;

// //b!/(a!*c!) b =n-i,  
// double permute(int total, int twos, int ones){

//     if(twos==0 || total==0 || ones==0) return 1;
//     double num = 1;
//     double deno = 1;

//     for(int i=total; i>ones; i--) num=num*i;
//     for(int i=1; i<=twos; i++) deno=deno*i;


//     return num/deno;
// }

// public:
//     int climbStairs(int n) {
//         int k = n/2;
//         int ans = 0;
//         for(int i=0; i<=k; i++){
//             ans = ans + permute(n-i, i, n-(2*i));
//         }

//         return ans;
        
//     }
// };






// int climbStairs(int n){
//     if(n==0 || n==1) return 1;

//     return climbStairs(n-1)+ climbStairs(n-2);
// }



class Solution {
public:
    int climbStairs(int n) { 
        vector<int> dp(n+1,-1);
        if(n==0 || n==1 || n==2)
           return n;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++)
           dp[i]=dp[i-1]+dp[i-2];
        return dp[n];
    }
};


