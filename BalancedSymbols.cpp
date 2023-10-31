#include <cassert>
#include <string>

#include "Stack.h"

bool chars_match(char c1, char c2) {
    if (((c1 == '(') && (c2 == ')')) || ((c1 == ')') && (c2 == '('))) {
        return true;
    }
    if (((c1 == '{') && (c2 == '}')) || ((c1 == '}') && (c2 == '{'))) {
        return true;
    }
    if (((c1 == '<') && (c2 == '>')) || ((c1 == '>') && (c2 == '<'))) {
        return true;
    }
    if (((c1 == '[') && (c2 == ']')) || ((c1 == ']') && (c2 == '['))) {
        return true;
    }

    return false;
}

bool is_phrase_balanced(const string& phrase_to_check) {
    Stack<char> balance_check;
    string opening_symbols = "([{<";
    string closing_symbols = ")]}>";
}