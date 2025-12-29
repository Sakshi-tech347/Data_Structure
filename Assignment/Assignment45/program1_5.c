
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
//      Function name : Count_Less
//      Desciption    : use to display count element less than X
//      Input         : ptr(head) , int
//      output        :  int
//      Author name   : Sakshi kachate
//      Date          : 29/12/25  
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
//

int Count_Less(PNODE first ,int no)
{
     
    int iCnt = 0;
    
     while ( first != NULL)
    {
        
        if(first ->data  < no)
        {
            iCnt++;
         
        }
       

         first = first->next;
        
        }
    
       
           
            printf(" .\n");

         return iCnt;
         
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

     printf(" give element: ");
    scanf("%d",&iValue);
     
  
    iRet = Count_Less(head ,iValue );

   printf("Number of element greter than %d :: %d",iValue ,iRet);
    

 
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
 .
Number of element greter than 3 :: 2


///////////////////////////////////////////////////////////////////////////////


How many element to insert int linked list:
5
Enter element 1: 22
Enter element 2: 33
Enter element 3: 55
Enter element 4: 66
Enter element 5: 44
 give element: 21
 .
Number of element greter than 21 :: 0

*/
