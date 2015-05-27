#ifndef LINKED_LIST
#define LINKED_LIST

#include "LinkedListNode.h"

template<class T>
class LinkedList {
    private:
        Node<T> * head;

    public:
        LinkedList();
        LinkedList(T data);

        ~LinkedList();

        void add(T data);
        Node<T> * getHeadNode() {return head;}
};

#include "LinkedList.tpp"

#endif //LINKED_LIST