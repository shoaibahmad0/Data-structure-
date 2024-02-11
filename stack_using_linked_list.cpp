#include <iostream>
using namespace std;
struct stack_node
{
  int data;
  stack_node *next;
};

stack_node *top=NULL;


void push(int x)
{
  stack_node *t=new stack_node;
  if (t==NULL)
  {
    cout<<"stack over flow "<<endl;
  }
  else
  {
    t->data=x;
    t->next=top;
    top=t;
  }
}

int pop()
{
    stack_node *temp;
    int x=-1;
    if (top==NULL)
    {
        cout<<"stack underflow "<<endl;
    }
    else
    {
        temp=top;
        top=top->next;
        x=temp->data;
        delete temp;
    }
    return x; 
}
void display()
{
    stack_node *current=top;
    while (current!=NULL)
    {
        cout<<current->data<<" -> ";
        current=current->next;
    }
    cout<<endl;
    
}
int main()
{
    
    int ch,val;
    int result;
    do
    {
        cout<<"*****************OPERATION ON STACK*******************"<<endl;
        cout<<endl<<endl;
        cout<<"1 remove an item"<<endl;
        cout<<"2 add an item "<<endl;
        cout<<"3 display the stack"<<endl;
        cout<<"0 exit "<<endl;
        cout<<"enter your choice "<<endl;
        cin>>ch;
        switch (ch)
        {
        case 1:
            result=pop();
            if (result==-1)
            {
                cout<<"stack underflow "<<endl;
            }
            else
            {
                cout<<"the deleted element is "<<result<<endl;
            }
            
            break;
        case 2:
            cout<<"enter the value "<<endl;
            cin>>val;
            push(val);
            break;
        case 3:
            display();
            break;
        default:
            break;
        }
    } while (ch!=0);
    
    return 0;
}