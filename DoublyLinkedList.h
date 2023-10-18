#pragma once
#include <stdexcept>
#include <iostream>

using namespace std;

template <typename T>
class DoublyLinkedList
{
private:
    class Node
    {
    public:
        T data;
        Node *next;
        Node *previous;

        Node(T data) : data(data), next(nullptr), previous(nullptr) {}
    };
    void insertNode(Node *node, T value);
    void removeNode(Node *node);
    T m_size;
    Node *m_head;
    Node *m_tail;
    void insert_very_first_node(Node *node_to_insert);
    void insert_new_head(Node *node_to_insert);
    void insert_new_tail(Node *node_to_insert);
    void insert_between_nodes(Node *previous_node, Node *next_node, Node *node_to_insert);
    int remove_node(Node *node_to_remove);
    int remove_only_node();
    int remove_head();
    int remove_tail();
    int remove_node();

public:
    DoublyLinkedList();
    int size() const;
    int pop_front();
    int pop_back();
    int remove(int position);
    int get(int position);
    int set(int position, T value);
    bool is_empty() const;
    void print_list() const;
    void push_front(T value);
    void push_back(T value);
    void prepend(T value);
    void append(T value);
    void insert(int position, T value);
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    m_size = 0;
    m_head = nullptr;
    m_tail = nullptr;
}

template <typename T>
int DoublyLinkedList<T>::size() const
{
    return m_size;
}

template <typename T>
bool DoublyLinkedList<T>::is_empty() const
{
    return m_size == 0;
}
template <typename T>
void DoublyLinkedList<T>::print_list() const
{
    if (is_empty())
    {
        cout << "Empty List" << endl;
    }
    else
    {
        Node *to_print = m_head;

        while (to_print != nullptr)
        {
            cout << "Node: " << to_print->data << endl;

            to_print = to_print->next;
        }
    }
}

template <typename T>
void DoublyLinkedList<T>::insert_very_first_node(Node *node_to_insert)
{
    m_head = node_to_insert;
    m_tail = node_to_insert;
    node_to_insert->next = nullptr;
    node_to_insert->previous = nullptr;
    m_size++;
}

template <typename T>
void DoublyLinkedList<T>::insert_new_head(Node *node_to_insert)
{
    node_to_insert->previous = nullptr;
    node_to_insert->next = m_head;
    m_head->previous = node_to_insert;
    m_head = node_to_insert;
    m_size++;
}

template <typename T>
void DoublyLinkedList<T>::insert_new_tail(Node *node_to_insert)
{
    node_to_insert->next = nullptr;
    node_to_insert->previous = m_tail;
    m_tail->next = node_to_insert;
    m_tail = node_to_insert;
    m_size++;
}

template <typename T>
void DoublyLinkedList<T>::insert_between_nodes(Node *previous_node, Node *next_node, Node *node_to_insert)
{
    if (previous_node == nullptr)
    {
        node_to_insert->next = m_head;
        m_head->previous = node_to_insert;
        m_head = node_to_insert;
    }
    else if (next_node == nullptr)
    {
        node_to_insert->previous = m_tail;
        m_tail->next = node_to_insert;
        m_tail = node_to_insert;
    }
    else
    {
        node_to_insert->previous = previous_node;
        node_to_insert->next = next_node;
        previous_node->next = node_to_insert;
        next_node->previous = node_to_insert;
    }

    m_size++;
}

template <typename T>
void DoublyLinkedList<T>::push_front(T value)
{
    prepend(value);
}

template <typename T>
void DoublyLinkedList<T>::push_back(T value)
{
    append(value);
}

template <typename T>
void DoublyLinkedList<T>::prepend(T value)
{
    Node *node_to_insert = new Node(value);

    if (is_empty())
    {
        insert_very_first_node(node_to_insert);
    }
    else
    {
        insert_new_head(node_to_insert);
    }
}

template <typename T>
void DoublyLinkedList<T>::append(T value)
{
    Node *node_to_insert = new Node(value);

    if (is_empty())
    {
        insert_very_first_node(node_to_insert);
    }
    else
    {
        insert_new_tail(node_to_insert);
    }
}

