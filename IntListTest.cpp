#include <iostream>
#include "IntList.cpp"

using namespace std;

int main() {
    IntList my_list_of_units;

    cout << "After creation, my_list_of_ints has size: ";
    cout << my_list_of_units.size() << endl;
    cout << "is_empty: " << my_list_of_units.is_empty() << endl;

    cout << "Here is the list" << endl;
    my_list_of_units.print_list();

    cout << "I'm pushing some values on the front of the list" << endl;

    my_list_of_units.push_front(10);
    my_list_of_units.push_front(20);
    my_list_of_units.push_front(30);
    my_list_of_units.push_front(40);
    my_list_of_units.push_front(50);

    cout << "I expect: 50, 40, 30, 20, 10" << endl;
    my_list_of_units.print_list();

    cout << "I'm pushing some values on the back of the list" << endl;
    my_list_of_units.push_back(60);
    my_list_of_units.push_back(70);

    cout << "I expect: 50, 40, 30, 20, 10, 60, 70" << endl;
    my_list_of_units.print_list();

    cout << "I'm inserting some values into the beginning and middle of the list";
    my_list_of_units.insert(1, 60);
    my_list_of_units.insert(7, 0);

    cout << "I expect: 60, 50, 40, 30, 20, 10, 0, 60, 70" << endl;
    my_list_of_units.print_list();

    my_list_of_units.pop_front();
    my_list_of_units.pop_back();

    cout << "I expect: 50, 40, 30, 20, 10, 0, 60" << endl;
    my_list_of_units.print_list();
    
    cout << "I expect: 40" << endl;
    my_list_of_units.get(1);

    my_list_of_units.remove(1);

    cout << "I expect: 40, 30, 20, 10, 0, 60" << endl;
    my_list_of_units.print_list();
}