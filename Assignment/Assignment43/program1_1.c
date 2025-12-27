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
//    Function Name :   DisplayPerfect
//    Desciption :     Display Perfect element in node
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
int CheckPerfect(int no)
{
    int i = 1 , sum =0 ;

    for(i = 1; i<= no/2 ; i++)
    {
        if (no % i == 0)
        {
            sum = sum + i;
        }

    }
    if (sum == no)
    {
        return 1;
    }
    else
    {
         return 0;
    }
}


void DisplayPerfect(PNODE first  )
{
    
     

    while(first != NULL)
    {
       
    
        if(CheckPerfect(first->data) == 1)
        {
            printf("%d ", first->data);
        }

        first = first ->next;

        
    }

       
    printf("\n");

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
    InsertFirst(&head , 28);
    InsertFirst(&head , 51);
    InsertFirst(&head , 6);
    InsertFirst(&head , 111);

    Display(head);
 
    DisplayPerfect(head );

    return 0;
}

///////////////////////////////////////////////////////////////////
//  
//  output
//    |111|->|6|->|51|->|28|->|11|->NULL
//    6 28
//   
///////////////////////////////////////////////////////////////////
