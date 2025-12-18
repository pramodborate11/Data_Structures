#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;   // type def
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;
//-------------------------------------------------------------------
void InsertFirst(PPNODE first ,int no)
{
    PNODE newn = NULL ;

    newn =(PNODE) malloc(sizeof(NODE));

    newn -> data = no;
    newn-> next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn -> next = (*first);
        *first = newn;
    }
    
}

void InsertLast(PPNODE first ,int no)
{
    PNODE newn = NULL ;
    PNODE temp = NULL;

    newn =(PNODE) malloc(sizeof(NODE));

    newn -> data = no;
    newn-> next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;
            
        while(temp -> next != NULL)  // Type 2
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
}


//----------------------------------------------------------------------
void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;
   if(*first == NULL)   //case 1
   {
    return ;
   }
   else if((*first) -> next ==NULL)   // case 2
   {
    free(*first);
    *first = NULL;
   }
   else                               //case 3
   {
    temp = (*first);
    (*first) = (*first) -> next;
    free(temp);
   }
}
void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;
    if(*first == NULL)
   {
    return ;
   }
   else if((*first) -> next ==NULL)
   {
    free(*first);
    *first = NULL;
   }
   else
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

//------------------------------------------------------------------------
void Display(PNODE first)
{
   while(first != NULL)       // Type 1
    {
        printf("| %d |->",first -> data);
        first = first -> next;
    }
    printf("NULL \n");
}

int Count(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first->next;
    }
    return iCount;
}
//----------------------------------------------------------------------
void InsertAtPos(PPNODE first ,int no,int pos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    int iCnt = 0;
    int iSize = 0;
    iSize = Count(*first);

    if((pos < 1) || (pos > iSize +1))     // Filter 
    {
      printf("Invalid Position \n");
      return ;
    }

    if(pos == 1)
    {
        InsertFirst(first ,no);
    }
    else if(pos == (iSize + 1))
    {
        InsertLast(first,no);
    }
    else
    {
      newn = (PNODE)malloc (sizeof(NODE));

      newn -> data= no;
      newn -> next = NULL;

      temp = *first;

      for(iCnt = 1; iCnt<pos-1;iCnt++)
      {
        temp = temp ->next;
      }

      newn -> next = temp -> next;
      temp -> next = newn;

    }
}
//--------------------------------------------------------
void DeleteAtPos(PPNODE first,int pos)
{
    int iSize = 0;
    iSize = Count(*first);
    int iCnt = 0;

    PNODE temp = NULL;
    PNODE target = NULL;

    if((pos < 1) || (pos > iSize))     // Filter 
    {
      printf("Invalid Position \n");
      return ;
    }

    if(pos == 1)
    {
        DeleteFirst(first);
    }
    else if(pos == (iSize))
    {
        DeleteLast(first);
    }
    else
    {
        temp = *first;
        
        for(iCnt = 1;iCnt <pos -1 ;iCnt++)
        {
            temp = temp ->next;
        }

        target = temp -> next;

        temp -> next = target -> next;
        free(target);
    }
}
//-------------------------------------------------------------------------
int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    Display(head);
    iRet = Count(head);
    printf("Number of Nodes are : %d\n",iRet);
//---------------------------------------------------------------------------
    InsertLast(&head,101);
    InsertLast(&head,111);
    InsertLast(&head,121);

    Display(head);
    iRet = Count(head);
    printf("Number of Nodes are : %d\n",iRet);
//-------------------------------------------------------------------
    DeleteFirst(&head);

    Display(head);
    iRet = Count(head);
    printf("Number of Nodes are : %d\n",iRet);

    DeleteLast(&head);
    
    Display(head);
    iRet = Count(head);
    printf("Number of Nodes are : %d\n",iRet);

//----------------------------------------------------------------------------

    InsertAtPos(&head,105,3);

    Display(head);
    iRet = Count(head);
    printf("Number of Nodes are : %d\n",iRet);

//-------------------------------------------------------------------------
    DeleteAtPos(&head,3);

    Display(head);
    iRet = Count(head);
    printf("Number of Nodes are : %d\n",iRet);

    return 0;
}

/*
output:
C:\Users\admin\OneDrive\Desktop\LB\DS>gcc program393.c -o myexe

C:\Users\admin\OneDrive\Desktop\LB\DS>myexe.exe
| 11 |->| 21 |->| 51 |->NULL
Number of Nodes are : 3
| 11 |->| 21 |->| 51 |->| 101 |->| 111 |->| 121 |->NULL
Number of Nodes are : 6
| 21 |->| 51 |->| 101 |->| 111 |->| 121 |->NULL
Number of Nodes are : 5
| 21 |->| 51 |->| 101 |->| 111 |->NULL
Number of Nodes are : 4
| 21 |->| 51 |->| 105 |->| 101 |->| 111 |->NULL
Number of Nodes are : 5
| 21 |->| 51 |->| 101 |->| 111 |->NULL
Number of Nodes are : 4

C:\Users\admin\OneDrive\Desktop\LB\DS>
*/