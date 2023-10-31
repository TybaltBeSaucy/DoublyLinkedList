#include "DoublyLinkedList.h"

template <typename T>
class Deque {
private:
    DoublyLinkedList<T> list;

public:
    Deque() {}

    void push_front(T value) {
        list.push_front(value); // Add to the front of the Deque
    }

    void push_back(T value) {
        list.push_back(value); // Add to the back of the Deque
    }

    T pop_front() {
        return list.pop_front(); // Remove from the front of the Deque
    }

    T pop_back() {
        return list.pop_back(); // Remove from the back of the Deque
    }

    bool is_empty() const {
        return list.is_empty();
    }

    bool is_palindrome(const std::string& str) {
        Deque<char> characters;
        
        // Push characters from the string into the Deque
        for (char c : str) {
            if (std::isalnum(c)) {
                characters.push_back(std::tolower(c));
            }
        }

        // Check for palindrome by comparing characters from both ends
        while (!characters.is_empty()) {
            if (characters.pop_front() != characters.pop_back()) {
                return false;
            }
        }

        return true;
    }
};
