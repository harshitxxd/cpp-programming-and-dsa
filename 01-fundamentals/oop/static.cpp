#include<iostream>
#include<string>
using namespace std;

// Time Complexity: O(n)
void fun(){
    static int x = 0;
    int y = 0;
    cout << "y : " <<  y << endl;
    cout << "x : "<< x << endl;
    cout << endl;
    x++;
    y++;
}
class A {
    public :
    int a;
    void inca(){
        a = a+1;
      
    }
};

class abc{
    public :
    abc(){
        cout << "constructor \n";
    }

    ~abc(){
        cout << "destructor \n";
    }
};

int main(){
    if(true){
        abc obj; 
    }
    cout << "end of the main function \n";
    cout << endl;
    if(true){
        static abc obj1;
    }
    cout << "end of the main function \n";
    cout << endl;
    A a;
    a.a = 0;
    cout << a.a << endl;
    a.inca();
    cout << a.a << endl;
    cout << endl;
    fun();
    fun();
    fun();
    return 0;
 
}


