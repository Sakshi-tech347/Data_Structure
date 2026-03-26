#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node * next;
};
typedef struct node NODE;
typedef struct node * PNODE;

class SinglyCL
{
    private:
        int iCount;
        PNODE first;
        PNODE last;

    public:
        SinglyCL()
        {
            iCount = 0;
            first = NULL;
            last = NULL;
        }

        void Display()
        {
            
            cout<<"<-";
            do
            {
                cout<<"|"<<first->data<<"|->";
                first = first-> next;
            } while ( last->next != first);
            cout<<"\n";
        
        }

        int Count()
        {
            return iCount;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;
            newn = new node;
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

        void InsertLast(int no)
        { 
            PNODE newn = NULL;
            newn = new node;
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

        void InsertAtPos(int no , int pos)
        {
            PNODE temp = NULL;
            PNODE newn = NULL;
            newn = new node;
            newn->next = NULL;
            newn->data = no;
            
            PNODE target = NULL;
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

        void DeleteFirst()
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
                PNODE temp = NULL;
                temp = first;
                first = first ->next;
                free(temp);
                
            }
            last ->next = first;
            iCount --;
        }

        void DeleteLast()
        {
            PNODE temp = NULL;
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

        void DeleteAtPos(int pos )
        {
            PNODE temp = NULL;
            PNODE target = NULL;

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
};

int main()
{

    SinglyCL sobj;

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
