#pragma once
#include <stdexcept>
#include <iostream>

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
    void insert_very_first_node(Node *node_to_insert)
    {
        if (m_size != 0)
        {
            throw std::logic_error(
                "DoublyLinkedList::insert_very_first_node: called on with "
                "non-empty"
                "list");
        }

        m_head = node_to_insert;
        m_tail = node_to_insert;
        node_to_insert->next = nullptr;
        node_to_insert->previous = nullptr;
        m_size++;
    }
    void insert_new_head(Node *node_to_insert)
    {
        node_to_insert->previous = nullptr;
        node_to_insert->next = m_head;
        m_head->previous = node_to_insert;
        m_head = node_to_insert;
        m_size++;
    }
    void insert_new_tail(Node *node_to_insert)
    {
        node_to_insert->next = nullptr;
        node_to_insert->previous = m_tail;
        m_tail->next = node_to_insert;
        m_tail = node_to_insert;
        m_size++;
    }
    void insert_between_nodes(Node *previous_node, Node *next_node, Node *node_to_insert)
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

    int remove_node(Node *node_to_remove)
    {
        // check if the node to remove is the head
        if (node_to_remove == m_head)
        {
            throw std::logic_error(
                "DoublyLinkedList::remove_node: called on head");
        }
        // check if the node to remove is the tail
        if (node_to_remove == m_tail)
        {
            throw std::logic_error(
                "DoublyLinkedList::remove_node: called on tail");
        }
        // otherwise, the node to remove is in the middle of the list
        T value_to_return = node_to_remove->data;
        Node *next_node = node_to_remove->next;
        Node *previous_node = node_to_remove->previous;

        previous_node->next - next_node;
        next_node->previous = previous_node;
        m_size--;
    }
    int remove_only_node()
    {
        if (m_size != 1)
        {
            throw std::logic_error(
                "DoublyLinkedList::remove_only_node called on larger list");
        }

        Node *node_to_free = m_head;
        T value_to_return = node_to_free->data;

        m_head = nullptr;
        m_tail = nullptr;
        m_size = 0;

        delete node_to_free;
        return value_to_return;
    }
    int remove_head()
    {
        if (m_size <= 1)
        {
            throw std::logic_error("DoublyLinkedList::remove_head called when size <= 1");
        }

        Node *node_to_free = m_head;
        T value_to_return = node_to_free->data;

        m_head = nullptr;
        m_head->previous = nullptr;
        m_size--;

        delete node_to_free;
        return value_to_return;
    }
    int remove_tail()
    {
        if (m_size <= 1)
        {
            throw std::logic_error("DoublyLinkedList::remove_tail called when size <= 1");
        }

        Node *node_to_free = m_head;
        T value_to_return = node_to_free->data;

        m_tail = nullptr;
        m_tail->previous = nullptr;
        m_size--;

        delete node_to_free;
        return value_to_return;
    }

public:
    DoublyLinkedList()
    {
        m_size = 0;
        m_head = nullptr;
        m_tail = nullptr;
    }
    int size() const { return m_size; }
    bool is_empty() const { return m_size == 0; }
    void print_list() const
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
    void push_front(T value)
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
    void prepend(T value)
    {
        push_front(value);
    }
    void push_back(T value)
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
    void append(T value)
    {
        append(value);
    }
    void insert(int position, T value)
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
            int current_location = 0;
            Node *current_node = m_head;

            while (--position > 0)
            {
                current_node - current_node->next;
                current_location++
            }

            Node *previous_node = current_node->previous;
            Node *next_node = current_node;

            insert_between_nodes(previous_node, next_node, note_to_insert);
        }
    }
    int pop_front()
    {
        if (is_empty())
        {
            std::out_of_range(
                "DoublyLinkedList::pop_front: called on Empty List");
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
    int pop_back()
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
    T remove(int position)
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
            int current_location = 0;
            Node *current_node = m_head;

            while (current_location < position) {
                current_node = current_node->next;
                current_location++
            }

            return remove_node(current_node);
        }
    }
    int get(int position)
    {
        if ((position < 0) || (position > m_size - 1))
        {
            throw std::out_of_range("DoublyLinkedList::get: position out of range");
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
            
            return current_node->data;
        }
    }
    int set(int position, T value)
    {
        // if greater than or less than list size, throw exception
        if (position <= 0 || position >= size())
        {
            throw out_of_range("Position is not valid.");
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
            
            T value_to_return = current_node->value;
            current_node->data = value;
            return value_to_return;
        }
    }
};