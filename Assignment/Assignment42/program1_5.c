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
//    Function Name : 
//    Desciption :    It use smallest element  in singly linked list
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

int Minimum(PNODE first  )
{
    int iMin = 0;
  
    if(first == NULL)
    {
        return -1;
    }
     

    iMin = first->data;

    while(first != NULL)
    {
       
    
        if(iMin > first ->data)
        {
            iMin = first->data;
        }

        first = first ->next;

        
    }

        return iMin;


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
 
    iRet= Minimum(head );

     
        printf("minimum element   %d \n ",iRet);

    
    return 0;
}

///////////////////////////////////////////////////////////////////
//  
//  output
//    |111|->|21|->|51|->|21|->|11|->NULL
//      minimum is  21
//   
///////////////////////////////////////////////////////////////////