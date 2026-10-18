#include<iostream>
using namespace std;

// Time Complexity: O(1) for push, pop, front, empty
// Space Complexity: O(cap) - dynamically allocated array of size cap
class circular{
    int * arr;
    int currsize,cap;
    int f ,r;
    public:
    circular(int size){
        cap = size;
        arr = new int[cap];
        currsize = 0;
        f = 0;
        r =-1;
    }
    void push( int data){
        if(currsize ==  cap){
            cout << "queue is full\n" ;
            return ;
        }
        r = (r+1)%cap;
        arr[r] = data;
        currsize ++ ;
    }

    void pop(){
        if(empty()){
            cout << "queue is empty\n";
            return ;
        }
        f = (f+1)%cap;
        currsize--;
    }
    int front(){
       if(empty()){
            cout << "queue is empty\n";
            return -1 ;
        }
        return arr[f];
    }

    bool empty(){
        return currsize == 0;
    }
    void print(){
        for (int i = 0; i < currsize; i++) {
            cout << arr[(f + i) % cap] << " ";
        }
        cout << endl;
    }

    ~circular() {
        delete[] arr;
    }
};

int main(){
    circular c(3);
    c.push(1);
    c.push(2);
    c.push(3);
    c.pop();
    c.push(4);
    c.print();
    while(!c.empty()){
        cout << c.front() << " ";
        c.pop();
    }
    cout << endl;
    return 0;
}