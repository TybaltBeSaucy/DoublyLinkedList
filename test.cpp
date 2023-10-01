#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void insert_between_nodes(Node* previous_node, Node* next_node, Node* node_to_insert) {
    if (previous_node == nullptr || next_node == nullptr || node_to_insert == nullptr) {
        cout << "Invalid input" << endl;
        return;
    }

    node_to_insert->next = next_node;
    previous_node->next = node_to_insert;
}

int main() {
    Node* head = new Node();
    head->data = 1;
    head->next = new Node();
    head->next->data = 2;
    head->next->next = new Node();
    head->next->next->data = 3;

    Node* node_to_insert = new Node();
    node_to_insert->data = 4;

    insert_between_nodes(head->next, head->next->next, node_to_insert);

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
