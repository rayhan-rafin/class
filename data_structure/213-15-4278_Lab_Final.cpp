#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*head;

void createlist (int n);
void displaylist();
void deleteAtEnd();
void deleteAtPos(int x);

int main()
{
    int m,n,position;
    cout<<"Enter list number"<<endl;
    cin>>n;
    createlist (n);
    displaylist();
    cout<<endl;
    while (1)
    {
        cout<<endl;
        cout<<"Enter function to perform"<<endl;
        cout<<"1. deleting at end"<<endl;
        cout<<"2. deleting at fixed position"<<endl;
        cout<<"3. display the list"<<endl;
        cout<<"4. close"<<endl;
        cin>>m;
        if (m==1)
        {
            deleteAtEnd();
            cout<<"deleted at end"<<endl;
        }
        else if (m==2)
        {
            cout<<"Enter the position you want to delete"<<endl;
            cin>>position;
            deleteAtPos(position);
            cout<<"deleted at position"<<endl;
        }
        else if (m==3)
        {
            displaylist();
        }
        else
        {
            break;
        }

    }
    cout<<endl;
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
void displaylist()
{
    struct node *current;
    current = head;
    cout<<"values in the list are:"<<endl;
    while (current!=NULL)
    {
        cout<<current->data<<" ";
        current = current->next;
    }
    cout<<endl<<endl;
}

void deleteAtEnd()
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
void deleteAtPos(int position)
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
