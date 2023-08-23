// //medium

// class Solution {
// public:
//     string convert(string s, int numRows) {
//         int n = s.size();
//         if(n==1 || numRows ==1) return s;
//         vector < vector <char>> vect(numRows);
//         string ans;
//         int k=0;

//         while(k<n){
//             for(int i=0 ;i<numRows-1; i++){
//                 if(k<n) {
//                     vect[i].push_back(s[k]);
//                     k++;
//                 }
//                 else break;
//             }

//             for(int i=1 ;i<numRows; i++){
//                 if(k<n) {
//                     vect[numRows-i].push_back(s[k]);
//                     k++;
//                 }
//                 else break;
//             }
//         }
//         for(int i = 0; i<numRows; i++){
//             for(int j=0; j<vect[i].size(); j++){
//                 ans = ans + vect[i][j];
//             }
//         }

//         return ans;
//     }
// };


// class Solution {
// public:
//     string convert(string s, int numRows) {
//         int n = s.size();
//         if(n==1 || numRows ==1) return s;
//         vector <string> vect(numRows);
//         string ans;
//         int k=0;

//         while(k<n){
//             int i = 0;
//             while(k<n && i<numRows-1){
//                 vect[i++].push_back(s[k++]);
//             }
//             i=1;

//             while(k<n && i<numRows){
//                 vect[numRows-i++].push_back(s[k++]);
//             }
//         }

//         for(int i = 0; i<numRows; i++){
//             ans = ans + vect[i];
//         }

//         return ans;
//     }
// };



class Solution {
public:
    string convert(string s, int numRows) {
        string ans;
        int length=s.length();
        if(length==1 || numRows==1)return s;
        for(int i=0;i<numRows;i++)
        {
            if(i==0 || i==numRows-1)
            {
                for(int j=i;j<length;j+=2*numRows-2)ans.push_back(s[j]);
            }
            else
            {
                for(int j=i;j<length;j+=2*numRows-2)
                {
                   ans.push_back(s[j]);
                   if(j+2*numRows-2*i-2<length)ans.push_back(s[j+2*numRows-2*i-2]);
                }
            }
        }
        return ans;
    }
};