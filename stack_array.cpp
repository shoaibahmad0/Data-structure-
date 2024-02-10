#include <iostream>
using namespace std;


struct stack
{
    int size;
    int top;
    int *s;
};


void create(struct stack *st)
{
    cout<<"enter the size of stack "<<endl;
    cin>>st->size;
    st->top=-1;
    st->s=new int[st->size];

}
void display(struct stack st)
{
    for (int i = st.top; i >= 0; i--)
    {
        cout<<st.s[i]<<" ";
    }
    cout<<endl;
}
void push(stack *st,int x)
{
    if (st->top==st->size-1)
    {
        cout<<"stack overflow "<<endl;
    }
    else 
    {
        st->top++;
        st->s[st->top]=x;
    }
    
}
int pop(struct stack *st)
{
    int x=-1;
    if (st->top==-1)
    {
        cout<<"the stack is under flow "<<endl;
    }
    else
    {
        x=st->s[st->top--];
        
    }
    return x;
}
int isempty(struct stack st)
{
    if (st.top==-1)
    {
        return 1;
    }
    return 0;
}
int isfull(struct stack st)
{
    return st.top==st.size-1;
}
int stacktop(struct stack st)
{
    if (!isempty(st))
    {
        return st.s[st.top];
    }
    return -1;
}
int peak(stack st,int pos)
{
    int x=-1;
    if (st.top-pos+1<0)
    {
        cout<<"stack underflow "<<endl;
    }
    else
    {
        x=st.top-pos+1;
    }
    return x;
}
int main()
{
    struct stack st;
    create(&st);
    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    push(&st,50);
    display(st);
    int result=pop(&st);
    if (result==-1)
    {
        cout<<"stack underflow "<<endl;
    }
    else
    {
        cout<<"the deleted element is "<<result<<endl;
    }
    display(st);
    
    return 0;
}