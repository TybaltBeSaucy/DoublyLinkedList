#include <iostream>
#include "IntList.h"

using namespace std;

IntList::IntList() {
    m_size = 0;
    m_head = nullptr;
    m_tail = nullptr;
}

int IntList::size() const {
    return m_size;
}

bool IntList::is_empty() const {
    return m_size == 0;
}

void IntList::print_list() const {
    if (is_empty()) {
        cout << "Empty List" << endl;
    }
    else {
        Node* to_print = m_head;

        while (to_print != nullptr) {
            cout << "Node: " << to_print->value << endl;

            to_print = to_print->next;
        }
    }
}

void IntList::insert_very_first_node(Node* node_to_insert) {
    m_head = node_to_insert;
    m_tail = node_to_insert;
    node_to_insert->next = nullptr;
    node_to_insert->previous = nullptr;
    m_size++;
}

void IntList::insert_new_head(Node* node_to_insert) {
    node_to_insert->previous = nullptr;
    node_to_insert->next = m_head;
    m_head->previous = node_to_insert;
    m_head = node_to_insert;
    m_size++;
}

void IntList::insert_new_tail(Node* node_to_insert) {
    node_to_insert->next = nullptr;
    node_to_insert->previous = m_tail;
    m_tail->next = node_to_insert;
    m_tail = node_to_insert;
    m_size++;
}

void IntList::insert_between_nodes(Node* previous_node, Node* next_node, Node* node_to_insert) {
    node_to_insert->next = next_node;
    previous_node->next = node_to_insert;
}

void IntList::push_front(int value) {
    prepend(value);
}

void IntList::push_back(int value) {
    append(value);
}

void IntList::prepend(int value) {
    Node* node_to_insert = new Node(value);

    if (is_empty()) {
        insert_very_first_node(node_to_insert);
    }
    else {
        insert_new_head(node_to_insert);
    }
}

void IntList::append(int value) {
    Node* node_to_insert = new Node(value);
    
    if (is_empty()) {
        insert_very_first_node(node_to_insert);
    }
    else {
        insert_new_tail(node_to_insert);
    }
}

void IntList::insert(int position, int value) {
    Node* node_to_insert = new Node(value);
    node_to_insert->value = value;
    node_to_insert->next = nullptr;

    if(is_empty()) {
        insert_very_first_node(node_to_insert);
    }
    else if(position <= 0){
        insert_new_head(node_to_insert);
    }
    else if(position >= m_size) {
        insert_new_tail(node_to_insert);
    }
    else {
        Node* temp = m_head;

        while(--position > 1) {
            temp = temp->next;
        }
        node_to_insert->next = temp->next;
        temp->next = node_to_insert;
        m_size++;
    }
}