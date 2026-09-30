#include<iostream>
#include<string>
using namespace std;

// Time Complexity: O(n)
class Person{
    public:
    string name ;
    int age ;

    Person(string name , int age){
        this -> name = name;
        this -> age = age;
    }
};

// single inheritance
class Student : public Person{
    public :
    int rollno ;

    Student(string name , int age, int rollno) : Person(name,age){
        this -> rollno = rollno;
    }

    void getinfo(){
        cout << "name : " << name << endl;
        cout << "age : " << age << endl;
        cout << "rollno : " << rollno << endl;
    }
};
// multi level inheritance
class gradstudent : public Student{
    public :
    string research ;

    gradstudent(string name , int age, int rollno): Student(name,age,rollno){

    }
};
// multiple and hierarchical inheritance
class Father {
    public :
    string father_name ;
};
class Mother {
    public: 
    string mohter_name;
};

class Daughter : public Father, public Mother{
    public :
    string daughter_name;

};

class Son : public Father , public Mother{
    public :
    string son_name;
};

int main(){
    Student s("harshit", 19,31); 
    s.getinfo();
    gradstudent g("komal",19,32);
    g.getinfo();
    
    Daughter n;
    n.father_name = "prem";
    Son h;
    h.mohter_name = "phool";
    return 0;

}