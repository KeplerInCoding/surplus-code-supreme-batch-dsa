//medium

class Solution {
public:


    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int ans = 1;
        int index[1000000]={-1};
        int n = position.size();
        vector <float> reach_time;

        

        for(int i=0; i<n; i++){
            float k = (float(target-position[i])/speed[i]);
            reach_time.push_back(k);
            index[position[i]]=i;
        }
        sort(position.begin(), position.end());
        // for(int i=0; i<n; i++){
        //     cout<<"p: "<<position[i]<<"  i : "<<index[position[i]]<<endl;
        //     // cout<<speed.size()<<" "<<i<<endl;
        // }

        int I = n-1;
        int i = index[position[I]];
        float t1 = reach_time[i];
        I--;

        while(I!=-1){

            int i = index[position[I]];
            float t2 = reach_time[i];

            if(t1>=t2){
                I--;
                continue;
            }
            else{
                I--;
                ans++;
                t1 = t2;
            }
        }

        return ans;
    }
};