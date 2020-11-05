//
// Created by snowflake3509 on 29/10/20.
//

#ifndef DEQUE_DEQUEADTLIST_H
#define DEQUE_DEQUEADTLIST_H
#include<istream>

template <typename E>
class DequeADTList{
private:

    struct dequeNode{
        int data;
        dequeNode *prev, *next;
        // Function to get a new node
        static dequeNode* getnode(int data)
        {
            dequeNode* newNode = (dequeNode*)malloc(sizeof(dequeNode));
            newNode->data = data;
            newNode->prev = newNode->next = NULL;
            return newNode;
        }
    };

    dequeNode* front;
    dequeNode* rear;
    int Size;
public:
    DequeADTList();			//constructor
    ~DequeADTList();			//destructor
    void insertFront(const E& e);
    void insertBack(const E& e);
    const E& eraseFront(); // throw(DequeEmpty);	//note that the use of exceptions is optional
    const E& eraseBack(); // throw(DequeEmpty);	//note that the use of exceptions is optional
    const E &getfront() const; // throw(DequeEmpty);	//note that the use of exceptions is optional
    const E& getback() const; // throw(DequeEmpty);	//note that the use of exceptions is optional
    int size () const;
    void Display();
    bool isEmpty() const;
    //Stack Functions
    void pop();
    void push(const E &element);
    //Queue Functions
    void enqueue(const E &e);
    void deque();
};


#endif //DEQUE_DEQUEADTLIST_H
