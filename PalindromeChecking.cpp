#include "Deque.h"

int main() {
    Deque<char> deque;

    std::string str1 = "hello";
    if (deque.is_palindrome(str1)) {
        std::cout << str1 << " IS a palindrome." << std::endl;
    } else {
        std::cout << str1 << " IS NOT a palindrome." << std::endl;
    }

    std::string str2 = "radar";
    if (deque.is_palindrome(str2)) {
        std::cout << str2 << " IS a palindrome." << std::endl;
    } else {
        std::cout << str2 << " IS NOT a palindrome." << std::endl;
    }

    std::string str3 = "racecar";
    if (deque.is_palindrome(str3)) {
        std::cout << str3 << " IS a palindrome." << std::endl;
    } else {
        std::cout << str3 << " IS NOT a palindrome." << std::endl;
    }

    std::string str4 = "kayak";
    if (deque.is_palindrome(str4)) {
        std::cout << str4 << " IS a palindrome." << std::endl;
    } else {
        std::cout << str4 << " IS NOT a palindrome." << std::endl;
    }

    return 0;
}