template <typename T>
void DoublyLinkedList<T>::insert(int position, T value)
{
    Node *node_to_insert = new Node(value);

    if (is_empty())
    {
        insert_very_first_node(node_to_insert);
    }
    else if (position <= 0)
    {
        insert_new_head(node_to_insert);
    }
    else if (position >= m_size)
    {
        insert_new_tail(node_to_insert);
    }
    else
    {
        Node *temp = m_head;

        while (--position > 0)
        {
            temp = temp->next;
        }
        node_to_insert->next = temp->next;
        temp->next = node_to_insert;
        m_size++;
    }
}

template <typename T>
int DoublyLinkedList<T>::remove_only_node()
{
    Node *node_to_free = m_head;
    T value_to_return = node_to_free->data;
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
    delete node_to_free;
    return value_to_return;
}
template <typename T>
int DoublyLinkedList<T>::remove_head()
{
    Node *node_to_free = m_head;
    T value_to_return = node_to_free->data;
    m_head = m_head->next;
    m_head->previous = nullptr;
    m_size--;
    delete node_to_free;
    return value_to_return;
}
template <typename T>
int DoublyLinkedList<T>::remove_tail()
{
    Node *node_to_free = m_tail;
    T value_to_return = node_to_free->data;
    m_tail = m_tail->previous;
    m_tail->next = nullptr;
    m_size--;
    delete node_to_free;
    return value_to_return;
}
template <typename T>
int DoublyLinkedList<T>::pop_front()
{
    if (is_empty())
    {
        cout << "pop_front on Empty List" << endl;
    }
    else if (m_size == 1)
    {
        return remove_only_node();
    }
    else
    {
        return remove_head();
    }
}
template <typename T>
int DoublyLinkedList<T>::pop_back()
{
    if (is_empty())
    {
        cout << "pop_front on Empty List" << endl;
    }
    else if (m_size == 1)
    {
        return remove_only_node();
    }
    else
    {
        return remove_tail();
    }
}
template <typename T>
int DoublyLinkedList<T>::get(int position)
{
    if ((position < 0) || (position > m_size - 1))
    {
        cout << "pop_front on Empty List" << endl;
    }
    else
    {
        int current_location = 0;
        Node *current_node = m_head;
        while (current_location < position)
        {
            current_node = current_node->next;
            current_location++;
        }
        cout << current_node->data << endl;
        return current_node->data;
    }
}

template <typename T>
int DoublyLinkedList<T>::set(int position, T value)
{
    // if greater than or less than list size, throw exception
    if (position <= 0 || position >= size())
    {
        throw out_of_range("Position is not valid.");
    }
    else
    {
        Node *temp = m_head;
        int index = 0;

        while (temp != nullptr)
        {
            if (index == position)
            {
                int old_value = temp->data;
                temp->data = value;
                return old_value;
            }

            temp->previous = temp;
            temp = temp->next;
            index++;
        }
    }
}
template <typename T>
int DoublyLinkedList<T>::remove_node(Node *node_to_remove)
{
    // check if the node to remove is the head
    if (node_to_remove == m_head)
    {
        return remove_head();
    }
    // check if the node to remove is the tail
    if (node_to_remove == m_tail)
    {
        return remove_tail();
    }
    // otherwise, the node to remove is in the middle of the list
    T value_to_return = node_to_remove->data;
    node_to_remove->previous->next = node_to_remove->next;
    node_to_remove->next->previous = node_to_remove->previous;
    m_size--;
    delete node_to_remove;
    return value_to_return;
}
template <typename T>
int DoublyLinkedList<T>::remove(int position)
{
    // if position < 0, throw exception
    if (position < 0)
    {
        throw out_of_range("position is negative");
    }
    // if position >= size of list, throw exception
    if (position >= m_size)
    {
        throw out_of_range("position is greater than or equal to the size of the list");
    }
    // if position is 0, pop the front element
    if (position == 0)
    {
        return pop_front();
    }
    // if position is size-1, pop the back element
    if (position == m_size - 1)
    {
        return pop_back();
    }
    // otherwise, you know the list has at least 3
    // elements. Find the node to remove and use your
    // utility function
    else
    {
        Node *node_to_remove = m_head;
        for (int i = 0; i < position - 1; i++)
        {
            node_to_remove = node_to_remove->next;
        }
        return remove_node(node_to_remove);
    }
};