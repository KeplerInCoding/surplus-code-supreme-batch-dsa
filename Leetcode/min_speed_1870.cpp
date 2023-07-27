#include <vector>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;

    int isPossible(vector <int> dist, int trains, int speed, int hour){
        cout<<"hello3";

        int totalTime = 0;
        // cout<<speed;
        for(int i = 0; i<trains; i++){

            int t = dist[i]/speed %1==0? dist[i]/speed: dist[i]/speed+1;
            cout<<"t: "<<t<<"\n";
            totalTime = totalTime + t;
        }
        cout<<"test: "<<totalTime<<"\n";

        if(totalTime <= hour) return 1;
        return 0;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {

        cout<<"hello2"<<"\n";
        int trains = dist.size();
        if(trains==1) return dist[0]/hour;

        int d = 0;
        for(int i = 0; i<trains; i++ ){
            d = d + dist[i];
        }
        cout<<"dis: "<<d<<"\n";
        
        float maxSpeed = ceil(d/hour);

        int start = 0; 
        int end = maxSpeed;
        cout<<"end: "<<end<<"\n";

        int ans = -1;

        while (start<=end){
            int mid = (start+end)/2;
            cout<<"speed: "<<mid<<"\n";
            cout<<mid;
            if(mid==0) return 1;
            if(isPossible(dist, trains, mid, hour)){
                ans = mid;
                end = mid-1;
            }
            else start = mid+1;
        }

        return ans;
    }

    int main(){
        cout<<"hello";
        vector <int> dist{1,3,2};
        double hour = 2.7;
        cout<<minSpeedOnTime(dist, hour);
        return 0;
    }