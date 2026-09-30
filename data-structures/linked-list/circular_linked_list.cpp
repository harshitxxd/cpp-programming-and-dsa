#include<iostream>
using namespace std;

// Time Complexity: O(n)
class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

class circular{
    node* head;
    node* tail;

    public:
    circular(){
        head = tail = NULL;
    }

    void insert_head(int val){
        node* newnode = new node(val);
        if(head == NULL){
            head = tail = newnode;
            tail->next = head ;
        }
        else{    
            newnode->next = head;
            head = newnode;
            tail->next = head;

            // if head is not given
            // newnode->next = tail->next
            // tail->next = newnode
        }
    }

    void insert_tail(int val){
        node* newnode = new node(val);
        if(head == NULL){
            head = tail = newnode;
            tail->next = head ;
        }        
        else {
            newnode->next = head;
            tail->next = newnode;
            tail = newnode;
        }
    }

    void delete_head(){
        if(head == NULL){
            cout << "is empty\n";
            return ;
        }
        else if(head == NULL){
            delete head;
            head = tail = NULL;
        }
        else {
        node* temp = head;
        head = head->next;
        tail->next = head; 
        temp->next = NULL;
        delete temp;
        }
    }

    void delete_tail(){
         if(head == NULL){
            cout << "is empty\n";
            return ;
        }
        else if(head == NULL){
            delete head;
            head = tail = NULL;
        }
        else{
            node* temp = tail;
            node* prev = head;
            while (prev->next != tail){
                prev = prev->next;
            }
            tail = prev;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
    }

    void print(){
        if(head == NULL) return ;

        cout << head->data <<"->";
        node* temp= head->next;

        while(temp != head){
            cout << temp -> data << " ->";
            temp  = temp->next;
        }

        cout << temp->data << endl;
    }
};

int main(){
    circular cll;
    cll.insert_head(1);
    cll.insert_head(2);
    cll.insert_head(3);
    cll.insert_tail(4);
    cll.print();
    cout << endl;
    cll.delete_head();
    cll.delete_tail();
    cll.print();
    return 0;
}
