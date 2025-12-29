
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
//      Function name : Last_Occ
//      Desciption    : it is use to Display first occurence of element
//      Input         : ptr(head) , int
//      output        :  occ
//      Author name   : Sakshi kachate
//      Date          : 29/12/25  
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
//

int Last_Occ(PNODE first ,int no)
{
    int iPos = 0;
    int iLast = -1;
     while ( first != NULL)
    {
        
        if(first ->data  == no)
        {
            
          iLast = iPos;

            
        }
       
     
         first = first->next;
         iPos++;
        }
    
       
           
            printf(" .\n");

         return iLast;
         
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

     printf(" Element for Last Occ: ");
    scanf("%d",&iValue);
     
  
    iRet = Last_Occ(head ,iValue );

    if(iRet == -1)
    {
        printf("Element are not found \n");
    }
    else 
    {
        printf(" Last occurrence of Element are found %d positon \n" , iRet);

    }
    

 
    return 0;
}


/*

How many element to insert int linked list:
5
Enter element 1: 2
Enter element 2: 1
Enter element 3: 3
Enter element 4: 2
Enter element 5: 5
 Element for Last Occ: 2
 .
 Last occurrence of Element are found 4 positon


///////////////////////////////////////////////////////////////////////////////


How many element to insert int linked list:
5
Enter element 1: 1
Enter element 2: 2
Enter element 3: 2
Enter element 4: 3
Enter element 5: 4
 Element for Last Occ: 5
 .
Element are not found

*/
