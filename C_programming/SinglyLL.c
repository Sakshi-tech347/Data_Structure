#include<stdio.h>
#include<stdlib.h>

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
        printf("|%d|->",first->data);
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

void InsertLast(PPNODE first , int no)
{
    PNODE temp = 0;
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn ->data = no;
    newn ->next = NULL;

    if (*first == NULL)
    {
       *first = newn; 
    }
    else  
    {
        temp = *first;

        while((temp -> next) != NULL)
        {
            temp = temp ->next;
        }

        temp ->next = newn;
        
    }
    
    
}

void InsertAtPos(PPNODE first , int no , int pos)
{   
    PNODE temp = NULL;
    PNODE newn = NULL;

    int iSize = 0;
    iSize = count(*first);
    int iCnt = 0;
    if((pos < 1) || pos > iSize +1 )
    {
        printf("Invalide position \n");
        return ;
    }

    if(pos == 1)
    {
        InsertFirst(first ,no);

    }
    else if(pos = iSize + 1)
    {
        InsertLast(first ,no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn ->data = no;
        newn ->next = NULL;

        temp = (*first);
        for(iCnt = 1; iCnt < pos -1 ; iCnt++)
        {
            temp = temp ->next;
        }

        newn ->next = temp ->next;
        temp->next = newn;

    }
}

void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;
    if(*first == NULL)
    {
        return;
    }
    else if((*first) -> next == NULL)
    {
        free(*first);
        *first = NULL;

    }
    else
    {   
        temp = (*first);
        *first = (*first) -> next;
        free(temp);
        
    }
  
}

void DeleteLast(PPNODE first)
{
     PNODE temp =NULL;
     

     if(*first == NULL)
     {
        return;
     }
     else if((*first)->next == NULL)
     {
        free(*first);
        (*first) = NULL;
     }
     else
     {
        temp = (*first);

        while(temp->next->next != NULL)
        {
            temp = temp ->next;
        }

        free(temp ->next);
        temp -> next = NULL;

     }
}

void DeleteAtPos(PPNODE first ,int pos)
{
    PNODE temp = NULL;
    PNODE target = NULL;

    int iCnt = 0 ,iSize =0;
    iSize = count(*first);

    if(pos == 1)
    {
        DeleteFirst(first);
    }
    else if( pos == iSize +1)
    {
        DeleteLast(first);
    }
    else
    {
        temp = *first;

        for(iCnt = 1 ; iCnt < pos - 1 ; iCnt++)
        {
            temp = temp -> next;
        }
            target = temp ->next;
            temp -> next = target ->next;

            free(target);
    
    }
}



int main()
{

    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head , 51);
    InsertFirst(&head , 21);
    InsertFirst(&head , 11);


    Display(head);
    iRet = count(head);
    printf(" Number of nodes are: %d \n",iRet);

    InsertLast(&head , 151);
    InsertLast(&head , 121);

    InsertLast(&head , 111);

    Display( head);
    iRet = count(head);
    printf(" Number of nodes are: %d \n",iRet);

    InsertAtPos(&head ,115,3);
    Display( head);
    iRet = count(head);
    printf(" Number of nodes are: %d \n",iRet);

    DeleteFirst(&head);
    Display( head);
    iRet = count(head);
    printf(" Number of nodes are: %d \n",iRet);

    DeleteLast(&head);
    Display(head);
    iRet = count(head);
    printf(" Number of nodes are: %d \n",iRet);

    DeleteAtPos(&head,3);
     Display(head);
    iRet = count(head);
    printf(" Number of nodes are: %d \n",iRet);

    return 0;
}
