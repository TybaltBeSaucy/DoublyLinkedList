#include "DoublyLinkedList.h"

template <typename T>
class Queue {
private:
    DoublyLinkedList<T> list;

public:
    Queue() {}

    void enqueue(T value) {
        list.push_back(value);
    }

    T dequeue() {
        if (list.is_empty()) {
            throw std::out_of_range("Queue is empty");
        }

        return list.pop_front();
    }

    bool is_empty() const {
        return list.is_empty();
    }
};