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
//    Function Name : InsertFirst
//    Desciption :    It use to display node in linkedlist
//    Input :         PPNODE first, int no
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

int SearchFirstOcc(PNODE first ,int  no )
{
    int pos = 1;

    while(first != NULL)
    {
        if(first -> data ==no)
        {
            return pos;
        }
        first = first ->next;
        pos++;
    }

        return -1;


}




///////////////////////////////////////////////////////////////////
//    
//    Entry point Function for the application 
//
///////////////////////////////////////////////////////////////////
int main()
{
     
    
    PNODE head = NULL;
    int iRet =0 , iValue = 0;

    InsertFirst(&head , 11);
    InsertFirst(&head , 21);
    InsertFirst(&head , 51);
    InsertFirst(&head , 111);

    
  


    Display(head);
    printf("Enter  search element  \n");
    scanf("%d",&iValue);



    iRet=SearchFirstOcc(head ,iValue);

    if (iRet != -1 )
    {
        printf("Element found at position %d \n ",iRet);

    }
    else 
    {
        printf("Element not found \n");
    }

    return 0;
}

///////////////////////////////////////////////////////////////////
//  
//  output
//    |111|->|51|->|21|->|11|->NULL
//     Enter  search element
//          21
//     Element found at position 3
//   
//
///////////////////////////////////////////////////////////////////
