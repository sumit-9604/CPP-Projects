#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;}};



class doublylinklist{
    Node *head;
    Node *tail;

public:
    doublylinklist(){
        head = tail = NULL;}

    void push_front(int val){
        Node *newnode = new Node(val);

        if (head == NULL)
        {
            head = tail = newnode;
        }else{
            newnode -> next = head;
            head -> prev = newnode;
            head = newnode;}}

    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<endl;
            temp = temp-> next;}}

    void push_back(int val){
        Node* newnode = new Node(val);

        if (head == NULL)
        {
            head = tail = newnode;
        }else{
            newnode -> prev = tail;
            tail -> next = newnode;
            tail = newnode;}}

        void pop_front(){
            Node* temp = head;
            head = head -> next;
            if(head != NULL){
                head -> prev = NULL;}
            temp -> next = NULL;
            delete temp;}

        void pop_back(){
            Node* temp = tail;
            tail = tail -> prev;

            if (tail != NULL)
            {
                tail -> next = NULL; 
                temp -> prev = NULL;
                delete temp;

            }
            
        }
};






int main(){

    doublylinklist dll;
    dll.push_front(5);
    dll.push_front(4);
    dll.push_front(3);
    dll.push_front(2);
    dll.push_front(1);
    dll.print();
    dll.pop_front();


}
