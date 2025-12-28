#include<iostream>
using namespace std;

struct  node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class SinglyLL
{
    public:
        int iCount;
        PNODE first;

        SinglyLL()
        {
            cout<<"Object of SinglyLL gets created \n";
            first = NULL;
            iCount = 0;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;
            newn = new NODE;

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

        void InsertLast(int no)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;
            newn = new NODE;

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

        void InsertAtPos(int no , int pos)
        {
            PNODE temp = NULL;
            PNODE newn = NULL;

            newn = new NODE;
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
               newn = new NODE;
               
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

        void DeleteFirst()
        {
            PNODE temp = NULL;
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

        void DeleteLast()
        {
             PNODE temp = NULL;
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

        void DeleteAtpos(int pos)
        {
           PNODE temp = NULL;
           PNODE target = NULL;

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

        void Display()
        {
            PNODE temp = NULL;

            temp = first;
            while(temp != NULL)
            {
                cout<<"|"<<temp->data<<"|->";
                temp = temp -> next;
            }
            cout<<"NULL \n";
        }

        int Count()
        {
            return iCount;
        }
 

};

int main ()
{
    SinglyLL sobj;
    int iRet = 0;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    sobj.Display();
    iRet =sobj.Count();
    cout<<"number of node are :"<<iRet<<"\n";

    sobj.InsertLast(151);
    sobj.InsertLast(121);
    sobj.InsertLast(111);

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of node are :"<<iRet<<"\n";

    sobj.InsertAtPos(33,3);
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
