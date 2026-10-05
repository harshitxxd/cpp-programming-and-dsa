#include<iostream>
#include<string>

using namespace std;

// Time Complexity: O(n)
class Teacher{
    private :
    double salary;

    public :   
    // non parameterized 
    Teacher(){
        department = "computer science";
    }
    // parameterized   
    Teacher(string n, string d , string s, double sal){
        name = n;
        department = d;
        subject = s;
        salary = sal;
    }
    // copy
    Teacher(Teacher &orgobj){
        cout << "custom copy constructor" << endl;
        this ->name = orgobj.name;
        this ->department = orgobj.department;
        this ->subject = orgobj.subject;
        this ->salary = orgobj.salary;
    }
    string name ;
    string department ;
    string subject;
    
    void getinfo(){
        cout << "name : "<< name << endl;
        cout << "subject : " << subject << endl;
        cout << endl;
    }
 
};

class Student{
    public :
    string name ;
    double *cgpaptr;
 
    Student(string name , double cgpa){
        this -> name = name;
        cgpaptr = new double ;
        *cgpaptr = cgpa ;
    }
    // // shallow copy
    // student(student &obj){
    //     this -> name = obj.name;
    //     this ->cgpaptr = obj.cgpaptr;
    // }
    // deep copy
    Student(Student &obj){
        this -> name = obj.name;
        cgpaptr = new double;
        *cgpaptr = *obj.cgpaptr;
    }

    void getinfo(){
        cout << "name : " << name << endl;
        cout << "cgpa : " << *cgpaptr << endl;
        cout << endl;
    }
};
int main(){
    Teacher t1("harshit","computer science","C++",25000);
    t1.getinfo();
    Teacher t2(t1); // copy constructor by default
    t2.getinfo();

    Student s1("harshit",9.8);
    Student s2(s1);

    s1.getinfo();
    *s2.cgpaptr = 9.2;
    s1.getinfo(); 

    return 0;
}
