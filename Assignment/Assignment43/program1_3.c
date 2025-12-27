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
//    Function Name :   DisplayAddEven 
//    Desciption :     Display Addition of even  element in node
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
 
        
 


int AddEven(PNODE first  )
{
    
     int iSum = 0;

    while(first != NULL)
    {
       
    
        if(first->data %2  == 1)
        {
           iSum = iSum + first->data;
        }

        first = first ->next;

        
    }

       return iSum;
    

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
    InsertFirst(&head , 20);
    InsertFirst(&head , 32);
    InsertFirst(&head , 41);



    Display(head);
 
     iRet = AddEven(head);
     printf(" %d is the Addition of all element in the linked list ",iRet);

    return 0;
}

///////////////////////////////////////////////////////////////////
//  
//  output
//    |41|->|32|->|20|->|11|->NULL
//       52 is the Addition of all element in the linked list
//   
///////////////////////////////////////////////////////////////////