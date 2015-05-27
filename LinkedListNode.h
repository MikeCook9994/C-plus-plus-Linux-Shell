#ifndef LINKED_LIST_NODE
#define LINKED_LIST_NODE

template<class T>
class Node {
    private:
        T data;
        Node<T> * next;

    public:
        Node();
        Node(T data);

        ~Node();

        void setNext(Node * next) {this->next = next;}
        Node<T> * getNext(void) {return next;}
        void setData(T data) {this->data = data;}
        T getData(void) {return data;}
};

#include "LinkedListNode.tpp"

#endif //LINKED_LIST_NODE