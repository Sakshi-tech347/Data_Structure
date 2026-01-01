
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
//      Function name : DisplayEvenPosition
//      Desciption    : use to display value at even pos
//      Input         : ptr(head)
//      output        :  int
//      Author name   : Sakshi kachate
//      Date          : 29/12/25  
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
//

void DisplayEvenPosition(PNODE first )
{
     
    
    
    
    
        PNODE temp = NULL;
         int ipos  = 1;

         temp =first;


        while(temp != NULL)
        {
             if (ipos % 2 == 0)
             {
                 printf("|%d|",temp->data);
             }
             ipos ++;
            temp = temp->next;
        }
       
        printf("NULL\n");
       
       
            
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
     
    InsertLast(&head ,2);
    InsertLast(&head ,3);
    InsertLast(&head ,4);
    InsertLast(&head ,5);


     

    printf("original :\n");
    Display(head ); 

     

    printf("ele with even pos\n");
     DisplayEvenPosition(head );

    
 
    return 0;
}


/*

original :
|2|->|3|->|4|->|5|->NULL
ele with even pos
|3||5|NULL


///////////////////////////////////////////////////////////////////////////////


 

*/
