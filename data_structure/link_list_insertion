#include<bits/stdc++.h>
using namespace std;

void createlist(int n);
void display();
void insertAtBegining();
void insertAtEnd();
void insertAtMid(int position);
struct node
{
    int data;
    struct node *next;
}*head;

int main ()
{
    int n,position;
    cout<<"Enter number: ";
    cin>>n;
    createlist(n);
    cout<<"Data in the list are: "<<endl;
    display();
    insertAtBegining();
    cout<<"Data in the new list are: "<<endl;
    display();
    cout<<"Enter the position where you want to insert your newnode"<<endl;
    cin>>position;
    insertAtMid(position);
    cout<<"Data in new list are: "<<endl;
    display();
    insertAtEnd();
    cout<<"Data in new list are: "<<endl;
    display();
    return 0;
}

void createlist(int n)
{
    struct node *newnode,*current;
    int value,i;
    head = (struct node*)malloc(sizeof(struct node));
    if (head == NULL)
    {
        cout<<"Memory is full"<<endl;
    }
    else
    {
        cout<<"Enter first value of list"<<endl;
        cin>>value;
        head->data = value;
        head->next = NULL;
        current = head;
        for (i=1; i<n; i++)
        {
            newnode = (struct node*)malloc(sizeof(struct node));
            cout<<"Enter value "<<i+1<<endl;
            cin>> newnode->data;
            newnode->next = NULL;
            current->next = newnode;
            current = newnode;
        }
    }
}
void insertAtBegining()
{
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    cout<<"Enter the value you want to insert at the begining"<<endl;
    cin>>newnode->data;
    newnode->next = head;
    head = newnode;
}

void insertAtMid(int position)
{
    struct node *current,*newnode;
    current = head;
    for (int i =1;i<position-1;i++){
        current = current->next;
    }
    newnode = (struct node*)malloc(sizeof(struct node));
    cout<<"Enter the value you want to insert in the linked list"<<endl;
    cin>>newnode->data;
    newnode->next = current->next;
    current->next = newnode;
}

void insertAtEnd()
{
    struct node *current,*newnode;
    current=head;
    while(current->next!=NULL)
    {
        current = current->next;
    }
    newnode = (struct node*)malloc(sizeof(struct node));
    cout<<"Enter the value you want to insert at the End"<<endl;
    cin>>newnode->data;
    newnode->next = NULL;
    current->next = newnode;
}

void display ( )
{
    struct node *current;
    current=head;
    while(current!=NULL)
    {
        cout<<current->data<<endl;
        current = current->next;
    }
}
