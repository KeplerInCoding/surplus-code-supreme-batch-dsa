//medium
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    // your code here
    if(s.size()%2 || !s.size()) return -1;
    stack <char> st;
    int ans=0;
    int m=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='{'){
            if(m<=(s.size()-i-1)){
                st.push(s[i]);
                m++;
            }
            else{
                s[i]='}';
                st.pop();
                m--;
                ans++;
            }
            
        }
        else{
            if(st.empty()) {
                s[i]='{';
                st.push(s[i]);
                m++;
                ans++;
            }
            else{
                st.pop();
                m--;
            }
            
        }
    }
    return ans;
}