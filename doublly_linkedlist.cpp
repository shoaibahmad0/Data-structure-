#include <iostream>
using namespace std;


struct node{
    node* prev;
    int data;
    node* next;
}*first=NULL;

//function for creating a doublly linkedlis

 //function for searching in a doublly linkedlist

 bool search(int val)
 {
    node* currentnode=first;
    while (currentnode!=NULL)
    {
        if (currentnode->data==val)
        {
            return true;
        }
        currentnode=currentnode->next;
    }
    
    return false;
 }
  // function for inserting at the start of the linkedlist , the end of the linked 
  // list and between any two nodes

 void insert(int val, int pos) {
    int n = 9;
    node *t;
    if (pos < 0 || pos > n) {
        return;
    }
    t = new node;
    t->data = val;
    if (pos == 0) {
        t->prev = nullptr;
        t->next = first;
        if (first != nullptr) {
            first->prev = t;
        }
        first = t;
    } else {
        node *p = first;
        for (int i = 0; i < pos - 1; i++) {
            if (p == nullptr) {
                return; 
            }
            p = p->next;
        }
        t->next = p->next;
        t->prev = p;
        if (p->next != nullptr) {
            p->next->prev = t;
        }
        p->next = t;
    }
}

    //function for printing the doubley linked list

  void display(node *p)
  {    
    while (p!=NULL)
    {
        cout<<p->data<<"-> ";
        p=p->next;
    }
    
  }

  int main()
  {
    insert(10,0);
    insert(20,1);
    insert(30,2);
    display(first);
    cout<<endl;
    bool res=search(30);
    if (res==true)
    {
         cout<<"element found"<<endl;
    }
    else
    {
        cout<<"element not found "<<endl;
    }
    
    return 0;
  }