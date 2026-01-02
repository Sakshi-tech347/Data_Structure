
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
//      Function name :CheckAllPositive
//      Desciption    : use to display all ele are positive or not 
//      Input         : 
//      output        :  int
//      Author name   : Sakshi kachate
//      Date          : 2/1/26
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
//

    bool CheckAllPositive(PNODE first)
    {

        if (first == NULL) 
        {
        return 0; 
        }
        PNODE temp = NULL;
        temp = first;
         

       
        while(temp != NULL)
        {
            if(temp ->data  <  0)
            {
                return false;
            }
             

            
            temp = temp->next;
        }
        return true;
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
    bool bRet = false;
     
    InsertLast(&head ,2);
    InsertLast(&head ,3);
    InsertLast(&head ,-4);
    InsertLast(&head ,7);


     

    printf("original :\n");
    Display(head ); 

     

    
    bRet = CheckAllPositive(head );

    if(bRet == true)
    {
        printf("All elments are positive \n");
    }
    else
    {
        printf("some elements are negative  \n");

    }

    
 
    return 0;
}


/*

original :
|2|->|3|->|4|->|7|->NULL
All elments are positive


///////////////////////////////////////////////////////////////////////////////

original :
|2|->|3|->|-4|->|7|->NULL
some elements are negative
 

*/
