#include<iostream>
#include<string>

using namespace std;

// Time Complexity: O(n)
class Student{
    public :
    string name ;
    double *cgpaptr;

    Student(string name , double cgpa){
        this -> name = name;
        cgpaptr = new double ;
        *cgpaptr = cgpa ;
    }
    
    ~Student(){
        cout << "i delete everything\n";
        delete cgpaptr;
    }

    void getinfo(){
        cout << "name : " << name << endl;
        cout << "cgpa : " << *cgpaptr << endl;
        cout << endl;
    }
};

int main(){
    Student s1("harshit",9.8);
    s1.getinfo();
    
    return 0;
}