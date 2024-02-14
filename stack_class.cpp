#include <iostream>
using namespace std;
class stack_class
{
private:
    int size;
    int top;
    int *s;
public:
    stack_class()
    {
        size=5;
        top=-1;
        s=new int[size];
    };
    stack_class(int si,int t);
    
    void push(int x);
    int pop();
    bool isfull();
    bool isempty();
    int peak(int no);
    void display();
    ~stack_class()
    {
      delete[] s;
    }

};
bool stack_class::isfull()
{
    if (top==size-1)
    {
        return true;
    }
    else
    {
        return false;
    }    
}
bool stack_class::isempty()
{
    if (top==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

stack_class::stack_class(int si,int t)
{
    size=si;
    top=t;
    s=new int[size];
}
void stack_class::push(int x)
{
    if (isfull()==1)
    {
        cout<<"stack overflow "<<endl;
    }
    else
    {
        top++;
        s[top]=x;
    }
    
}
int stack_class::pop()
{
    int x=-1;
    if (isempty()==1)
    {
        cout<<"stack underflow"<<endl;
        return x;
    }
    else
    {
        x=s[top];
        top--;
    }
    return x;
}
int stack_class::peak(int no)
{
   if (no < 0 || no > size)
   {
     cout<<"Invalid position"<<endl;
     return -1;
   }
   else
   {
     return s[no]; 
   }
}
void stack_class::display()
{
    for (int i = top; i >=0; i--)
    {
        cout<<s[i]<<" "<<endl;
    }
    cout<<endl;
}

int main()
{
    stack_class s(5,-1);
    int ch,add,rem,res;
    cout<<endl<<endl<<endl;
    cout<<"*********************OPERATION ON STACK*************************"<<endl;
    do
    {   cout<<"****choose 1 to 5 and 0 for exit "<<endl<<endl<<endl;
        cout<<"1 is full ? "<<endl;
        cout<<"2 is empty ? "<<endl;
        cout<<"3 add element "<<endl;
        cout<<"4 remove item  "<<endl;
        cout<<"5 check item in position "<<endl;
        cout<<"0 exit "<<endl;
        cout<<"enter your choice "<<endl;
        cin>>ch;
        switch (ch)
        {
        case 1:
          if (s.isfull())
          {
            cout<<"stack overflow "<<endl;
          }
          else
          {
            cout<<"not full "<<endl;
          }   
            break;
        case 2:
        if (s.isempty())
        {
              cout<<"stack underflow "<<endl;
        }
        else
        {
            cout<<"not empty"<<endl;
        }
        break;
        case 3:
              cout<<"Add the number "<<endl;
              cin>>add;
              s.push(add);
        break;
        case 4:
              s.pop();
        break;
        case 5:
             cout<<"enter the position of an item "<<endl;
             cin>>rem;
             res=s.peak(rem);
          break;

        default:
            break;
        }
    } while (ch!=0);
    cout<<endl<<endl<<endl;
    s.display();
    
   /* s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    if (s.isfull())
    {
        cout<<"stack overflow "<<endl;
    }
    else
    {
        cout<<"not full "<<endl;
    }
    if (s.isempty())
    {
        cout<<"stack underflow "<<endl;
    }
    else
    {
        cout<<"not empty"<<endl;
    }
    s.display();
    cout<<"the deleted element is  "<<s.pop()<<endl;
    cout <<"after deleting the top element "<<endl;
    s.display();*/
    
    
    return 0;
}