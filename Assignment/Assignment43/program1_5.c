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
//    Function Name :  DispaySumOfDigit
//    Desciption :    It use to display addition od digit in each element in node  
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

int DisplaySumOfDigit(PNODE first  )
{
    int ino =0 , iDigit =0, iSum =0;
    

    while(first != NULL)
    {
       
        ino = first->data;
        iSum = 0;

        while (ino != 0)
        {
            iDigit = ino % 10 ;
            iSum = iSum + iDigit;
            ino =  ino /  10;
        }
        printf("Sum of digits of %d is %d\n", first->data, iSum);
               first = first->next;
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

    InsertFirst(&head , 11);
    InsertFirst(&head , 21);
    InsertFirst(&head , 51);
    InsertFirst(&head , 21);
    InsertFirst(&head , 111);

    Display(head);
 
     DisplaySumOfDigit(head );

 
     
         
     
     
    
    return 0;
}

///////////////////////////////////////////////////////////////////
//  
//  output
//    |111|->|21|->|51|->|21|->|11|->NULL
//    Sum of digits of 111 is 3
//    Sum of digits of 21 is 3
//    Sum of digits of 51 is 6
//    Sum of digits of 21 is 3
//    Sum of digits of 11 is 2
//   
///////////////////////////////////////////////////////////////////