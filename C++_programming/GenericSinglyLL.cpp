#include<iostream>
using namespace std;

template <class T>
struct  node
{
    T data;
    struct node <T>* next;
};

template <class T>
class SinglyLL
{
    public:
        int iCount;
        struct node <T>* first;

        SinglyLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no , int pos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtpos(int pos);
        void Display();
        int Count();
      
 

};

template <class T>
SinglyLL <T>:: SinglyLL()
{
    cout<<"Object of SinglyLL gets created \n";
    first = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL <T>:: InsertFirst(T no)
{
    struct node <T>* newn = NULL;
    newn = new struct node <T>;

    newn ->data = no;
    newn -> next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn -> next = first ;
        first = newn;
    }
    iCount ++;
}

template <class T>
void SinglyLL <T>::InsertLast(T no)
{
    struct node <T>* newn = NULL;
    struct node <T>* temp = NULL;
    newn = new struct node <T>;

    newn ->data = no;
    newn-> next = NULL;
    
    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
            temp ->next = newn;

    }

    iCount++;
    
}

template <class T>
void SinglyLL <T>::InsertAtPos(T no , int pos)
{
    struct node <T>*temp = NULL;
    struct node <T>* newn = NULL;

    newn = new struct node <T>;
    newn->data = no;
    newn->next = NULL;
    int iSize = 0 ;
    int iCnt =0;
    iSize =Count();

    if(pos ==1)
    {
        InsertFirst(no);
    }
    else if(pos == iSize + 1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct node <T>;
        
        newn->data = no;
        newn->next = NULL;
        temp =(first);

        for(iCnt =1 ; iCnt < pos -1 ; iCnt++)
        {
            temp = temp->next;
        }

        newn ->next = temp ->next;
        temp ->next = newn;

    }
    iCount ++;
}

template <class T>
void SinglyLL <T>::DeleteFirst()
{
    struct node <T>* temp = NULL;
    if(first == NULL)
    {
        return;
    }
    else if( first->next == NULL)
    {
        free(first);
        first ->next =NULL;
    }
    else
    {
        temp = first;
        first = first ->next;
        free(temp);
        
    }
    iCount--;
}

template <class T>
void SinglyLL <T>::DeleteLast()
{
        struct node <T>*temp = NULL;
    if(first == NULL)
    {
        return;
    }
    else if( first->next == NULL)
    {
        free(first);
        first ->next =NULL;
    }
    else
    { 
        temp = first;
        while(temp ->next ->next != NULL)
        {
            temp = temp ->next;
        }
            free(temp->next);
            temp ->next =NULL;
        
    }
    iCount--;
}

template <class T>
void SinglyLL <T>::DeleteAtpos(int pos)
{
    struct node <T>* temp = NULL;
    struct node <T>* target = NULL;

    int iCnt = 0, iSize = 0;
    iSize = Count();

    if(pos == 1)
    {
    DeleteFirst();
    }
    else if(pos == iSize + 1)
    {
    DeleteLast();
    }
    else
    {
        temp = first;

        for(iCnt = 1; iCnt < pos -1 ; iCnt++)
        {
            temp = temp ->next;
        }
        target = temp -> next;
        temp ->next = target ->next;
        free(target);

    }
    iCount--;
}

template <class T>
void SinglyLL <T>::Display()
{
    struct node <T>* temp = NULL;

    temp = first;
    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp -> next;
    }
    cout<<"NULL \n";
}

template <class T>
int SinglyLL <T>::Count()
{
    return iCount;
}

int main ()
{
    SinglyLL <double>sobj;
    int iRet = 0;

    sobj.InsertFirst(51.2);
    sobj.InsertFirst(21.1);
    sobj.InsertFirst(11.2);

    sobj.Display();
    iRet =sobj.Count();
    cout<<"number of node are :"<<iRet<<"\n";

    sobj.InsertLast(151.2);
    sobj.InsertLast(121.3);
    sobj.InsertLast(111.1);

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of node are :"<<iRet<<"\n";

    sobj.InsertAtPos(33.1,3);
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of node are:"<<iRet<<"\n";

    sobj.DeleteFirst();
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of node are:"<<iRet<<"\n";

    sobj.DeleteLast();
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of node are:"<<iRet<<"\n";

    sobj.DeleteAtpos(3);
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of node are:"<<iRet<<"\n";



    return 0;
}
