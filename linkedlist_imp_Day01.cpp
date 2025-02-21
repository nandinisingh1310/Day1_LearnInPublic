#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data, Node* next = NULL){
        this->data = data;
        this->next = NULL;
    }
};
class List{
    Node* head;
    Node* tail;
public:
    List(){
        head = tail = NULL;
    }
    void push_front(int val){
        Node* newnode = new Node(val); //dynamic still be there after function call unlike static will be remved after fubction call
    //     Node newNode(val); //static
        if(head == NULL){
            head = tail = newnode;
            return;
        }else{
            newnode -> next = head;
            head = newnode;
        }
    }
    void push_back(int val){
        Node* newnode = new Node(val);
        if(head == NULL){
            head = tail = newnode;
            return;
        }
        else{
            tail -> next = newnode;
            tail = newnode;
        }
    }
    void pop_front(){
        if(head == NULL){
            cout<<"LL IS EMPTY\n";
            return;
        }else{
            Node* temp = head;
            head = head -> next;
            temp->next = NULL;
            delete temp;
        }
    }
    void pop_back(){
        if(head == NULL){
            cout<<"LL IS EMPTY\n";
            return;
        }else{
            Node* temp = head;
            while(temp->next != tail){
                temp = temp->next;
            }
            temp->next = NULL;
            delete tail;
            tail = temp;
        }
    }
    void insertatmiddle(int val, int pos){
        if(pos < 0){
            cout << "Invalid Case\n";
            return;
        }
        if(pos == 0){
            push_front(val);
            return;
        }
        Node* temp = head;
        for(int i = 0; i < pos-1; i++){
            if(temp == NULL){
                cout<<"INVALID POSIT\n";
                return;
            }
            temp = temp -> next;
        }
        Node* newnode = new Node(val);
        newnode->next = temp->next;
        temp->next = newnode;
    }
    void printLL(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp -> data <<  " ";
            temp = temp -> next;
        }
        cout << endl;
    }
    int search(int key){
        Node* temp = head;
        int idx = 0;
        while(temp != NULL){
            if(temp->data==key){
                return idx;
            }
            temp = temp->next;
            idx++;

        }
        return -1; 
    }
};
int main(){
    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.insertatmiddle(4,0);
    cout << ll.search(2) << endl;
    ll.printLL();
    cout << ll.search(2) << endl;

}
