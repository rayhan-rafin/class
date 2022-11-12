#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*head;

void createlist(int n);
void displaylist ();
void searchitem(int x);
void countlist();

int main ()
{
    int n,x;
    cout<<"enter the number of list"<<endl;
    cin>>n;
    createlist(n);
//    displaylist ();
//    cout<<"enter search item"<<endl;
//    cin>>x;
//    searchitem(x);
    countlist();
}

void createlist(int n)
{
    struct node *current,*newnode;
    head = (struct node*)malloc(sizeof(struct node));
    cin>>head->data;
    head->next= NULL;
    current=head;
    for (int i =1; i<n; i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        cin>>newnode->data;
        newnode->next = NULL;
        current->next = newnode;
        current = newnode;
    }
}

void displaylist ()
{
    struct node *current;
    current = head;
    cout<<endl;
    while (current!=NULL)
    {
        cout<<current->data<<endl;;
        current=current->next;
    }
}
void searchitem(int x)
{
    struct node *current;
    current = head;
    int i =1;
    while (current!=NULL)
    {
        if (current->data == x)
        {
            cout<<"Found"<<endl;
            cout<<i<<endl;
            break;
        }
        current = current->next;
        i++;
    }
    if (current==NULL)
    {
        cout<<"not found"<<endl;
    }
}

void countlist()
{
    struct node *current;
    current = head;
    int i = 0;
    while (current!=NULL)
    {
        current=current->next;
        i++;
    }
    cout<<"count is "<<i<<endl;
}
