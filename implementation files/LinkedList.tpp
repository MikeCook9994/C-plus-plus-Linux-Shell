template<class T>
LinkedList<T>::LinkedList() {
    head = NULL;
    currSize = 0;
}

template<class T>
LinkedList<T>::LinkedList(T data) {
    Node<T> * headNode = new Node<T>;
    headNode->setData(data);
    headNode->setNext(NULL);
    head = headNode;
    currSize = 1;
}

template<class T>
LinkedList<T>::~LinkedList() {
    Node<T> * curr = head;
    Node<T> * prev = NULL;
    while(curr) {
        prev = curr;
        curr = curr->getNext();
        delete prev;
    }
}

template<class T>
void LinkedList<T>::add(T data) {
    Node<T> * curr = head;

    if(curr == NULL) {
        head = new Node<T>(data);
        currSize++;
        return;
    }

    while(curr->getNext()) { // moves to the end of the list
        curr = curr->getNext();
    }

    Node<T> * tmp = new Node<T>;
    tmp->setData(data);
    tmp->setNext(NULL);
    curr->setNext(tmp);
    currSize++;
}