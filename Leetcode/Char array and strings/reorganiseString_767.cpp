// //medium

// class Solution {
//     #include <string>
// public:
//     string reorganizeString(string s) {
//         int hash[256] = {0};

//         for(int i = 0; i<s.size(); i++){
//             hash[s[i]]++;
//         }

//         int max = 0;
//         for(int i = 0; i<s.size(); i++){
//             if(hash[s[max]]<hash[s[i]]) max = i;
//             if(hash[s[i]] >((s.size()+1)/2)) return "";
//         }

//         string k = "";
//         for(int i = 0; i<hash[s[max]]; i++){
//             k=k+s[max];
//         }

//         int q=1;
//         for(int i = 0; i<256; i++){
            
//             if(hash[i]>0 && i!= s[max]){
//                 cout<<k;
//                 string t(1, char(i));
//                 for(int j = 0; j<hash[i]; j++){
//                     k.insert(q, t);
//                     q=q+2;
//                     if(q>k.size()) q = 1;
//                 }
//             }

            
//         }

        

//     return k;
        
//     }
// };


class Solution {
    #include <string>
public:
    string reorganizeString(string s) {
        int hash[26] = {0};

        for(int i = 0; i<s.size(); i++){
            hash[s[i]-'a']++;
        }

        int max = 0;
        for(int i = 0; i<26; i++){
            if(hash[i]>hash[max]) max = i;
        }

        int i=0;

        while(hash[max]>0 && i<s.size()){
            s[i]=char(max +'a');
            hash[max]--;
            i=i+2;
        }

        if(hash[max]>0) return "";

        for(int j=0; j<26; j++){
            while(hash[j]>0){
                if(i>=s.size()) i=1;
                s[i] = char(j+'a');
                hash[j]--;
                i=i+2;
                
            }
        }

    return s;
        
    }
};