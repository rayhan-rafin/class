#include<bits/stdc++.h>
using namespace std;

void createlist(int n);
void display();
void insertAtEnd();
void DeleteFromEnd();
struct node
{
    int data;
    struct node *next;
}*head;

int main ()
{
    int i,n,position;
    cout<<"Enter initial number: ";
    cin>>n;
    createlist(n);
    cout<<"Data in the list are: "<<endl;
    display();
    for ( ; ;)
    {
        cout<<endl;
        cout<<"Enter a command"<<endl;
        cout<<"1.insert"<<endl;
        cout<<"2.delete"<<endl;
        cout<<"3.display"<<endl;
        cout<<"4.end program"<<endl<<endl;
        cin >>i;
        if (i==1)
        {
            insertAtEnd();
        }
        else if (i==2)
        {
            DeleteFromEnd();
        }
        else if(i==3)
        {
            cout<<"Data in new list are: "<<endl;
            display();
        }
        else {
            break;
        }
    }
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

