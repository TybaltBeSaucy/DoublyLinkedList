#pragma once

class Node {
    public:
        Node(int val = 0):
            value{val}, next{nullptr}, previous{nullptr} {}

        int value;
        Node* next;
        Node* previous;
};