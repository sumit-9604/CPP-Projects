#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;

    node(int val){
        data = val;
        next = NULL;
    }

};

class circularll{
    node* head;
    node* tail;

    public:
        circularll(){
        head = tail = NULL;}

        void inserthead(int val){
            node* newnode = new node(val);
            if (head == NULL)
            {
                head = tail = newnode;
                tail -> next = head;
            }else{
                newnode -> next = tail -> next;  // head = tail na next 
                tail -> next = newnode;}}
        
        void print(){

            node* temp = head -> next;
            while(temp != head){
                cout<<temp->data<<endl;
                temp = temp-> next;}
            cout<<temp->data<<endl;}

        void inserttail(int val){

            node* newnode = new node(val);
            if (head == NULL){

                head = tail = NULL;
                tail -> next = head;
            }else{
                newnode ->next = head;
                tail -> next = newnode;
                tail = newnode;}}

        void popfront(){

            if (head == NULL){return;}

            else if(head != NULL && head != tail){
                node* temp = head;
                head = head -> next;  // firts update head
                tail -> next = head;
                temp -> next = NULL;
                delete temp;}

            else{
                delete head;
                head = tail = NULL;}}
        
        void poptail(){

            if(head == NULL){return;}

            else if(head != NULL && head!= tail){
                node* temp  = tail;
                node* prev = head;
                while (prev -> next != tail){
                    prev -> next = tail;}
                tail = prev;
                tail -> next = head;
                temp -> next = NULL;
                delete temp;}

            else{
                delete tail;
                head = tail = NULL;}}
                

};


int main(){
    circularll cll;
    cll.inserthead(5);
    cll.inserthead(4);
    cll.inserthead(3);
    cll.inserthead(2);
    cll.inserthead(1);
    cll.print();
}