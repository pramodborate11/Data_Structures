#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE first,int no)
{
   PNODE newn = NULL;
   newn = (PNODE)malloc(sizeof(NODE));

   newn -> data = no;
   newn -> next = NULL;

   if(*first == NULL)   
   {
      (*first) = newn;
   }
   else                 
   {
      newn ->next = (*first);
      (*first) = newn;
   }
}

void InsertLast(PPNODE first,int no)
{
   PNODE newn = NULL;
   PNODE temp = NULL;
   newn = (PNODE)malloc(sizeof(NODE));           // 12 Bytes

   newn -> data = no;
   newn -> next = NULL;

   if(*first == NULL)   
   {
      *first = newn;
   }
   else                 
   {
      temp = *first;

      while(temp -> next != NULL)
      {
        temp = temp -> next;
      }
      temp -> next =newn;
   }
}

void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;

    if((*first) == NULL)                   //CASE 1
    {
        return ;
    }
    else if((*first)->next == NULL)    // CASE 2
    {
        free(*first);
        (*first) = NULL;
    }
    else                              //CASE 3
    {
       temp = (*first);
       (*first) = (*first) -> next;
       free(temp);
    }
}

void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;
    if((*first) == NULL)                   //CASE 1
    {
        return ;
    }
    else if((*first)->next == NULL)    // CASE 2
    {
        free(*first);
        *first = NULL;
    }
    else                              //CASE 3
    {
        temp = *first;
        while(temp->next->next != NULL)
        {
            temp = temp->next;

        }
        free(temp-> next);
        temp->next = NULL;
    }
}
//----------------------------------------Call By Value-----------------------------------
void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d |->",first ->data);
        first = first ->next;
    }
    printf("NULL \n");
}

int Count(PNODE first)
{
    int iCount = 0;
    while(first != NULL)
    {
        iCount++;
        first = first ->next;
    }
    return iCount;
}

int main() 
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst (&head,75);
    InsertFirst (&head, 51);
    InsertFirst (&head, 21);
    InsertFirst (&head, 11);

    Display(head);
    iRet = Count(head);
    printf("Number of Nodes are : %d\n",iRet);
    

    InsertLast (&head,101);
    InsertLast (&head,111);
    InsertLast (&head,121);


    Display(head);
    iRet = Count(head);
    printf("Number of Nodes are : %d\n",iRet);

    DeleteFirst(&head);

    Display(head);
    iRet = Count(head);
    printf("Number of Nodes are : %d\n",iRet);
    
    DeleteLast(&head);

    Display(head);
    iRet = Count(head);
    printf("Number of Nodes are : %d\n",iRet);

    return 0;
}

/*
out put :
C:\Users\admin\OneDrive\Desktop\LB\DS>Myexe.exe
| 11 |->| 21 |->| 51 |->| 75 |->NULL
Number of Nodes are : 4
| 11 |->| 21 |->| 51 |->| 75 |->| 101 |->| 111 |->| 121 |->NULL
Number of Nodes are : 7
| 21 |->| 51 |->| 75 |->| 101 |->| 111 |->| 121 |->NULL
Number of Nodes are : 6
| 21 |->| 51 |->| 75 |->| 101 |->| 111 |->NULL
Number of Nodes are : 5
*/