
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
//      Function name : Display_Less
//      Desciption    : use to display  element less  than X
//      Input         : ptr(head) , int
//      output        :  int
//      Author name   : Sakshi kachate
//      Date          : 29/12/25  
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
//

void Display_Less(PNODE first ,int no)
{
     
    
    
     while ( first != NULL)
    {
        
        if(first ->data  < no)
        {
             printf("%d  ",first->data);
            
        }
            first = first->next;
 
        
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

     printf(" give element: ");
    scanf("%d",&iValue);
     
  
    printf("this Number are less than %d ::  ", iValue);
    Display_Less(head,iValue );

    
    

 
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
 give element: 3
this Number are less than 3 ::  1  2


///////////////////////////////////////////////////////////////////////////////


How many element to insert int linked list:
5
Enter element 1: 6
Enter element 2: 5
Enter element 3: 7
Enter element 4: 8
Enter element 5: 9
 give element: 5
this Number are less than 5 ::

*/
