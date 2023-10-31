#include <iostream>
#include <string>
#include <cmath>

#include "Queue.h"

void generateBinary(int n) {
    Queue<std::string> queue;
    queue.enqueue("1");

    for (int i = 1; i <= n; ++i) {
        std::string current = queue.dequeue();
        std::cout << current << std::endl;

        std::string next;

        queue.enqueue(current + "0");
        queue.enqueue(current + "1");
    }
}
bool isSymbolBalanced(const std::string &phrase) {
    Queue<char> symbols;
    
    for (char c : phrase) {
        if (c == '(' || c == '[' || c == '{') {
            symbols.enqueue(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (symbols.is_empty()) {
                return false;
            }

            char openSymbol = symbols.dequeue();
            if ((c == ')' && openSymbol != '(') ||
                (c == ']' && openSymbol != '[') ||
                (c == '}' && openSymbol != '{')) {
                return false;
            }
        }
    }

    return symbols.is_empty();
}
int main() {
    int n = 12;
    std::cout << "Binary numbers from 1 to " << n << ":" << std::endl;
    generateBinary(n);

    std::string phrase = "((a + b) * (c - d))";
    std::cout << "Is the phrase balanced? " << std::boolalpha << isSymbolBalanced(phrase) << std::endl;

    return 0;
}
