
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
//      Function name :DisplayGtrThanAvg
//      Desciption    : use to  Display grter ele of the avf
//                                 
//      Input         : 
//      output        :  
//      Author name   : Sakshi kachate
//      Date          : 2/1/26
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
//

    void DisplayGtrThanAvg(PNODE first)
    {
        int iAvg = 0;
        int iCount = 0;
        int iSum = 0;
         PNODE temp = NULL;
        temp = first;
        
        
        if (first == NULL) 
        {
            return ; 
        }
       
         

       
        while(temp != NULL)
        {
           
             
            iSum = iSum + temp->data;
            iCount++;

            temp = temp->next;
        }
         
        iAvg = iSum / iCount;
        
        temp = first;
        printf("this are the element are greter than the average\n");
        while (temp != NULL)
        {
             if(iAvg < temp->data)
             { 
                printf("%d   \n",temp->data);
             }
             temp= temp->next;
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
    int iRet = 0;

    InsertLast(&head ,5);
    InsertLast(&head ,3);
    InsertLast(&head ,10);
    InsertLast(&head ,6);
    InsertLast(&head ,15);
    InsertLast(&head ,4);




     

    printf("original :\n");
    Display(head ); 

     

  
    DisplayGtrThanAvg(head );

   

    
 
    return 0;
}


/*


///////////////////////////////////////////////////////////////////////////////

|5|->|3|->|10|->|6|->|15|->|4|->NULL
this are the element are greter than the average
10
15                    

5+3+10+6+15+4 = 43 (sum)
43 / 6        = 7 (avg) = sum +(ele)

print numbers are gtr than 7

*/
