#include <iostream>
using namespace std;
class node
{
    public:
    int value;
    node* next;
}*first=NULL;


// this is a comment
void count(node* head)
{
    int count=0;
    if (head==NULL)
    {
        cout<<"list is empty "<<endl;
    }
    else
    {
        node* temp=new node;
        temp=head;
        while (temp!=NULL)
        {
            cout<<temp->value<<" -> ";
            count++;
            temp=temp->next;
            
        }
        cout<<endl;
        cout<<" total no of link = "<<count<<endl;
        
    }
   
}
void create(int a[],int s)
{
    node *p,*last;
    first=new node;
    first->value=a[0];
    first->next=NULL;
    last=first;
    for (int i = 1; i <=s; i++)
    {
        p=new node;
        p->value=a[i];
        p->next=NULL;
        last->next=p;
        last=p;
    }
    
}
void display(node *d)
{
    
    while (d!=NULL)
    {
        cout<<d->value<<"->";
        d=d->next;
    }
    cout<<endl;
    
}
int main()
{
    int a[5]={12,34,5,67,7};
    int s=5;
    create(a,s);
    display(first);

    return 0;
}
