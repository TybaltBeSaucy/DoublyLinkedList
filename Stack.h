#pragma once
#include <stdexcept>
#include "DoublyLinkedList.h"

template <typename T>
class Stack
{
private:
    DoublyLinkedList<T> my_backing_list;

public:
    void push(T value) { my_backing_list.push_front(value); }
    T top const
    {
        try
        {
            return my_backing_list.get(0);
        }
        catch
        {
            throw std::out_of_range("Stack is empty");
        }
    }

    T pop() {
        try {
            my_backing_list.pop_front();
        }
        catch ()
    }

    int size() {
        return my_backing_list.size();
    }
};