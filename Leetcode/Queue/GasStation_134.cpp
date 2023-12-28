//medium

class Solution {
public:

    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int deficient = 0;
        int balance = 0;
        int start = 0;
        for(int i=0; i<gas.size(); i++){
            balance += gas[i]-cost[i];
            if(balance<0){
                deficient += abs(balance);
                balance = 0;
                start = i+1;
            }
        }
        if(deficient<=balance){
            return start;
        }
        return -1;
    }

};