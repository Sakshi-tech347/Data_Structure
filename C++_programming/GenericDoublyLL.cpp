#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node <T>* next;
    struct node <T>* prev;
};
 

template <class T>
class DoublyLL
{
    private:
        T iCount;
        struct node <T>* first;

    public:
    DoublyLL();
    

    void Display();
   

    int Count();
   

    void InsertFirst( T no);
  

    void InsertLast(T  no);
 

    void InsertAtPos( T no , int pos);
  

    void DeleteFirst();
 

    void DeleteLast();
 

    void DeleteAtPos(int pos);
   
};

template <class T>
DoublyLL <T>:: DoublyLL()
{
cout<<"object gets created succefully \n";
iCount = 0;
first = NULL;
}

template <class T>
void DoublyLL <T>::Display()
{
struct node <T>* temp = NULL;
temp = first;
while(temp != NULL)

{
    cout<<"|"<<temp->data<<"|<=>";
    temp = temp->next;

}
cout<<"NULL\n";

}

template <class T>
int DoublyLL <T> :: Count()
{
return iCount;
}

template <class T>
void DoublyLL <T> ::InsertFirst( T no)
{
struct node <T>* newn = NULL;
newn = new struct node <T>;
newn -> data = no;
newn ->prev = NULL;
newn ->next = NULL;

if(first == NULL)
{
    first =newn;
}
else
{
    newn ->next = first;
    first ->prev = newn;

    first = newn;

}
iCount++;


}

template <class T>
void DoublyLL <T> ::InsertLast( T no)
{
struct node <T>* newn = NULL;
struct node <T>* temp = NULL;

newn = new struct node <T>;
newn -> data = no;
newn ->prev = NULL;
newn ->next = NULL;

if(first == NULL)
{
    first =newn;
}
else
{
    temp = first;

    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }

    temp ->next = newn;
    newn ->prev = temp;

        

}
iCount++;
}

template <class T>
void DoublyLL <T> ::InsertAtPos( T no , int pos)
{
struct node <T>* newn = NULL;
struct node <T>* temp = NULL;



int i = 0 ;

if(pos < 1 || pos > iCount + 1)
{
    cout<<"Invalid position \n";

}
if(pos == 1)
{
    InsertFirst(no);
}
else if(pos == iCount + 1)
{
    InsertLast(no);

}
else
{
    newn = new struct node <T>;
    newn -> data = no;
    newn ->prev = NULL;
    newn ->next = NULL;
    temp = first;

    for (i = 1 ; i < pos - 1 ; i++)
    {
        temp = temp -> next;
    }
    newn->next = temp->next;
    temp->next->prev = newn;

    temp->next =newn;
    newn->prev = temp;

    

}
iCount++;
}

template <class T>
void DoublyLL <T> ::DeleteFirst()
{
struct node <T>* temp = NULL;


if(first == NULL)
{
    return ;
}
else if(first -> next == NULL)
{
    delete(first);
    first = NULL;
}
else
{
    temp = first;
    first = first ->next;
    delete(temp);
}

iCount--;
}

template <class T>
void DoublyLL <T> ::DeleteLast()
{
struct node <T>* temp = NULL;

if(first == NULL)
{
    return ;
}
else if(first -> next == NULL)
{
    delete(first);
    first = NULL;
}
else
{
    temp = first;
    while(temp ->next ->next != NULL)
    {
        temp = temp ->next;
    }
    delete(temp->next);
    temp->next = NULL;

}

iCount--;
}

template <class T>
void DoublyLL <T> ::DeleteAtPos(int pos)
{
struct node <T>* newn = NULL;
struct node <T>* temp = NULL;
struct node <T>*target = NULL;

int i = 0 ;

if(pos < 1 || pos > iCount + 1)
{
    cout<<"Invalid position \n";

}
if(pos == 1)
{
    DeleteFirst();
}
else if(pos == iCount + 1)
{
    DeleteLast();

}
else
{
        
    temp = first;

    for (i = 1 ; i < pos - 1 ; i++)
    {
        temp = temp -> next;
    }
    target = temp -> next;

    temp -> next -> prev = temp;
    temp ->next = temp -> next ->next;

    delete(target);



}
iCount--;
}


int main()
{

    
    DoublyLL <char>dobj;
    int iRet = 0;

    dobj.InsertFirst('L');
    dobj.InsertFirst('E');
    dobj.InsertFirst('H');
    dobj.Display();
    iRet = dobj.Count();
    cout<<"number of nodes are : "<<iRet<<"\n";

    dobj.InsertLast('L');
    dobj.InsertLast('O');
    dobj.InsertLast('B');

    dobj.Display();
    iRet = dobj.Count();
    cout<<"number of nodes are : "<<iRet<<"\n";

    dobj.DeleteFirst();
    dobj.Display();
    iRet = dobj.Count();
    cout<<"number of nodes are : "<<iRet<<"\n";

    dobj.DeleteLast();
    dobj.Display();
    iRet = dobj.Count();
    cout<<"number of nodes are : "<<iRet<<"\n";

    dobj.InsertAtPos('R',4);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"number of nodes are : "<<iRet<<"\n";

    dobj.DeleteAtPos(4);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"number of nodes are : "<<iRet<<"\n";

    return 0;
}
