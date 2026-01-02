
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
//      Function name :Difference
//      Desciption    : use to display difference inbetween max & min node 
//      Input         : 
//      output        :  int
//      Author name   : Sakshi kachate
//      Date          : 2/1/26
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
//

    int Difference(PNODE first)
    {

        if (first == NULL) 
        {
        return 0; 
        }
        PNODE temp = NULL;
        temp = first;
        int iMax = 0;
        int iMin = 0;

        iMax = first->data;
        iMin = first->data;
        while(temp != NULL)
        {
            iMax = 1;
            if(temp ->data  > iMax)
            {
                iMax = temp ->data;
            }
            else
            {
                iMin = temp->data;
            }

            
            temp = temp->next;
        }
      return iMax - iMin;
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
     
    InsertLast(&head ,2);
    InsertLast(&head ,3);
    InsertLast(&head ,4);
    InsertLast(&head ,7);


     

    printf("original :\n");
    Display(head ); 

     

    
    iRet = Difference(head );
    printf("difference inbetween min and max is : %d", iRet);

    
 
    return 0;
}


/*

original :
|2|->|3|->|4|->|7|->NULL
difference inbetween min and max is : 5


///////////////////////////////////////////////////////////////////////////////


 

*/
