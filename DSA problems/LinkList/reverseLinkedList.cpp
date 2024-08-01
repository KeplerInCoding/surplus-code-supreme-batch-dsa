#include <iostream>
using namespace std;

class Node
{
  public:
  int data;
  Node* next;

  Node()
  {
    this->data = 0;
    this -> next = NULL;
  }
  Node(int data)
  {
    this->data = data;
    this->next = NULL;
  }

};

void insert(Node* &head, int data){
  Node* newNode = new Node(data);
  if(head==NULL) {
    head = newNode;
    return;
  }
  Node* temp = head;

  while(temp->next!=NULL){
    temp = temp->next;
  }

  temp->next = newNode;

}

void print(Node* &head){
  Node* temp = head;
  if(head==NULL){
    cout<<"List is empty."<<endl;
    return;
  }

  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  cout<<endl;
}



void reverseList(Node* &head){
  
  if(head==NULL || head->next==NULL) return;

  Node* current, *right;
  Node* prev = head;

  current = prev->next;
  prev->next = NULL;

  while(current!=NULL){
    right = current->next;
    current->next = prev;
    prev = current;
    current = right;
  }

  head = prev;
}

void findMidNode(Node* &head){

  if(head==NULL) return;

  Node* slow = head;
  Node* fast = head;

  while(fast->next!=NULL){
    fast = fast->next;
    if(fast->next==NULL) break;
    fast = fast->next;
    slow = slow->next;
  }
  if(slow!=NULL)
  cout<<slow->data<<endl;
}

Node* reverseKnodes(Node* &head, int k){

  //base case
  int count = 1;
  if(head==NULL || head->next==NULL)return head;

  Node* temp = head;
  // cout<<"head : "<<head->data<<endl;
  // cout<<"k : "<<k<<endl;


  while(count<k && temp->next!=NULL){
  // cout<<"in base case loop, temp and count : "<<temp->data<<" "<<count<<endl;

    temp=temp->next;
    count++;   
  }  

  // cout<<"count : "<<count<<endl;


  if(count!=k) return head;


//solve one case
  count = 1;
  temp = head;
  Node* current = temp->next;
  Node* right;

  while(count!=k){
    right = current->next;
    current->next = temp;
    temp = current;
    current = right;
    count++;
    // cout<<"in loop, temp : "<<temp->data<<endl;

  }

  //recursion
  head->next = reverseKnodes(current, k);

  // cout<<"returning head : "<<temp->data<<endl;


  return temp;

}

int main() {

  Node* head;

  insert(head, 10);
  insert(head, 20);
  insert(head, 30);
  insert(head, 40);
  insert(head, 50);
  insert(head, 60);
  insert(head, 70);
  // insert(head, 30);
  // insert(head, 40);
  // insert(head, 50);

  // print(head);

  // reverseList(head);
  print(head);

  head = reverseKnodes(head, 4);
  print(head);

  // findMidNode(head);
  return 0;
}