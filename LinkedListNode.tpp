template<class T>
Node<T>::Node() {
    data = NULL;
    next = NULL;
}

template<class T>
Node<T>::Node(T data) {
    this->data = data;
    next = NULL;
}

template<class T>
Node<T>::~Node() {
    // no fields need be freed
}