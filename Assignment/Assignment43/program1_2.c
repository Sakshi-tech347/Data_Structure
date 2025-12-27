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
//    Function Name :   DisplayPrime 
//    Desciption :     Display Prime element in node
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
int CheckPrime(int no)
{
    int i = 1  ;
    if(no <= 1)
    {
        return 0;
    }

    for(i = 2; i<= no/2 ; i++)
    {
        if (no % i == 0)
        {
            return 0;
            
        }
        return 1;

    }
     
}


void DisplayPrime(PNODE first  )
{
    
     

    while(first != NULL)
    {
       
    
        if(CheckPrime(first->data) == 1)
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
    InsertFirst(&head , 20);
    InsertFirst(&head , 17);
    InsertFirst(&head , 41);
    InsertFirst(&head , 22);
    InsertFirst(&head , 89);



    Display(head);
 
    DisplayPrime(head );

    return 0;
}

///////////////////////////////////////////////////////////////////
//  
//  output
//    |89|->|22|->|41|->|17|->|20|->|11|->NULL
//     89 41 17 11
//   
///////////////////////////////////////////////////////////////////