class Solution {
    vector <vector <int>> markZone(int i, int j, vector <vector<int>> zone){
        //down
        if(zone.size()==1) return zone;
        for(int m=i+1; m<zone.size(); m++){
            zone[m][j]=1;
        }
        //slant left
        for(int m=i+1, k=j-1; m<zone.size() && k>=0; m++, k--){
            zone[m][k]=1;
        }
        //slant right
        for(int m=i+1, k=j+1; m<zone.size() && k<zone.size(); m++, k++){
            zone[m][k]=1;
        }
        return zone;
    }

    void Nqueen(int n, vector <vector <int>> zone, vector <string>& sol, int i, vector <vector <string>>& V){

        //base condition
        if(i==n) {
            V.push_back(sol);
            return;
        }

        //solve one case

        for(int j=0; j<n; j++){
            if(!zone[i][j]) {
                sol[i][j]='Q';
                //to unmark zones
                vector <vector <int>> Z = markZone(i, j, zone); 
                Nqueen(n, Z, sol, i+1, V);
                sol[i][j]='.';  //backtracking
            }

        }
        return;
    }
    
public:

    


    vector<vector<string>> solveNQueens(int n) {
        vector <vector <int>> zone(n, vector<int>(n, 0));
        string str(n, '.');
        vector <string> solution(n, str);
        vector <vector <string>> V;

        int i=0;


        Nqueen(n, zone, solution, i, V);

        return V;

        
    }
};