/*
 * File: friend_class.cpp
 * Description: Demonstrates how a friend class can access another class's private data.
 */

#include <iostream>
using namespace std;

class Box {
private:
    int width;

public:
    explicit Box(int boxWidth) : width(boxWidth) {}

    // Every member function of BoxInspector can access Box's private members.
    friend class BoxInspector;
};

class BoxInspector {
public:
    int getWidth(const Box& box) const {
        return box.width;
    }
};

int main() {
    Box box(10);
    BoxInspector inspector;

    cout << "Width: " << inspector.getWidth(box) << '\n';
    return 0;
}
