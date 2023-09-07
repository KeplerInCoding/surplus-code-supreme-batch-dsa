#include <iostream>
using namespace std;

class Stack{
  private:     ///public bhi kr skte, but pvt better
  int *arr;
  int top;
  int size;

  public:
  Stack(int size)
  {
    this->size = size;
    arr = new int[size];
    top = -1;
  }

  void push(int data);
  void pop();
  void peek();
  bool isEmpty();

};

void Stack::push(int data){
  if(top==size-1) {
    cout<< "Stack is full"<<endl;
    return;
  }
  arr[++top]=data;
}

void Stack::pop(){
  if(top==-1) {
    cout<< "Stack is empty"<<endl;
    return;
  }
  top--;
}

void Stack::peek(){
  if(top==-1) {
    cout<< "Stack is empty"<<endl;
    return;
  }
  cout<<arr[top]<<endl;
}

bool Stack::isEmpty(){
  if(top==-1) return true;
  return false;
}


int main() {
  Stack stack(5);
  stack.pop();

  while(!stack.isEmpty()){
    stack.peek();
    stack.pop();
  }
  return 0;
}