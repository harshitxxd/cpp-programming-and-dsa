#include<iostream>
using namespace std;

// Time Complexity: O(n)
class node{
    public:
    int data;
    node* next ;

    node(int val){
        data = val; 
        next = NULL;
    }
};

class list { 
    node* head;
    node* tail;

    public :
    list(){
        head = tail = NULL;
    }

    void push_front(int val){
        node* newnode = new node(val); //dynamic 
        // node newnode(val); //static
        if(head == NULL){
            head = tail = newnode;
            return ;
        }
        else {
            newnode ->next = head;
            head = newnode;
        }
    }

    void push_back(int val){
        node* newnode = new node(val);
        if (head == NULL){
            head = tail = newnode;
        }
        else {
            tail -> next = newnode;
            tail = newnode;
        }
    }

    void pop_front(){
        if(head == NULL){
            cout << "ll is emoty \n";
            return ;
        }

        node* temp = head ;
        head = head ->next;

        if (head == NULL) {
        tail = NULL;
        }

        temp -> next = NULL;

        delete temp;
    }

    void pop_back(){
        if(head == NULL ){
            cout << "ll i emoty \n";
            return;
        }
        
        if (head == tail) {
        delete head;
        head = tail = NULL; // Both pointers must reset to NULL
        return;
        }
        node* temp = head;
        while (temp -> next != tail){
            temp = temp->next ;
        }
        temp ->next = NULL;
        delete tail;
        tail = temp;
    }

    void insert(int val , int pos){
        if(pos < 0){
            cout << "invlaid pos \n";
            return ;
        }
        if(pos == 0){
            push_front(val);
            return;
        }

        node* temp = head ;
        for(int i = 0 ; i < pos -1;i++){
            if(temp == NULL){
                cout << "invalid pos \n";
                return ;
            }
            temp = temp ->next;
        }
        node* newnode = new node(val);
        newnode ->next = temp ->next;
        temp -> next = newnode;
    }

    void print(){
        node* temp = head;

        while (temp != NULL){
            cout << temp ->data << " ";
            temp = temp-> next;
        }
        cout << "NULL" << endl;

    }

    int search(int key){
        node* temp = head;
        int idx = 0;
        while (temp != NULL){
            if(temp ->data == key){
                return idx ;
            }
            temp = temp->next;
            idx++;
        }        
        return -1;
    }

};

int main(){
    list ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_back(4);
    
    ll.pop_front();
    ll.pop_back();

    ll.insert(4,0);
    ll.insert(3,1);

    cout << ll.search(4) << endl;

    ll.print();
    return 0;
}