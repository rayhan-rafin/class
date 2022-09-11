#include<bits/stdc++.h>
using namespace std;

void createlist(int n);
void display();
void insertAtBegining();
void insertAtEnd();
void insertAtMid(int position);
void DeleteFromBegining();
void DeleteFromEnd();
void DeleteFromMid(int position);
void searching (int searchitem);

struct node
{
    int data;
    struct node *next;
}*head;

int main ()
{
    int n,position,value;
    cout<<"Enter number: ";
    cin>>n;
    createlist(n);
    cout<<"Data in the list are: "<<endl;
    display();
//    insertAtBegining();
//    cout<<"Data in the new list are: "<<endl;
//    display();
//    cout<<"Enter the position where you want to insert your newnode"<<endl;
//    cin>>position;
//    insertAtMid(position);
//    cout<<"Data in new list are: "<<endl;
//    display();
//    insertAtEnd();
//    cout<<"Data in new list are: "<<endl;
//    display();
//    DeleteFromBegining();
//    cout<<"Data in new list are: "<<endl;
//    display();
//    cout<<"Enter the position you want to delete"<<endl;
//    cin>>position;
//    DeleteFromMid(position);
//    cout<<"Data in new list are: "<<endl;
//    display();
//    DeleteFromEnd();
//    cout<<"Data in new list are: "<<endl;
//    display();
    cout<<"Enter the value you want to search"<<endl;
    cin>>value;
    searching (value);
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
    for (int i =1; i<position-1; i++)
    {
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

void DeleteFromBegining()
{
    struct node *current;
    current = head;
    head = head->next;
    free(current);
}

void DeleteFromMid(int position)
{
    struct node *current,*previous;
    current = head;
    for (int i=1; i<position; i++)
    {
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    free(current);
}

void DeleteFromEnd()
{
    struct node *current,*previous;
    current = head;
    while (current->next!=NULL)
    {
        previous = current;
        current  = current->next;
    }
    free(current);
    previous->next = NULL;
}

void searching (int searchitem)
{
    struct node *current;
    current = head;
    int i = 0;
    while (current != NULL)
    {
        if (searchitem == current -> data)
        {
            cout<<"Search item is found"<<endl;
            break;
        }
        else
        {
            current = current->next;
        }
    }
    if (current == NULL)
    {
        cout<<"Search item is not found"<<endl;
    }
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
