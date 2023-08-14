
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int l = timePoints.size();

        int m = INT_MAX;
        vector <int> t;

        for(int i=0 ; i< l; i++){
            string s = timePoints[i];
            int min = stoi(s.substr(3,2));
            int hour = stoi(s.substr(0,2));

            int time = min + 60*hour;
            t.push_back(time);
        }

        sort(t.begin(), t.end());


        for(int i=0 ; i< l-1; i++){
            m = min(t[i+1]-t[i],m);
        }

        int last = t[0]-t[l-1]+1440;
        m = min(last,m);
        return m;
        
    }
};