#include<iostream>
using namespace std;

struct node 
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;

class DoublyCL
{
    private:
        int iCount;
        PNODE first;
        PNODE last;

    public:
        DoublyCL()
        {
            iCount = 0;
            first = NULL;
            last = NULL;
        }

        void Display()
        {
            if(first == NULL)
            {
                cout<<"linklist is empty \n";
                return;
            }
            PNODE temp = NULL;
            temp = first;
            cout<<"<=>";
            do
            {
                cout<<"|"<<temp->data<<"|<=>";
                temp = temp->next;
            } while (temp != first);    
            cout<<"\n";
            
        };

        int Count()
        {
            return iCount; 
        };

        void InsertFirst(int no)
        {
            PNODE newn = NULL;
            newn = new node;
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

        void InsertLast(int no)     
        {
            PNODE newn = NULL;
            newn = new node;
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

        void InsertAtPos(int no , int pos )
        {
            PNODE newn = NULL;
            PNODE temp = NULL;
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
                newn = new node;
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

        void DeleteFirst()
        {
            PNODE temp = NULL;
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

        void DeleteLast()
        {
            PNODE temp = NULL;
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

            void DeleteAtPos(int pos)
            {
                PNODE temp =NULL;
                PNODE target = NULL;
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


};

int main()
{
    DoublyCL dobj;
    
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
