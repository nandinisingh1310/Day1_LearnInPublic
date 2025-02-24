#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
class CircularLL{
public:
    Node* head;
    Node* tail;
    CircularLL(){
        head = tail = NULL;
    }
    void insertathead(int val){
        Node* newnode = new Node(val);
        if(head == NULL){
            head = tail = newnode;
            tail -> next = head;
            //can also write newnode
        }else{
            newnode -> next = head;
            head = newnode;
            tail -> next = head; 

            //if we didn't have a head 
            //newnode -> next = tail -> next;
            //tail -> next = tail;
        }
    }
    void insertattail(int val){
        Node* newnode = new Node(val);
        if(head == NULL){
            head = tail = newnode;
        }else{
            newnode -> next = head;
            tail -> next = newnode;
            tail = newnode;
        }
    }
    void deleteathead(){
        Node* temp = head;
        if(head == NULL){
            cout<< "LL IS EMPTY";
        }
        if(head == tail){ //single node
            delete head;
            head = tail = NULL; 
        }else{ //2 or more
            head = head -> next;
            tail -> next = head;
            temp -> next = NULL;
            delete temp;

        }
    }
    void deleteattail(){
        Node* temp = tail;
        if(head == NULL){
            cout << "LL is empty";
            return;
        }
        if(head == tail){
            delete head;
            head = tail = NULL;
        }else{
            Node* prev = head;
            while(prev -> next != tail){
                prev = prev -> next;
            }
            tail = prev;
            tail -> next = head;
            temp -> next = NULL;
            delete temp;

        }

    }
    void print(){
        if(head == NULL)return;
        cout << head->data << "->";
        Node* temp = head -> next;
        while(temp != head){
            cout << temp -> data << " -> " ;
            temp = temp -> next;
        }
    }
};
int main(){
CircularLL l1;
l1.insertathead(1);
l1.insertathead(2);
l1.insertathead(3);
l1.insertathead(0);
l1.insertattail(4);
l1.insertattail(5);
l1.insertattail(6);
l1.insertattail(0);
l1.print();
// l1.deleteathead();
// cout << endl;
// l1.print();
// cout << endl;
l1.deleteattail();
cout<<endl;
l1.print();
}