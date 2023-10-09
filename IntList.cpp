#include <iostream>
#include <stdexcept>
#include "IntList.h"

using namespace std;

IntList::IntList()
{
    m_size = 0;
    m_head = nullptr;
    m_tail = nullptr;
}

int IntList::size() const
{
    return m_size;
}

bool IntList::is_empty() const
{
    return m_size == 0;
}

void IntList::print_list() const
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
            cout << "Node: " << to_print->value << endl;

            to_print = to_print->next;
        }
    }
}

void IntList::insert_very_first_node(Node *node_to_insert)
{
    m_head = node_to_insert;
    m_tail = node_to_insert;
    node_to_insert->next = nullptr;
    node_to_insert->previous = nullptr;
    m_size++;
}

void IntList::insert_new_head(Node *node_to_insert)
{
    node_to_insert->previous = nullptr;
    node_to_insert->next = m_head;
    m_head->previous = node_to_insert;
    m_head = node_to_insert;
    m_size++;
}

void IntList::insert_new_tail(Node *node_to_insert)
{
    node_to_insert->next = nullptr;
    node_to_insert->previous = m_tail;
    m_tail->next = node_to_insert;
    m_tail = node_to_insert;
    m_size++;
}

void IntList::insert_between_nodes(Node *previous_node, Node *next_node, Node *node_to_insert)
{
    node_to_insert->next = next_node;
    previous_node->next = node_to_insert;
}

void IntList::push_front(int value)
{
    prepend(value);
}

void IntList::push_back(int value)
{
    append(value);
}

void IntList::prepend(int value)
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

void IntList::append(int value)
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

void IntList::insert(int position, int value)
{
    Node *node_to_insert = new Node(value);
    node_to_insert->value = value;
    node_to_insert->next = nullptr;

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

        while (--position > 1)
        {
            temp = temp->next;
        }
        node_to_insert->next = temp->next;
        temp->next = node_to_insert;
        m_size++;
    }
}
int IntList::remove_only_node()
{
    Node *node_to_free = m_head;
    int value_to_return = node_to_free->value;
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
    delete node_to_free;
    return value_to_return;
}
int IntList::remove_head()
{
    Node *node_to_free = m_head;
    int value_to_return = node_to_free->value;
    m_head = m_head->next;
    m_head->previous = nullptr;
    m_size--;
    delete node_to_free;
    return value_to_return;
}
int IntList::remove_tail()
{
    Node *node_to_free = m_tail;
    int value_to_return = node_to_free->value;
    m_tail = m_tail->previous;
    m_tail->next = nullptr;
    m_size--;
    delete node_to_free;
    return value_to_return;
}
int IntList::pop_front()
{
    if (is_empty())
    {
        throw out_of_range("pop_front on Empty List");
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
int IntList::pop_back()
{
    if (is_empty())
    {
        throw out_of_range("pop_back on Empty List");
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
int IntList::get(int position)
{
    if ((position < 0) || (position > m_size - 1))
    {
        throw out_of_range("getting out of range value");
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
        cout << current_node->value << endl;
        return current_node->value;
    }
}
int IntList::remove(int position)
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
}
int IntList::remove_node(Node *node_to_remove)
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
    int value_to_return = node_to_remove->value;
    node_to_remove->previous->next = node_to_remove->next;
    node_to_remove->next->previous = node_to_remove->previous;
    m_size--;
    delete node_to_remove;
    return value_to_return;
}