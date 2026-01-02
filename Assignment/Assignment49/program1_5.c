
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
//      Function name :CountTwoDigit
//      Desciption    : use to display count of ele of 2 digit
//      Input         : 
//      output        :  int
//      Author name   : Sakshi kachate
//      Date          : 2/1/26
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
//

    int CountTwoDigit(PNODE first)
    {
        int iCount = 0;
         PNODE temp = NULL;
        temp = first;
        
        
        if (first == NULL) 
        {
            return 0; 
        }
       
         

       
        while(temp != NULL)
        {
            if((temp ->data  >= 10 ) && (temp ->data  <= 99 ) )
            {
                iCount++  ;
            }
             

            
            temp = temp->next;
        }
         return iCount;
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

    InsertLast(&head ,5);
    InsertLast(&head ,3);
    InsertLast(&head ,-4);
    InsertLast(&head ,10);
    InsertLast(&head ,6);
    InsertLast(&head ,15);



     

    printf("original :\n");
    Display(head ); 

     

  
    iRet = CountTwoDigit(head );
    printf("count of 2 Digit elements are  %d \n", iRet);

   

    
 
    return 0;
}


/*




///////////////////////////////////////////////////////////////////////////////

original :
|5|->|3|->|-4|->|10|->|6|->|15|->NULL
count of 2 Digit elements are  2

*/
