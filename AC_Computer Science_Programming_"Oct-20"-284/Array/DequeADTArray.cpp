//
// Created by snowflake3509 on 29/10/20.
//
#include "DequeADTArray.h"

using namespace std;



template<typename E>
DequeADTArray<E>::DequeADTArray(int size) {

    front = -1;
    rear = 0;
    this->size = size;
}

template<typename E>
DequeADTArray<E>::~DequeADTArray() {

}

template<typename E>
void DequeADTArray<E>::insertFront(const E &e) {

    if(isFull()){
        cout<<"Deque is Full"<<endl;
        return;
    }
    //queue is empty initially
    if(front==-1)
    {
        front = 0;
        rear = 0;
    }
    else if (front==0)
    {
        front = size-1;
    }
    else
    {
        front = front-1;
    }
    arr[front] = e;
    size++;
}

template<typename E>
void DequeADTArray<E>::insertBack(const E &e) {

    if(isFull())
    {
        cout<<"Deque is Full"<<endl;
        return;
    }
    //if queue is empty initially
    if(front==-1){
        front = 0;
        rear=0;
    } else if(rear == size-1) {
        rear=0;
    } else{
      rear = rear+1;
    }
    arr[rear] = e;
    size++;
}

template<typename E>
const E &DequeADTArray<E>::eraseFront() {
    if(isEmpty())
    {
        cout<<"Deque is Empty"<<endl;

    }
    const E& temp = arr[front];
    if(front ==rear)
    {
        front = -1;
        rear = -1;
    } else {
        if(front == size-1)
        {
            front=0;
        }
        else{
            front = front+1;
        }
    }
    size--;
    return temp;
}

template<typename E>
const E &DequeADTArray<E>::eraseBack() {

    if(isEmpty())
    {
        cout<<"Deque is Empty"<<endl;
    }
    E temp = arr[rear];
    if(front == rear){
        front = -1;
        rear = -1;
    }
    else if(rear == 0)
    {
        rear = size-1;
    }
    else{
        rear = rear-1;
    }
    size--;
    return temp;
}


template<typename E>
bool DequeADTArray<E>::isFull() const {
    return ((front==0&&rear==size-1)||front==rear+1);
}

template<typename E>
bool DequeADTArray<E>::isEmpty() const {
    return (front==-1);
}

template<typename E>
int DequeADTArray<E>::sizeOfDeque() const {
    return this->size;
}

template<typename E>
const E &DequeADTArray<E>::frontOfDeque() const {

    if(isEmpty())
    {
        cout<<"Deque is Empty"<<endl;
        return -1;
    }
    return arr[front];
}

template<typename E>
const E &DequeADTArray<E>::backOfDeque() const {

    if(isEmpty()||rear<0)
    {
        cout<<"Deque is Empty"<<endl;
        return -1;
    }
    return arr[rear];
}

template <typename E>
void DequeADTArray<E>::Display(){

    if(!isEmpty())
    {
        int size = sizeOfDeque();
        for(int i=0;i<size;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    cout<<"Deque is Empty"<<endl;
}
// push to push element at top of stack
// using insert at last function of deque
template<typename E>
void DequeADTArray<E>:: push(const E &element)
{
    insertBack(element);
}

// pop to remove element at top of stack
// using remove at last function of deque
template<typename E>
void DequeADTArray<E>::pop()
{
    eraseBack();
}

template<typename E>
void DequeADTArray<E>::deque() {
    eraseFront();
}

template<typename E>
void DequeADTArray<E>::enqueue(const E &e) {
    insertBack(e);
}

template<typename E>
DequeADTArray<E>::DequeADTArray() {
    front = rear = NULL;
    size=0;
}

int main(){
//    template<typename E>, I have choosen Integer type data.
    DequeADTArray<int> dq;
    cout << "Insert element '5' at rear end\n";
    dq.insertBack(5);

    cout << "Insert element '10' at rear end\n";
    dq.insertBack(10);

    cout << "Rear end element: "
         << dq.backOfDeque() << endl;

    dq.eraseBack();
    cout << "After deleting rear element new rear"
         << " is: " << dq.backOfDeque() << endl;

    cout << "Inserting element '15' at front end \n";
    dq.insertFront(15);

    cout << "Front end element: "
         << dq.frontOfDeque() << endl;

    cout << "Number of elements in Deque: "
         << dq.sizeOfDeque() << endl;

    dq.eraseFront();
    cout << "After deleting front element new "
         << "front is: " << dq.frontOfDeque() << endl;

    cout<<"#####################################################"<<endl;

    cout<<"Implementing the Stack using LinkedList and Deque"<<endl;
    DequeADTArray<int> stack;
    // push 7 and 8 at top of stack
    stack.push(7);
    stack.push(8);
    cout << "Stack: ";
    stack.Display();

    // pop an element
    stack.pop();
    cout << "Stack: ";
    stack.Display();
    cout<<"Successfully implemented Stack "<<endl;

    cout<<"#####################################################"<<endl;

    // object of Queue
    cout<<"Implementing the Queue using LinkedList and Deque"<<endl;
    DequeADTArray<int> que;

    // insert 12 and 13 in queue
    que.enqueue(12);
    que.enqueue(13);
    que.enqueue(16);
    que.enqueue(84);
    cout << "Queue: ";
    que.Display();
    // delete an element from queue
    que.deque();
    cout << "Queue: ";
    que.Display();
    cout<<"Successfully implemented Queue "<<endl;
    cout<<"#####################################################"<<endl;

    return 0;
}

