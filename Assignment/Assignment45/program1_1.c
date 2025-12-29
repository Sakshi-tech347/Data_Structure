
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

void InsertFirst(PPNODE first , int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;  
    }
    else
    {
        newn->next = *first;
        *first = newn;
    }
}
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
//
//      Function name : Display
//      Desciption    : it is use to Display odd Elements in ll
//      Input         : ptr(head) 
//      output        :  odd Element
//      Author name   : Sakshi kachate
//      Date          : 29/12/25  
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
//

void Display_Odd(PNODE first )
{
     while ( first != NULL)
     {
        if(first ->data  % 2 != 0)
        {
            printf( "%d ,",first->data);
        }
       
     
         first = first->next;
     }
    
       

    printf(" .\n");


      
     
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
    int iValue =0, iEle = 0;
    int iCnt = 0,iNo = 0;

    
    printf("How many element to insert int linked list:\n");
    scanf("%d",&iNo);
    for(iCnt = 1 ; iCnt <= iNo ; iCnt++)
    {
           printf("Enter element %d: ",iCnt);
            scanf("%d",&iEle);
             InsertFirst(&head , iEle); 
    }

     
    printf("Odd Element in linked list are : ");
  
    Display_Odd(head );

  
    return 0;
}







/*

How many element to insert int linked list:
5
Enter element 1: 1
Enter element 2: 2
Enter element 3: 3
Enter element 4: 4
Enter element 5: 5
Odd Element in linked list are : 5 ,3 ,1 , .


///////////////////////////////////////////////////////////////////////////////


How many element to insert int linked list:
5
Enter element 1: 2
Enter element 2: 4
Enter element 3: 6
Enter element 4: 8
Enter element 5: 10
Odd Element in linked list are :  .

*/
