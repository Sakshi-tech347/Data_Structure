
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
//      Function name :CheackSorted
//      Desciption    : use to  Display list are sorted or not 
//                                 
//      Input         : 
//      output        :  bool
//      Author name   : Sakshi kachate
//      Date          : 2/1/26
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
//

     bool CheackSorted(PNODE first)
    {
         PNODE temp = NULL;
        temp = first;
        
        
        if (first == NULL) 
        {
            return 0; 
        }
       
         

       
        while(temp ->next != NULL)
        {
           
             
             if(temp ->data > temp ->next ->data)
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
    int bRet = 0;

    InsertLast(&head ,3);
    InsertLast(&head ,1);
    InsertLast(&head ,10);
    InsertLast(&head ,15);
    InsertLast(&head ,1);
    InsertLast(&head ,34);




     

    printf("original :\n");
    Display(head ); 

    bRet = CheackSorted(head);
    if(bRet == true   )
    {
         printf("List are Sorted \n");

        
    } 
    else
    {
         printf("list are not sorted \n");

    }

  
     

   

    
 
    return 0;
}


/*

original :
|3|->|1|->|10|->|15|->|1|->|34|->NULL
list are not sorted


///////////////////////////////////////////////////////////////////////////////

original :
|3|->|3|->|10|->|15|->|25|->|34|->NULL
List are Sorted                 



*/
