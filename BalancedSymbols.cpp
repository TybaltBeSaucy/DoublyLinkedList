#include <iostream>
#include <string>

#include "Stack.h"

bool chars_match(char c1, char c2)
{
    if (((c1 == '(') && (c2 == ')')) || ((c1 == ')') && (c2 == '(')))
    {
        return true;
    }
    if (((c1 == '{') && (c2 == '}')) || ((c1 == '}') && (c2 == '{')))
    {
        return true;
    }
    if (((c1 == '<') && (c2 == '>')) || ((c1 == '>') && (c2 == '<')))
    {
        return true;
    }
    if (((c1 == '[') && (c2 == ']')) || ((c1 == ']') && (c2 == '[')))
    {
        return true;
    }

    return false;
}

bool is_phrase_balanced(const string &phrase_to_check)
{
    Stack<char> balance_check;
    string opening_symbols = "([{<";
    string closing_symbols = ")]}>";

    char ch;
    int length = phrase_to_check.length();

    for (int i = 0; i < length; ++i)
    {
        ch = phrase_to_check.at(i);

        if (opening_symbols.find(ch) != string::npos)
        {
            balance_check.push(ch);
        }
        else if (closing_symbols.find(ch) != string::npos)
        {
            try
            {
                char popped_character = balance_check.pop();
                if (!chars_match(ch, popped_character))
                {
                    cout << "unmatched characters " << popped_character << " and " << ch << endl;
                    return false;
                }
            }
            catch (std::out_of_range oor) {
                cout << "unmatched ending character " << ch << endl;
                return false;
            }
        }
    }

    if (balance_check.size() != 0) {
        cout << "unmatched starting character " << balance_check.top() << endl;
        return false;
    }
    else {
        return true;
    }
}

void report_balance(const string& phrase) {
    cout << "----------" << endl;
    cout << "Checking phrase: " << phrase << endl;
    bool is_balanced = is_phrase_balanced(phrase);

    if (is_balanced) {
        cout << "The phrase is balanced." << endl;
    }
    else {
        cout << "The phrase is not balanced." << endl;
    }
}

int main() {
    try {
        string test_str = "(hello[there])";
        report_balance(test_str);
        assert(is_phrase_balanced(test_str) == true);

        test_str = "(hello<there])";
        report_balance(test_str);
        assert(is_phrase_balanced(test_str) == false);

        test_str = "(hello[there<you>{fool}]))";
        report_balance(test_str);
        assert(is_phrase_balanced(test_str));

        return 0;
    }
    catch (const std::exception &exc) {
        cout << exc.what();
        return 1;
    }
}