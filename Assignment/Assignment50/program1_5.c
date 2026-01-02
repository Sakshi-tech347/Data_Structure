
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
//
//      Required header file :
//
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
//
//      Declaration of Structure:
//      it contain : 
//                      data of node 
//                      next pointer to points another node
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
//
struct node 
{
    int data;
    struct node * next;

};

    typedef struct node NODE;
    typedef struct node * PNODE;
    typedef struct node ** PPNODE;

   void Display(PNODE first)
    {
        while(first != NULL)
        {
            printf("|%d|->",first ->data);
            first = first->next;
        }
        printf("NULL \n");
    }


int count(PNODE first)
{
    int icount = 0;
    while(first != NULL)
    {
        icount++;
        first = first->next;
    }
    return icount;
}

void InsertLast(PPNODE first, int no)
{
    PNODE newn = NULL;
    PNODE temp = *first;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if (*first == NULL)
    {
        *first = newn;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
//
//      Function name : DisplayAnCount
//      Desciption    : Display data at n position 
//                                 
//      Input         : 
//      output        :  
//      Author name   : Sakshi kachate
//      Date          : 2/1/26
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
//

    void DisplayAnCount(PNODE first , int ipos)
    {
         
         PNODE temp = NULL;
        temp = first;
        int icnt = 0;
        int iSize = 0; 
        iSize = count(first);
        
        
       if(ipos < 0 || ipos > iSize + 1)
       {
        printf("Invalid position \n");
        return ;
       } 

    for(icnt = 1 ; icnt< ipos ; icnt ++)
       {
         temp = temp ->next;
          
       }
       
       printf("%d is a data at %d position \n", temp->data , ipos );
            
    }

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//
//      Entry point Function
//
//
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



int main()
{

    PNODE head = NULL;
    int iRet = 0;
    int ipos = 0;

    InsertLast(&head ,5);
    InsertLast(&head ,3);
    InsertLast(&head ,10);
    InsertLast(&head ,6);
    InsertLast(&head ,15);
    InsertLast(&head ,4);  

    printf("original :\n");
    Display(head ); 

    printf("after :\n");
  
   DisplayAnCount(head , 3 ); 
 
    return 0;
}


/*

original :
|5|->|3|->|10|->|6|->|15|->|4|->NULL
after :
10 is a data at 3 position


///////////////////////////////////////////////////////////////////////////////

                   
original :
|5|->|3|->|10|->|6|->|15|->|4|->NULL
after :
Invalid position
 
*/
