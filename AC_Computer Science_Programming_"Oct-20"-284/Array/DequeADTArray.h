//
// Created by snowflake3509 on 29/10/20.
//

#ifndef DEQUE_DEQUEADTARRAY_H
#define DEQUE_DEQUEADTARRAY_H
#include<iostream>

#define MAX 100

template <typename E>
class DequeADTArray {
    int arr[MAX];
    int front;
    int rear;
    int size;
public:
    DequeADTArray(int i);			//constructor
    ~DequeADTArray();			//destructor
    void insertFront(const E& e);
    void insertBack(const E& e);
    const E& eraseFront(); // throw(DequeEmpty);	//note that the use of exceptions is optional
    const E& eraseBack(); // throw(DequeEmpty);	//note that the use of exceptions is optional
    const E& frontOfDeque() const; // throw(DequeEmpty);	//note that the use of exceptions is optional
    const E& backOfDeque() const; // throw(DequeEmpty);	//note that the use of exceptions is optional
    bool isFull() const;
    bool isEmpty() const;
    int sizeOfDeque() const;
    void Display();
    //Stack Functions
    void pop();
    void push(const E &element);
    //Queue Functions
    void enqueue(const E &e);
    void deque();

    DequeADTArray();
};
#endif //DEQUE_DEQUEADTARRAY_H
