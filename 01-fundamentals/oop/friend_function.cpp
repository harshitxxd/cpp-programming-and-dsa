/*
 * File: friend_function.cpp
 * Description: Demonstrates how a friend function can access a class's private data.
 */

#include <iostream>
using namespace std;

// Time Complexity: O(n)
class Box {
private:
    int width;

public:
    explicit Box(int boxWidth) : width(boxWidth) {}

    // This non-member function is allowed to access Box's private members.
    friend int getWidth(const Box& box);
};

// A friend function is defined like an ordinary function, outside the class.
int getWidth(const Box& box) {
    return box.width;
}

int main() {
    Box box(10);

    // Call it like a regular function, passing the object as an argument.
    cout << "Width: " << getWidth(box) << '\n';
    return 0;
}
