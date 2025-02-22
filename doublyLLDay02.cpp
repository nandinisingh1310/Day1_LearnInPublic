#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};
class DoublyList{
    Node* head;
    Node* tail;
public:
    DoublyList(){
        head = tail = NULL;
    }
    void push_front(int val){
        Node* newnode = new Node(val);
        if(head == NULL){
            head = tail = newnode;  
        }
        else{
            newnode -> next = head;
            head -> prev = newnode;
            head = newnode;
        }
    }
    void push_back(int val){
        Node*  newnode = new Node(val);
        if(head == NULL){
            head = tail = newnode;
        }else{
            newnode -> prev = tail;
            tail -> next = newnode;
            tail = newnode;
        }
    }
    void pop_front(){
        //can add the condition if the LL is empty simply caan print LL is empty
        Node* temp = head;
        head = head -> next;
        if(head!=NULL){
            head -> prev = NULL;
        }
        temp -> next = NULL;
        delete temp;
    }
    void pop_back(){
        // add condition if it is empty i mean the linkedlist
        Node* temp = tail;
        tail = tail -> prev;
        if(tail!=NULL){
            tail -> next = NULL;
        }
        temp -> prev = NULL;
        delete temp;
    }
    void print(){
        Node* temp = head;
        while(temp!=NULL){
            cout << temp->data << " -> " ; 
            temp = temp -> next;
        }
    }
};
int main(){
DoublyList dll;
dll.push_front(69);
dll.push_front(67);
dll.push_front(457);
dll.push_back(23238);
dll.push_back(7478);
dll.pop_front();
dll.pop_back();



dll.print();
}