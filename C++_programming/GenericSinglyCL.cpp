#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node <T>* next;
};
 
template <class T>
class SinglyCL
{
    private:
        int iCount;
        struct node <T>* first;
       struct node <T>* last;

    public:
        SinglyCL();
        void Display();
        int Count();
        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no , int pos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int pos );
        
};
template <class T>
SinglyCL <T> :: SinglyCL() 
{
iCount = 0;
first = NULL;
last = NULL;
}


template <class T>
void SinglyCL <T> :: Display()
{

cout<<"<-";
do
{
    cout<<"|"<<first->data<<"|->";
    first = first-> next;
} while ( last->next != first);
cout<<"\n";

}


template <class T>
int SinglyCL  <T>:: Count()
{
return iCount;
}


template <class T>
void SinglyCL  <T>::InsertFirst(T no)
{
struct node <T>* newn = NULL;
newn = new struct node <T>;
newn->next = NULL;
newn->data = no;

if(first == NULL && last == NULL)
{
    first = newn;
    last = newn;
}
else
{
    newn->next= first;
    first = newn;

}
    last->next = first;


iCount ++;
}


template <class T>
void SinglyCL <T> ::InsertLast(T no)
{ 
struct node <T>* newn = NULL;
newn = new struct node <T>;
newn->next = NULL;
newn->data = no;

if(first == NULL && last == NULL)
{
    first = newn;
    last = newn;
}
else
{
    
    last->next = newn;
    last = newn;

}
last->next = first;


iCount ++;
}


template <class T>
void SinglyCL  <T> :: InsertAtPos(T no , int pos)
{
struct node <T>* temp = NULL;
struct node <T>* newn = NULL;
newn = new struct node <T>;
newn->next = NULL;
newn->data = no;

struct node <T>* target = NULL;
int i = 0;
if(pos < 1 || pos > iCount +1 )
{
    cout<<"Invalid Position \n";
    return;
}
if(pos == 1)
{
    InsertFirst(no);
}
else if(pos == iCount +1 )
{
    InsertLast(no);
}
else
{

    temp = first;
    for( i = 1 ; i< pos -1 ; i++)
    {
        temp =temp-> next;
    }

    newn->next = temp->next;
    temp -> next = newn;

    
}
last->next = first;
iCount ++;
}


template <class T>
void SinglyCL  <T>:: DeleteFirst()
{
if(first == NULL& last == NULL)
{
    return;
}
else if(first->next == NULL)
{
    delete(first);
    first = NULL;
    last = NULL;
}
else
{
    struct node <T>* temp = NULL;
    temp = first;
    first = first ->next;
    free(temp);
    
}
last ->next = first;
iCount --;
}


template <class T>
void SinglyCL <T>:: DeleteLast()
{
struct node <T>* temp = NULL;
int i = 0;

if(first == NULL& last == NULL)
{
    return;
}
else if(first->next == NULL)
{
    delete(first);
    first = NULL;
    last = NULL;
}
else
{
    temp = first;

    while(temp ->next ->next != first)
    {
        temp = temp->next;
    }
    delete (temp->next);
    last = temp;
        
    
}
last ->next = first;
iCount --;
}


template <class T>
void SinglyCL <T>:: DeleteAtPos(int pos )
{
struct node <T>* temp = NULL;
struct node <T>* target = NULL;

int i = 0;
if(pos < 1 || pos > iCount +1 )
{
    cout<<"Invalid Position \n";
    return;
}
if(pos == 1)
{
    DeleteFirst();
}
else if(pos == iCount +1 )
{
    DeleteLast();
}
else
{

    temp = first;
    for( i = 1 ; i< pos -1 ; i++)
    {
        temp =temp-> next;
    }

    target = temp->next;
    temp ->next = target ->next;

    delete(target);

    
}
last->next = first;
iCount --;

}

int main()
{

    SinglyCL <int>sobj;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    sobj.Display();
    cout<<"Number of nodes are : "<<sobj.Count()<<"\n";

    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);

    sobj.Display();
    cout<<"Number of nodes are : "<<sobj.Count()<<"\n";

    sobj.InsertAtPos(105,4);
    sobj.Display();
    cout<<"Number of nodes are : "<<sobj.Count()<<"\n";

    sobj.DeleteAtPos(4);
    sobj.Display();
    cout<<"Number of nodes are : "<<sobj.Count()<<"\n";
    
    sobj.DeleteFirst();
    sobj.Display();
    cout<<"Number of nodes are : "<<sobj.Count()<<"\n";

    sobj.DeleteLast();
    sobj.Display();
    cout<<"Number of nodes are : "<<sobj.Count()<<"\n";

    
    
    return 0;
}
