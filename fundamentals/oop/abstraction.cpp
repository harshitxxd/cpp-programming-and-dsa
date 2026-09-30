#include<iostream>
#include<string>
using namespace std;

// Time Complexity: O(n)

class shape { // abstract class
    virtual void draw() = 0; // pure virtual function
};

class circle : public shape {
    public :
    void draw(){
        cout << "drawing a circle \n" ;
    }
};

int main(){
    circle c;
    c.draw();
    return 0;
 
}