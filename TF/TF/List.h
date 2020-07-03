#pragma once
#include <functional>
using namespace std;

template <typename T>
class List
{
private:
    struct Node {
        T       elem;
        Node* next;
        Node* prev;

        Node(T elem, Node* p = nullptr, Node* n = nullptr)
            : elem(elem), next(n), prev(p) {}
    };

    Node* head;
    int     length;

public:
	List() : head(nullptr), length(0) {}
    ~List() { clear(); }

    int size();
    bool empty();

    void addFirst(T elem);
    void addLast(T elem);
    void addPos(T elem, int pos);

    void removeFirst();
    void removeLast();
    void removePos(int pos);

    void modifyFirst(T elem);

    void modifyLast(T elem);

    void modifyPos(T elem, int pos);

    T getFirst();
    T GetLast();
    T getPos(int pos);

    void clear();

    class iterator {
        Node* aux;
        int pos;
    public:
        iterator(int pos = 0, Node* aux = nullptr) : pos(pos), aux(aux) {}
        bool operator!=(iterator o) {
            return this->pos != o.pos;
        }
        void operator++() {
            ++pos;
            aux = aux->next;
        }
        T operator*() {
            return aux->elem;
        }
    };

    iterator begin() {
        return iterator(0, head);
    }

    iterator end() {
        return iterator(length);
    }

private:

};

template<typename T>
int List<T>::size() { return length; }

template<typename T>
bool List<T>::empty() { return length == 0; }

template<typename T>
void List<T>::addFirst(T elem) {
    if (length == 0) {
        head = new Node(elem);
        head->next = head;
        head->prev = head;
    }
    else {
        auto newest = new Node(elem, head->prev, head);
        head->prev = newest;
        newest->prev->next = newest;
        head = newest;
    }
    ++length;
}

template<typename T>
void List<T>::addLast(T elem) {
    if (length == 0) {
        addFirst(elem);
    }
    else {
        auto newest = new Node(elem, head->prev, head);
        head->prev = newest;
        newest->prev->next = newest;
        ++length;
    }
}

template<typename T>
void List<T>::addPos(T elem, int pos) {
    if (pos == 0) {
        addFirst(elem);
    }
    else {
        auto aux = head;
        if (pos > 0 && pos <= length) {
            for (int i = 1; i < pos; ++i) {
                aux = aux->next;
            }
            auto newest = new Node(elem, aux, aux->next);
            aux->next->prev = newest;
            aux->next = newest;
        }
        else if (pos < 0 && -pos <= length) {
            for (int i = -1; i > pos; --i) {
                aux = aux->prev;
            }
            auto newest = new Node(elem, aux->prev, aux);
            aux->prev->next = newest;
            aux->prev = newest;
        }
        else {
            return;
        }
        ++length;
    }
}

template<typename T>
void List<T>::removeFirst() {
    if (length == 0) {
        return;
    }
    if (length == 1) {
        delete head;
        head = nullptr;
    }
    else {
        auto aux = head;
        head = head->next;
        head->prev = aux->prev;
        aux->prev->next = head;
        delete aux;
    }
    --length;
}

template<typename T>
void List<T>::removeLast() {
    if (length == 0) {
        return;
    }
    if (length == 1) {
        delete head;
        head = nullptr;
    }
    else {
        auto aux = head->prev;
        aux->prev->next = head;
        head->prev = aux->prev;
        delete aux;
    }
    --length;
}

template<typename T>
void List<T>::removePos(int pos) {
    if (length == 0) {
        return;
    }
    if (pos == 0) {
        removeFirst();
    }
    else {
        auto aux = head;
        if (pos > 0 && pos < length) {
            for (int i = 1; i < pos; ++i) {
                aux = aux->next;
            }
            auto aux2 = aux->next;
            aux->next = aux2->next;
            aux2->next->prev = aux;
            delete aux2;
        }
        else if (pos < 0 && -pos < length) {
            for (int i = -1; i > pos; --i) {
                aux = aux->prev;
            }
            auto aux2 = aux->prev;
            aux->prev = aux2->prev;
            aux2->prev->next = aux;
            delete aux2;
        }
        else {
            return;
        }
        --length;
    }
}

template<typename T>
void List<T>::modifyFirst(T elem) {
    if (length > 0) {
        head->elem = elem;
    }
}

template<typename T>
void List<T>::modifyLast(T elem) {
    if (length > 0) {
        head->prev->elem = elem;
    }
}

template<typename T>
void List<T>::modifyPos(T elem, int pos) {
    if (length > 0) {
        auto aux = head;
        if (pos >= 0 && pos < length) {
            for (int i = 0; i < pos; ++i) {
                aux = aux->next;
            }
        }
        else if (pos < 0 && -pos < length) {
            for (int i = 0; i > pos; --i) {
                aux = aux->prev;
            }
        }
        aux->elem = elem;
    }
}

template<typename T>
T List<T>::getFirst() {
    if (length > 0) {
        return head->elem;
    }
    return NONE;
}

template<typename T>
T List<T>::GetLast() {
    if (length > 0) {
        return head->prev->elem;
    }
    return NONE;
}

template<typename T>
T List<T>::getPos(int pos) {
    if (length > 0) {
        auto aux = head;
        if (pos >= 0 && pos < length) {
            for (int i = 0; i < pos; ++i) {
                aux = aux->next;
            }
        }
        else if (pos < 0 && -pos < length) {
            for (int i = 0; i > pos; --i) {
                aux = aux->prev;
            }
        }
        return aux->elem;
    }
    return NONE;
}

template<typename T>
void List<T>::clear() {
    for (int i = 0; i < length; ++i) {
        auto aux = head;
        head = aux->next;
        delete aux;
    }
    length = 0;
}
