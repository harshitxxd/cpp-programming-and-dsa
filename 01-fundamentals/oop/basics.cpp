#include<iostream>
#include<string>

using namespace std;

// Time Complexity: O(n)
class Teacher{
    private :
    double salary;

    public :   
    string name ;
    string department ;
    string subject;
    

    void change_department(string newdpart){
        department = newdpart;
    } 

    void setsalary(int s){
        salary = s;
    }

    double getsalary(){
        return salary;
    }
};

int main(){
    Teacher t1;
    t1.name = "shradha";
    t1.subject = "C++";
    t1.setsalary(25000);
    cout << t1.getsalary()<< endl;
    t1.change_department("computer science");
    cout << t1.name << endl;
    cout << t1.department << endl;
    return 0;
}
