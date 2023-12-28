//hard
class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector <double> answer(n,-1);
        stack <int> st;

        for(int i=n-1; i>=0; i--){

            int s1 = cars[i][1], s2=0;
            float p1 = cars[i][0], p2=0;
            
            while(!st.empty() && cars[st.top()][1]>=s1){
                st.pop();
            }
            while(!st.empty()){
                s2=cars[st.top()][1];
                p2 = cars[st.top()][0];
                double colTime = (double)(p2-p1)/(s1-s2);
                if(answer[st.top()]==-1 || colTime <= answer[st.top()]){
                    answer[i]=colTime;
                    break;
                }
                st.pop();
            }
            st.push(i);

        } 
        return answer;           
    }
};