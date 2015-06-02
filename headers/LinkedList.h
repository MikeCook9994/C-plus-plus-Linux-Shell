#ifndef LINKED_LIST
#define LINKED_LIST

#include "defs.h"
#include "LinkedListNode.h"

template<class T>
class LinkedList {
    private:
        Node<T> * head;
        int currSize;

    public:
        LinkedList();
        LinkedList(T data);

        ~LinkedList();

        void add(T data);
        //void addToFront(T data);
        //void addToPos(T data, int pos);
        //Node<T> * remove(int pos);
        //Node<T> * remove(T data);
        //Node<T> * removeFirst();
        //Node<T> * removeLast();
        Node<T> * getFirst() {return head;}
        //Node<T> * get(int pos);
        //Node<T> * getLast();
        int size() {return currSize;}
        //bool contains(T data);
};

#include "../implementation files/LinkedList.tpp"

#endif //LINKED_LIST