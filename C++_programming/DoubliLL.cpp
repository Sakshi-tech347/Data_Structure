#include<iostream>
using namespace std;


struct node
{
    int data;
    struct node * next;
    struct node * prev;
};
typedef struct node NODE;
typedef struct node * PNODE;


class DoublyLL
{
    private:
        int iCount;
        PNODE first;

    public:
    DoublyLL()
    {
        cout<<"object gets created succefully \n";
        iCount = 0;
        first = NULL;
    }

    void Display()
    {
        PNODE temp = NULL;
        temp = first;
        while(temp != NULL)

        {
            cout<<"|"<<temp->data<<"|<=>";
            temp = temp->next;

        }
        cout<<"NULL\n";

    }

    int Count()
    {
        return iCount;
    }

    void InsertFirst( int no)
    {
        PNODE newn = NULL;
        newn = new node;
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

    void InsertLast( int no)
    {
        PNODE newn = NULL;
        PNODE temp = NULL;

        newn = new node;
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

    void InsertAtPos( int no , int pos)
    {
        PNODE newn = NULL;
        PNODE temp = NULL;

        

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
            newn = new node;
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

    void DeleteFirst()
    {
        PNODE temp = NULL;

    
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

    void DeleteLast()
    {
        PNODE temp = NULL;

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

    void DeleteAtPos(int pos)
    {
        PNODE newn = NULL;
        PNODE temp = NULL;
        PNODE target = NULL;

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
};


int main()
{

    
    DoublyLL dobj;
    int iRet = 0;

    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);

    dobj.Display();
    iRet = dobj.Count();
    cout<<"number of nodes are : "<<iRet<<"\n";

    dobj.InsertLast(101);
    dobj.InsertLast(111);
    dobj.InsertLast(121);

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

    dobj.InsertAtPos(105,4);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"number of nodes are : "<<iRet<<"\n";

    dobj.DeleteAtPos(4);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"number of nodes are : "<<iRet<<"\n";

    return 0;
}
