//
// Created by snowflake3509 on 29/10/20.
//
#include<iostream>
#include "DequeADTList.h"
using namespace std;

template<typename E>
DequeADTList<E>::DequeADTList() {
    front = rear = nullptr;
    Size = 0;
}

template<typename E>
DequeADTList<E>::~DequeADTList(){
    rear = NULL;
    while (front != NULL)
    {
        dequeNode* temp = front;
        front = front->next;
        free(temp);
    }
    Size = 0;
}

template<typename E>
void DequeADTList<E>::insertFront(const E &data) {

    dequeNode* newNode = dequeNode::getnode(data);
    // If true then new element cannot be added
    // and it is an 'Overflow' condition
    if (newNode == NULL)
        cout << "OverFlow\n";
    else
    {
        // If deque is empty
        if (front == NULL)
            rear = front = newNode;

            // Inserts node at the front end
        else
        {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }

        // Increments count of elements by 1
        Size++;
    }
}

template<typename E>
void DequeADTList<E>::insertBack(const E &data) {

    dequeNode* newNode = dequeNode::getnode(data);
    // If true then new element cannot be added
    // and it is an 'Overflow' condition
    if (newNode == NULL)
        cout << "OverFlow\n";
    else
    {
        // If deque is empty
        if (rear == NULL)
            front = rear = newNode;

            // Inserts node at the rear end
        else
        {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }

        Size++;
    }
}

template<typename E>
const E &DequeADTList<E>::eraseFront() {
    // If deque is empty then
    // 'Underflow' condition
    if (isEmpty())
        cout << "UnderFlow\n";

        // Deletes the node from the front end and makes
        // the adjustment in the links
    else
    {
        dequeNode* temp = front;
        front = front->next;

        // If only one element was present
        if (front == NULL)
            rear = NULL;
        else
            front->prev = NULL;
        free(temp);

        // Decrements count of elements by 1
        Size--;
    }

}

template<typename E>
const E &DequeADTList<E>::eraseBack() {

    // If deque is empty then
    // 'Underflow' condition
    if (isEmpty())
        cout << "UnderFlow\n";

        // Deletes the node from the rear end and makes
        // the adjustment in the links
    else
    {
        dequeNode* temp = rear;
        rear = rear->prev;

        // If only one element was present
        if (rear == NULL)
            front = NULL;
        else
            rear->next = NULL;
        free(temp);

        // Decrements count of elements by 1
        Size--;
    }
}

template<typename E>
const E &DequeADTList<E>::getfront() const {

    // If deque is empty, then returns
    // garbage value
    if (isEmpty())
        return -1;
    return front->data;
}

template<typename E>
const E &DequeADTList<E>::getback() const {
    // If deque is empty, then returns
    // garbage value
    if (isEmpty())
        return -1;
    return rear->data;
}

template<typename E>
int DequeADTList<E>::size() const {
    return Size;
}

template<typename E>
void DequeADTList<E>::Display() {
    // if list is not empty
    if (!isEmpty()) {
        dequeNode* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        return;
    }
    cout << "List is Empty" << endl;
}

template<typename E>
bool DequeADTList<E>::isEmpty() const {

    return (front == NULL);
}

// push to push element at top of stack
// using insert at last function of deque
template<typename E>
void DequeADTList<E>:: push(const E &element)
{
    insertBack(element);
}

// pop to remove element at top of stack
// using remove at last function of deque
template<typename E>
void DequeADTList<E>::pop()
{
    eraseBack();
}

template<typename E>
void DequeADTList<E>::deque() {
    eraseFront();
}

template<typename E>
void DequeADTList<E>::enqueue(const E &e) {
    insertBack(e);
}


int main(){
//    template<typename E>, I have chosen Integer type data.
    DequeADTList<int> dq;
    cout << "Insert element '5' at rear end\n";
    dq.insertBack(5);

    cout << "Insert element '10' at rear end\n";
    dq.insertBack(10);

    cout << "Rear end element: "
         << dq.getback() << endl;

    dq.eraseBack();
    cout << "After deleting rear element new rear"
         << " is: " << dq.getback() << endl;

    cout << "Inserting element '15' at front end \n";
    dq.insertFront(15);

    cout << "Front end element: "
         << dq.getfront() << endl;

    cout << "Number of elements in Deque: "
         << dq.size() << endl;

    dq.eraseFront();
    cout << "After deleting front element new "
         << "front is: " << dq.getfront() << endl;

    cout<<"#####################################################"<<endl;

    cout<<"Implementing the Stack using LinkedList and Deque"<<endl;
    DequeADTList<int> stack;
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
    DequeADTList<int> que;

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


