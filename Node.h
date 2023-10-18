#pragma once

class Node {
    public:
        Node(int val = 0):
            data{val}, next{nullptr}, previous{nullptr} {}

        int data;
        Node* next;
        Node* previous;
};