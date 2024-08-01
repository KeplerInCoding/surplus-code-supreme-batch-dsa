// //permutation string
// #include <iostream>
// #include <string>
// using namespace std;

// //abc -> 3*2*1 = 6

// void permute(string s, string ans){
//   //base case 
//   if(s.size()==0) {
//     cout<<ans<<endl;
    
//     return;
//   }

  

//   //solve one case
//   for(int i=0; i<s.size(); i++){
//     string Ans = ans;
//     Ans = Ans+s[i];

//     //replace, erase, substring-> to remove part of string
//     string part = s;
//     part.erase(i,1);
//     permute(part, Ans);
//   }
// }
 
// int main(){
//   string s = "ahgc";
//   string ans = "";
//   cout<<"the permutations are: "<<endl;
//   permute(s, ans);

//   return 0;
// }



#include <iostream>
using namespace std;
void printPermutation(string &str, int i) {
  //base case
  if(i >= str.length()) {
    cout << str << " ";
    return;
  }

//swapping
  for(int j=i; j<str.length(); j++) {
    //swap
    swap(str[i], str[j]);
    //rec call
    printPermutation(str, i+1);
    //backtracking - to recreate the original input string
    swap(str[i], str[j]);
  }

}
int main() {
  string str = "abc";
  int i = 0;
  printPermutation(str,i);
  return 0;
}