//medium
class Solution {
public:
    stack <string> s;
    string dot = "";
    int flag=0;
    string simplifyPath(string path) {
        
        string dir="";
        for(int i=0; i<size(path); i++){
            if(path[i]=='.' && flag){
                while(i<size(path) && path[i]=='.'){
                    dot+=".";
                    i++;
                }
                if(i<size(path) && path[i]!='/'){
                    dir=dot;
                    i--;
                }
                
                else{
                    i--;
                    if(size(dot)>2){
                        s.push(dot);
                        flag=0;
                    }
                    else{
                        if(size(dot)==2 && !s.empty()){
                            s.pop();
                        }
                    }
                }
                dot="";
            }
            else if(path[i]=='/'){
                flag=1;
                if(dir!="") {
                    s.push(dir);
                    dir="";
                }
            }
            else{
                flag=0;
                dir+=path[i];
            }
        }
        if(dir!="")s.push(dir);
        string p = "";
        while(!s.empty()){
            p='/'+s.top()+p;
            s.pop();
        }
        if(p==""){
             p="/";
        }
        
        return p;
    }
};