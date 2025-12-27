///////////////////////////////////////////////////////////////////
//    
//    Required header file
//
///////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next ;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;
///////////////////////////////////////////////////////////////////
//
//    Function Name : SecondMax
//    Desciption :    It use to display second largest element in singly linked list 
//    Input :         PPNODE first 
//    Output :        
//    Auther :        Sakshi  Laxman Kachate
//    Date :          27/12/2025
//
/////////////////////////////////////////////////////////////////////

void InsertFirst(PPNODE first, int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else{
        newn ->next = *first;
        *first = newn;
    }

}
void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("|%d|->",first->data);
        first= first->next;
    }
    printf("NULL \n");
}

int count(PNODE first)
{
    int icount = 0;

    while(first != NULL)
    {
         icount++;
        first = first->next ;
       
    }
    return icount;
}

int SecondMax(PNODE first  )
{
    int iMax1 = 0 , iMax2 =0;
    if(first == NULL || first->next == NULL)
    {
        printf("maximum number is not possible \n");
        return 1;
    }
     

    iMax1 = iMax2 =-2147;

    while(first != NULL)
    {
       
    
       if(first->data > iMax1)
        {
            iMax2 = iMax1;
            iMax1 = first->data;
        }
        else if(first->data > iMax2 && first->data < iMax1)
        {
            iMax2 = first->data;
        }
               first = first->next;
    }

        return iMax2;
        
    }








///////////////////////////////////////////////////////////////////
//    
//    Entry point Function for the application 
//
///////////////////////////////////////////////////////////////////
int main()
{
     
    
    PNODE head = NULL;
    int iRet =0  ;

    InsertFirst(&head , 11);
    InsertFirst(&head , 21);
    InsertFirst(&head , 51);
    InsertFirst(&head , 21);
    InsertFirst(&head , 111);

    Display(head);
 
    iRet= SecondMax(head );

     if(iRet  == -2147)
     {
         printf("Second maximum element not Found \n");
     }
     else
     {
         printf("Second maximum element is : %d \n",iRet);

     }

    
    return 0;
}

///////////////////////////////////////////////////////////////////
//  
//  output
//    |111|->|21|->|51|->|21|->|11|->NULL
//     Second maximum element is : 51
//   
///////////////////////////////////////////////////////////////////