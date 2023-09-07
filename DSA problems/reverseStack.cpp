#include <iostream>
using namespace std;
#include <stack>

//50 
//20

void insertSorted(stack <int>& s, int temp){
  if(s.empty()) {
    s.push(temp);
    return;
  }

  if(s.top()<temp){
    int temp2=s.top();
    s.pop();
    insertSorted(s, temp);
    s.push(temp2);
  }
  else s.push(temp);
}

void reverseStack(stack <int>& s){
  if(s.empty()) return;
  
  int temp = s.top();
  s.pop();

  reverseStack(s);

  insertSorted(s, temp);

}

int main(){
  stack <int> s;
  s.push(50);
  s.push(20);
  s.push(30);
  s.push(10);
  s.push(500);
  s.push(90);

  reverseStack(s);

  while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
  }
  return 0;
}