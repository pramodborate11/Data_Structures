#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
typedef struct node
{
    int data;
    struct node *next;
}NODE,*PNODE, **PPNODE;


int main()
{
   PNODE ptr = NULL;

   ptr = (PNODE)malloc(sizeof(NODE));

   //Use The Node 
   
    free(ptr);

    return 0;
}

/*
out put :

*/