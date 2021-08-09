#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
} ;

node* insert_begin(node* ,int );
node* insert_end(node* head, int data);
node* delete_begin(node* head);
node* delete_end(node* head);
void display(node* head);


node* create(node* head, int value){
    node* nptr = (node*)malloc(sizeof(node));
    nptr->data = value;
    nptr->next = NULL;
    return nptr;
}

int main(){
    node* Head = NULL;
    Head = insert_begin(Head,10);
    Head = insert_begin(Head,5);
    Head = insert_end(Head,30);
    Head = insert_end(Head,50);
    Head = insert_begin(Head,1);
    display(Head);
    Head = delete_begin(Head);
    display(Head);
    Head = delete_end(Head);
    display(Head);
}

node* insert_begin(node* head, int data){
    node* np = create(head,data);
    if(head == NULL){
        head = np;
        return head;
    }
    np->next = head;
    head = np;
    return head;
}

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<< temp->data <<" ";
        temp = temp->next;
    }
    cout<<"\n";
}

node* insert_end(node* head, int data){
    node* np = create(head,data);
    if(head == NULL){
        head = np;
        return head;
    }
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = np;
    return head;
}

node* delete_begin(node* head){
    if(head == NULL){
        cout<<"List is empty.";
        return head;
    }
    node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

node* delete_end(node* head){
    if(head == NULL){
        cout<<"List is empty.";
        return head;
    }
    node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}
