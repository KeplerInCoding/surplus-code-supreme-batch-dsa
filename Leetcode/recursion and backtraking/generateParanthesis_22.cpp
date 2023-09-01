//medium
class Solution {
    void generator(vector <string>& V, string output, int open, int close ){
        cout<<output<<endl;
        if(open==0 && close==0) {
            V.push_back(output);
            return;
        }

        //open
        if(open>0){
            generator(V, output+"(", open-1, close);
        }
        //close
        if(close>open){
            generator(V, output+")", open, close-1);
        }
    }



public:
    vector<string> generateParenthesis(int n) {
        vector <string> V;
        int open = n, close = n;
        string output ="";
        generator(V, output, open, close);

        return V;

    }
};