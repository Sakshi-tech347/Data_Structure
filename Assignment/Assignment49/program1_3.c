
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
//      Function name :DisplayDivisiblByThree
//      Desciption    : use to display all ele which is divisible by 3 
//      Input         : 
//      output        :  int
//      Author name   : Sakshi kachate
//      Date          : 2/1/26
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
//

    void DisplayDivisiblByThree(PNODE first)
    {

        if (first == NULL) 
        {
            return;
        }
        PNODE temp = NULL;
        temp = first;
         

       
        while(temp != NULL)
        {
            if(temp ->data  %  3 ==  0)
            {
                 printf("|%d| " , temp->data);
            }
             

            
            temp = temp->next;
        }
         
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
     
    InsertLast(&head ,9);
    InsertLast(&head ,3);
    InsertLast(&head ,-4);
    InsertLast(&head ,7);
    InsertLast(&head ,6);
    InsertLast(&head ,8);



     

    printf("original :\n");
    Display(head ); 

     

    printf("there are this ele are divisible by 3: \n");
     DisplayDivisiblByThree(head );

   

    
 
    return 0;
}


/*




///////////////////////////////////////////////////////////////////////////////

original :
|9|->|3|->|-4|->|7|->|6|->|8|->NULL
there are this ele are divisible by 3:
|9| |3| |6|

*/
