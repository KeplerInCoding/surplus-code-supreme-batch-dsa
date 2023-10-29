//hard

//TLE

// class Solution {
// public:

//     int findMax(vector <int>& ht, bool &flag, int &h){
//         int len = 0;
//         int maxH = 0;
//         for(int i=0; i<ht.size(); i++){
//             if(ht[i]>=h) len = len+h;
//             else{
//                 maxH = max(maxH, len);
//                 len = 0;
//             } 
//         }
//         maxH = max(maxH, len);
//         if(maxH==0){
//             flag = false;
            
//         }
//         return maxH;
//     }

//     int largestRectangleArea(vector<int>& ht) {
//         int maxi = 0;
//         bool flag = true;
//         int i=1;
//         while(flag){
//             maxi=max(maxi, findMax(ht, flag, i));
//             i++;
//         }
        
//         return maxi;
//     }
// };



class Solution {
public:

    vector <int> setPrevSmaller(vector <int>& ht){
        stack <int> st;
        vector <int> ans(ht.size());
        st.push(-1);
        // cout<<"done prev entry"<<endl;

        for(int i = 0; i<ht.size(); i++){
        // cout<<"ht[i] : "<<ht[i]<<endl;

            int curr =ht[i];
            while(st.top()!=-1 && curr<=ht[st.top()]){
                st.pop();
            }
            ans[i] = st.top();
            // cout<<"ans [i]  : "<<ans[i]<<endl;
            st.push(i);
        }
        // cout<<"done prev"<<endl;

        return ans;
    } 

    vector <int> setNextSmaller(vector <int>& ht){
        stack <int> st;
        vector <int> ans(ht.size());
        st.push(-1);
        
        for(int i = ht.size()-1; i>= 0; i--){
            int curr =ht[i];
            while(st.top()!=-1 && curr<=ht[st.top()]){
                st.pop();
            }
            ans[i] = st.top();
            if(ans[i]==-1) ans[i]=ht.size();
        
            
            st.push(i);
        }
        return ans;
    }


    int largestRectangleArea(vector<int>& ht) {
        vector <int> prevSmaller;
        vector <int> nextSmaller;
        // cout<<"done entry"<<endl;

        prevSmaller = setPrevSmaller(ht);
        nextSmaller = setNextSmaller(ht);
        // cout<<"done both"<<endl;
        int maxH = 0, width, area;
        for(int i=0; i<ht.size(); i++){
            width = nextSmaller[i]-prevSmaller[i]-1;
            area = ht[i]*width;
            // cout<<"ht wd : "<<ht[i]<<" "<<width<<endl;
            maxH = max(maxH, area);
        }
        // cout << maxH;
        return maxH;
    }
};