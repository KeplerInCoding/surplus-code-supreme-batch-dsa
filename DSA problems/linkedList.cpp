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

class linkedList{
  Node* head;

  public:
  linkedList()
  {
    head = NULL;
  }

  void insert(int data);
  void insertAtPos(int data, int pos);
  void deletePos(int pos);
  void print();

};

void linkedList::insert(int data){
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

void linkedList::print(){
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

void linkedList::insertAtPos(int data, int pos){
  if(pos<0) return;
  int count = 2;
  Node* temp = head;
  Node* newNode = new Node(data);

  if(pos == 1){
    newNode->next = head;
    head = newNode;
    return;
  }

  while(count!=pos && temp!=NULL){
    temp = temp->next;
    count++;
  }

  if(temp==NULL){
    cout<<"Positions doesn't exists."<<endl;
    return;
  }
  newNode->next = temp->next;
  temp->next = newNode;

}

void linkedList::deletePos(int pos){
  if(head==NULL){
    cout<<"The list is empty."<<endl;
    return;
  }

  Node* temp = head;

  if(pos==1){
    head = head->next;
    delete temp;
    return;
  }

  Node* temp1 = head;
  int count = 1;

  while(temp!=NULL && count!=pos){
    temp1=temp;
    temp=temp->next;
    count++;
  }

  if(temp==NULL){
    cout<<"Invalid position"<<endl;
    return;
  }
  temp1->next = temp->next;
  delete temp;
}

int main() {

  linkedList list;

  list.print();
  list.insert(10);
  list.insert(20);
  list.insert(30);
  list.insert(40);

  // list.insertAtPos(5, 1);
  // list.insertAtPos(50, 6);
  // list.insertAtPos(60, 3);

  list.deletePos(4);
  list.print();
  

  return 0;
}