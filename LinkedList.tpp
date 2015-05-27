template<class T>
LinkedList<T>::LinkedList() {
    head = NULL;
}

template<class T>
LinkedList<T>::LinkedList(T data) {
    Node<T> * headNode = new Node<T>;
    headNode->setData(data);
    headNode->setNext(NULL);
    head = headNode;
}

template<class T>
LinkedList<T>::~LinkedList() {
    Node<T> * curr = head;
    Node<T> * prev = NULL;
    while(curr) {
        prev = curr;
        curr = curr->next;
        delete prev;
    }
    delete head;
}

template<class T>
void LinkedList<T>::add(T data) {
    Node<T> * curr = head;
    while(curr->next) { // moves to the end of the list
        curr = curr->next;
    }
    Node<T> * tmp = new Node<T>;
    tmp->data = data;
    tmp->next = NULL;
    curr->next = tmp;
}