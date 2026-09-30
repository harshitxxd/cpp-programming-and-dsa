#include<iostream>
#include<string>
using namespace std;

// Time Complexity: O(n)
class Student {
    public:
    string name ;
    //  consttructor overloading
    Student(){
        cout << "non parmetriized constructor\n";
    }

    Student(string name){
        this -> name = name;
        cout << "parametrized constructor\n";
    }

};

class print{
    public :
    // function overloading
    void show(int x){
        cout << "int : " << x << endl;
    }

    void show (char ch){
        cout << "char : " << ch << endl;
    }
};

class Parent {
    public:
    void getinfo(){
        cout << "parent class \n";
    }

    virtual void hello(){
        cout << "hello from parent \n";
    }
};

class Child : public Parent{
    public:
    void getinfo(){
        cout << "child class \n";
    }

    void hello(){
        cout << "hello from child\n";
    }

};
int main(){
    Student s;
    Student s1("harshit");
    print p;
    p.show(10);
    p.show('H');
    Parent p1;
    p1.getinfo();
    p1.hello();
    Child c;
    c.getinfo();
    c.hello(); 
    return 0;
}