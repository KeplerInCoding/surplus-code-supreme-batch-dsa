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

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector <vector<int>> v;
        for(int i=0; i<m; i++){
            vector <int> t;
            for(int j=0; j<n; j++){
                t.push_back(matrix[i][j]-'0');
            }
            v.push_back(t);
        }
        
        int area = largestRectangleArea(v[0]);
        for(int i=1; i<m; i++){
            for(int j=0; j<n; j++){
                if(v[i][j]) v[i][j]=v[i-1][j]+v[i][j];
                else v[i][j]=0;
            }
            area=max(area, largestRectangleArea(v[i]));
        }
        return area;
    }
};