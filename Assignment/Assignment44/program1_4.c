
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
        printf("|%d|->",first->data);
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
//      Function name : Frequency
//      Desciption    : it is use to Display frequency of element
//      Input         : ptr(head) , no
//      output        :  iCount
//      Author name   : Sakshi kachate
//      Date          : 29/12/25  
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
//

int Frequency(PNODE first ,int no)
{
    int iCount =0;
     while ( first != NULL)
     {
        if(first ->data  ==  no)
        {
           iCount++;
        }
        first = first->next;
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

    printf("Enter Element to give their Frequency : ");
    scanf("%d",&iValue);
  
    iRet= Frequency(head ,iValue);

    printf(" %d  number present  in Linked List  %d times", iValue, iRet);
  
    return 0;
}







/*

How many element to insert int linked list:
5
Enter element 1: 1
Enter element 2: 5
Enter element 3: 2
Enter element 4: 3
Enter element 5: 3
Enter Element to give their Frequency : 3
 3  number present  in Linked List  2 times


///////////////////////////////////////////////////////////////////////////////


How many element to insert int linked list:
5
Enter element 1: 3
Enter element 2: 4
Enter element 3: 5
Enter element 4: 6
Enter element 5: 9
Enter Element to give their Frequency : 2
 2  number present  in Linked List  0 times

*/
