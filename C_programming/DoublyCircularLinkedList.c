#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node* next;
    struct node * prev;
};
typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;


void Display(PNODE first , PNODE last)
{
    if((first) == NULL && (last) == NULL)
    {
        printf("Linked list are empty \n");
        return;
    }
    printf("<=>");
    do
    {   
        printf("|%d| <=> ",first->data);
        first = first->next;
    } while (first != last->next);
    printf("\n");
    
    
}

int Count(PNODE first,PNODE last)
{
    int iCount = 0; 
    if((first) == NULL && (last) == NULL)
    {
        printf("Linked list are empty \n");
        return 0;
    }
    do
    {
        iCount++;
        first = first->next;
    } while (first != last->next);
    printf("\n");

    return iCount;
}


void InsertFirst(PPNODE first ,PPNODE last , int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn ->data = no;
    newn->next =NULL;
    newn->prev =NULL;

    if(*first == NULL &&(*last) == NULL)
    {
        (*first) = newn;
        (*last)= newn;
    } 
    else
    {
        newn->next = (*first);
        (*first) ->prev = newn;

        (*first)= newn;
            

    }
    (*last)->next = (*first);
        (*first)->prev =(*last);
}

void InsertLast(PPNODE first ,PPNODE last , int no)
{
     PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn ->data = no;
    newn->next =NULL;
    newn->prev =NULL;

    if(*first == NULL &&(*last) == NULL)
    {
        (*first) = newn;
        (*last)= newn;
    } 
    else
    {
       (*last) ->next= newn;
       newn ->prev = (*last);
        (*last) = newn;

       

    }
    (*last) ->next = (*first);
       (*first) ->prev = (*last);
}
void InsertAtPos(PPNODE first ,PPNODE last , int no , int pos)
{
    
    int iCount =0;
    int i = 0;
    PNODE temp = NULL;
    PNODE newn = NULL;                      

    iCount = Count(*first,*last);

    if(pos < 1 || pos > iCount +1)
    {
        printf("Invalid Position \n");
    }
    if( pos == 1)
    {
        InsertFirst((first),(last),no);
    }
    else if(pos == iCount +1)
    {
        InsertLast((first),(last),no);

    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn ->next = NULL;
        newn->prev = NULL;
        newn->data = no;

        temp = (*first);
        for (i= 1 ; i< pos -1 ; i++)
        {
            temp = temp ->next;
        }
        newn ->next = temp  ->next ;
        newn ->  prev = temp;

        temp->next ->prev = newn;

        temp ->next = newn;
  
    }
}

void DeleteFirst(PPNODE first,PPNODE last)
{
    if((*first) == NULL && (*last) == NULL)
    {
        return ;
    } 
    else if((*first) == (*last))
    {
        free(*first);
        (*first) = NULL;
        (*last) = NULL;
    }
    else
    {
        (*first) = (*first)->next;
        free((*first)->prev);

        (*first)->prev = (*last);
        (*last)->next =(*first);     
    }
}

void DeleteLast(PPNODE first,PPNODE last)
{
    if((*first) == NULL && (*last) == NULL)
    {
        return ;
    } 
    else if((*first) == (*last))
    {
        free(*first);
        (*first) = NULL;
        (*last) = NULL;
    }
    else
    {
        (*last) = ((*last)->prev);
        free((*last)->next);

        (*last)->next = (*first);
        (*first)->prev = (*last);
    }
}

void DeleteAtPos(PPNODE first,PPNODE last, int pos)
{
    int iCount =0;
    int i = 0;
    PNODE temp = NULL;

    iCount = Count(*first,*last);

    if(pos < 1 || pos > iCount +1)
    {
        printf("Invalid Position \n");
    }
    if( pos == 1)
    {
        DeleteFirst((first),(last));
    }
    else if(pos == iCount +1)
    {
        DeleteLast((first),(last));

    }
    else
    {


        temp = (*first);
        for (i= 1 ; i< pos -1 ; i++)
        {
            temp = temp ->next;
        }
        
        temp ->next = temp ->next->next    ;
        free(temp->next->prev);
        temp->next->prev = temp;

         
    }
}


int main()
{

    PNODE head = NULL;
    PNODE tail = NULL;

    int iRet = 0;
 
    InsertFirst(&head,&tail, 51);
    InsertFirst(&head,&tail, 21);
    InsertFirst(&head,&tail, 11);

    Display(head,tail);
    iRet = Count(head,tail);
    printf("Number of nodes are : %d \n",iRet);


    InsertLast(&head ,&tail ,101);
    InsertLast(&head ,&tail ,111);
    InsertLast(&head ,&tail ,121);

    Display(head,tail);
    iRet = Count(head,tail);
    printf("Number of nodes are : %d \n",iRet);

    

    InsertAtPos(&head,&tail ,105,4);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("Number of nodes are : %d \n",iRet);

    DeleteAtPos(&head,&tail,4);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("Number of nodes are : %d \n",iRet);

    DeleteFirst(&head,&tail);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("Number of nodes are : %d \n",iRet);

    DeleteLast(&head,&tail);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("Number of nodes are : %d \n",iRet);
    
    return 0;
}
