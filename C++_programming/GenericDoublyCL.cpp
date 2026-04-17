#include<iostream>
using namespace std;

template <class T>
struct node 
{
    T data;
    struct node <T>*next;
    struct node <T>*prev;
};

 

template <class T>
class DoublyCL
{
    private:
        T iCount;
        struct node <T>* first;
        struct node <T>* last;

    public:
        DoublyCL();
        void Display();
        int Count();
        void InsertFirst(T no);
        void InsertLast(T no);   
        void InsertAtPos(T no , int pos );
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int pos);
        

};

template <class T>
DoublyCL <T>:: DoublyCL()
{
iCount = 0;
first = NULL;
last = NULL;
}

template <class T>
void DoublyCL <T> ::Display()
{
if(first == NULL)
{
    cout<<"linklist is empty \n";
    return;
}
struct node <T>* temp = NULL;
temp = first;
cout<<"<=>";
do
{
    cout<<"|"<<temp->data<<"|<=>";
    temp = temp->next;
} while (temp != first);    
cout<<"\n";

};

template <class T>
int DoublyCL <T> :: Count()
{
return iCount; 
};

template <class T>
void DoublyCL <T> ::InsertFirst(T no)
{
struct node <T>* newn = NULL;
newn = new struct node <T>;
newn->data = no;
newn->next = NULL;
newn->prev = NULL;

if(first == NULL && last == NULL)
{
    first = newn;
    last = newn;
}
else
{
    newn ->next = first;
    first = newn;
    newn ->prev = last;
}
last->next = first;
first->prev = last;

iCount++;

};

template <class T>
void DoublyCL <T> ::InsertLast(T no)     
{
struct node <T>* newn = NULL;
newn = new struct node <T>;
newn->data = no;
newn->next = NULL;
newn->prev = NULL;

if(first == NULL && last == NULL)
{
    first = newn;
    last = newn;
}
else
{
    newn ->prev = last;
    last ->next = newn;
    last = newn;
}
last->next = first;
first->prev = last;

iCount++;
};

template <class T>
void DoublyCL <T> ::InsertAtPos(T no , int pos )
{
struct node <T>* newn = NULL;
struct node <T>* temp = NULL;
int i =0;


if(pos < 1 || pos > iCount + 1)
{
    cout<<"Invalid Position \n";
}

if(pos == 1)
{
    InsertFirst(no);
}
else if(pos == iCount +1)
{
    InsertLast(no);
}
else
{
    newn = new struct node <T>;
    newn->next = NULL;
    newn->prev = NULL;
    newn-> data = no;

    temp = first;
    for(i = 1 ; i<pos- 1; i++)
    {
        temp = temp->next;
    }

    newn->next = temp->next;
    newn->prev = temp;

    temp->next->prev = newn;

    temp->next =newn;


    first->prev = last;
    last->next = first;

    iCount++;
}


};

template <class T>
void DoublyCL <T> :: DeleteFirst()
{
struct node <T>* temp = NULL;
if(first == NULL && last == NULL)
{
    return;
} 
else if(first == last)
{
    delete(first);
    first = NULL;
    last = NULL;
}
else
{
    temp = first;

    first = first->next;

    delete(temp);
    first->prev = last;

    last->next = first;

}
iCount--;
};

template <class T>
void DoublyCL <T> ::DeleteLast()
{
struct node <T>* temp = NULL;
if(first == NULL )
{
    return;
} 
else if(first == last)
{
    delete(first);
    first = NULL;
    last = NULL;
}
else
{   
    temp = last;
    last = last ->prev;
    first->prev = last; 
    last->next = first;


    delete(temp);

        


} 
iCount--;

};

template <class T>
void DoublyCL <T> :: DeleteAtPos(int pos)
{
    struct node <T>* temp =NULL;
    struct node <T>* target = NULL;
    int i =0;
    if(pos < 1 || pos > iCount +1 )
    {
        cout<<"Invalid position \n";
    }
    if(pos == 1)
    {
        DeleteFirst();

    }
    else if(pos == iCount)
    {
        DeleteLast();

    }
    else
    {
        temp =first;
        for(i = 1; i< pos-1 ; i++)
        {
            temp = temp -> next;
        }

        target = temp -> next;
        temp->next = temp->next ->next;
        target ->next ->prev = temp;
        delete(target);
    }
    iCount --;

};


int main()
{
    DoublyCL <int>dobj;
    
    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);

    dobj.Display();
    cout<<"Number of nodes are : "<<dobj.Count()<<"\n";

    


    dobj.InsertLast(101);
    dobj.InsertLast(111);
    dobj.InsertLast(121);

    dobj.Display();
    cout<<"Number of nodes are : "<<dobj.Count()<<"\n";
  
    dobj.DeleteFirst();
    dobj.Display();
    cout<<"Number of nodes are : "<<dobj.Count()<<"\n";

    dobj.DeleteLast();
    dobj.Display();
    cout<<"Number of nodes are : "<<dobj.Count()<<"\n";

    dobj.InsertAtPos(105,4);
    dobj.Display();
    cout<<"Number of nodes are   : "<<dobj.Count()<<"\n";

    dobj.DeleteAtPos(4);
    dobj.Display();
    cout<<"Number of nodes are   : "<<dobj.Count()<<"\n";



    return 0;
}
