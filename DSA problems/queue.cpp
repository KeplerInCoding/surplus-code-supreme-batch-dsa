#include <iostream>
using namespace std;

class Queue{
    public:
    int* arr;
    int front;
    int rear;
    int size;
    Queue(int size){
        arr = new int[size];
        front = -1;
        rear = -1;
        this->size = size;
    }

    void enqueue(int data);
    void dequeue();
    int getFront();
    bool isEmpty();
    int getSize();

};

void Queue::enqueue(int data){
    if(rear == size-1){
        cout << "Queue is full" << endl;
        return;
    }
    else{
        arr[++rear] = data;
        if(front == -1) front++;
    }
}

void Queue::dequeue(){
    if(rear == front-1 || front == -1){
        cout << "Queue is empty" << endl;
        return;
    }
    else{
        arr[front] = -1;
        front++;
        if(front-1==rear){
            front = -1;
            rear = -1;
        }
    }
}

int Queue::getFront(){
    if(rear == front-1 || front == -1){
        cout << "Q is empty"<< endl;
        return -1;
    }
    else{
        return arr[front];
    }
}

bool Queue::isEmpty(){
    if(rear == front-1 || front == -1){
        // cout << "Q is empty"<< endl;
        return true;
    }
    else{
        return false;
    }
}

int Queue::getSize(){
    return rear-front;
}

int main(){
    Queue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(5);
    q.enqueue(5);
    q.enqueue(5);

    while(!(q.isEmpty())){
        cout << q.getFront() << endl;
        q.dequeue();
    }

    cout<<q.getFront()<<endl;
    // cout<<q.getFront()<<endl;
    // q.dequeue();
    // cout<<q.getFront()<<endl;
    // q.dequeue();
    // cout<<q.getFront()<<endl;
    // q.dequeue();
    // cout<<q.getFront()<<endl;
    if(q.isEmpty()) cout<<"empty";
    else cout<<"not empty";

    return 0;
}