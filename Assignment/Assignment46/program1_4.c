
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
//      Function name : ReplaceNegative
//      Desciption    : use to display  element less  than X
//      Input         : ptr(head) , int
//      output        :  int
//      Author name   : Sakshi kachate
//      Date          : 29/12/25  
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
//

void ReplaceNegative(PPNODE first )
{
     
    PNODE temp = NULL;
    temp = *first;
    
     while ( temp != NULL)
    {
        
        if(temp ->data  < 0)
        {
            temp->data = 0;
        }
            temp = temp->next;

            
    }
    
         
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
     
    int iValue =0, iEle = 0;
    int iCnt = 0,iNo = 0;

    
    printf("How many element to insert int linked list:\n");
    scanf("%d",&iNo);
    for(iCnt = 1 ; iCnt <= iNo ; iCnt++)
    {
           printf("Enter element %d: ",iCnt);
            scanf("%d",&iEle);
             InsertLast(&head, iEle);

    }

     
     
    ReplaceNegative(&head);
    Display(head );

    
    

 
    return 0;
}







/*

How many element to insert int linked list:
5
Enter element 1: 4
Enter element 2: -2
Enter element 3: 3
Enter element 4: -1
Enter element 5: 5
|4|->|0|->|3|->|0|->|5|->NULL


///////////////////////////////////////////////////////////////////////////////


How many element to insert int linked list:
5
Enter element 1: 1
Enter element 2: 2
Enter element 3: 3
Enter element 4: 4
Enter element 5: 5
|1|->|2|->|3|->|4|->|5|->NULL

*/
