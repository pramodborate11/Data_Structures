#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;

class SinglyLL
{
    public :
        PNODE first;
        PNODE last;
        int iCount;
        
        SinglyLL()
        {
            cout<<"Object of SinglyLL gets created.\n";
            first = NULL;
            last = NULL;
            iCount = 0;
        }
        
        void InsertFirst(int no)
        {
            PNODE newn = NULL;
            newn = new NODE;
            
            newn->data = no;
            newn->next = NULL;
            
            newn->next = first;         //Update 
            first = newn;
    
            iCount++;                     //IMP
        }
        
        void InsertLast(int no)
        {
            PNODE temp = NULL;
            PNODE newn = NULL;
            newn = new NODE;
            
            newn->data = no;
            newn->next = NULL;

            if(iCount == 0)   // Updated
            {
                first = newn;
                last = newn;
            }
            else                // list has nodes
            {
                temp = first ;

                while(temp -> next != NULL)
                {
                    temp = temp -> next;
                }

                temp -> next = newn;
            }

            iCount++;
        }

        
 //------------------------------------------------------------------------------------------       
        void DeleteFirst()
        {
            PNODE temp = NULL;
            if(first == NULL)
            {
                return;
            }
            else if(first -> next == NULL)         // iCount == NULL
            {
                delete first;
                first = NULL;
            }
            else
            {
               temp = first;
               first = first -> next;
               delete temp;
            }
            iCount--;
        }
        
        void DeleteLast()
        {
            PNODE temp = NULL;
            if(first == NULL)
            {
                return;
            }
            else if(first -> next == NULL)         // iCount == NULL
            {
                delete first;
                first = NULL;
            }
            else
            {
                temp = first ;

                while (temp -> next -> next != NULL)
                {
                    temp = temp -> next;
                }
                delete temp-> next;
                temp-> next = NULL;
            }
            iCount--;
        }
        
        
        
        void Display()
        {
            PNODE temp = NULL;
            int iCnt = 0;
            temp = first;
            
            for(iCnt = 1; iCnt <= iCount ;iCnt++)         // UPDATED
            {
                cout<<"| "<<temp->data<<" | -> ";
                temp = temp -> next;
            }
            
            cout<<"NULL\n";
        }
        
        int Count()
        {
            return iCount;
        }

        
        void InsertAtPos(int  no, int pos)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;
            int iCnt = 0;
            
            if((pos < 1) || (pos > iCount+1))   // for negative position 
            {
                cout<<"Invalid Position\n";
                return;
            }
            
            if(pos == 1)
            {
                InsertFirst(no);
            }
            else if(pos == iCount+1)
            {
                InsertLast(no);
            }
            else
            {
                newn = new NODE;
                newn->data = no;
                newn->next = NULL;
                temp  = first;
                
                for(iCnt = 1; iCnt < pos-1; iCnt++)
                {
                    temp = temp -> next;
                }
                newn->next = temp->next;
                temp->next = newn;
                
                iCount++;
            }
        }

        void DeleteAtPos(int pos)
        {
            PNODE temp = NULL;
            PNODE target = NULL;                           
            int iCnt = 0;
            
            if((pos < 1) || (pos > iCount))
            {
                cout<<"Invalid Position\n";
                return;
            }
            
            if(pos == 1)
            {
                DeleteFirst();
            }
            else if(pos == iCount)
            {
                DeleteLast();
            }
            else
            {
                temp = first;
                
                for(iCnt = 1; iCnt < pos-1; iCnt++)
                {
                    temp = temp -> next;
                }
                
                target = temp->next;
                
                temp->next = target->next;
                delete target;
                
                iCount--;
            }
        }
};



int main()
{
    SinglyLL obj1;
    SinglyLL obj2;
    int iRet = 0;
    
    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);
    
    obj1.Display();
    iRet = obj1.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj1.InsertLast(101);
    obj1.InsertLast(111);
    obj1.InsertLast(121);  
    
    obj1.Display();
    iRet = obj1.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj1.DeleteFirst();

    obj1.Display();
    iRet = obj1.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj1.DeleteLast();

    obj1.Display();
    iRet = obj1.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";


    obj1.InsertAtPos(105,4);

    obj1.Display();
    iRet = obj1.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj1.DeleteAtPos(4);

    obj1.Display();
    iRet = obj1.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";    
    
    return 0;
}

/*

C:\Users\admin\OneDrive\Desktop\LB\DS>myexe.exe
Object of SinglyLL gets created.
Object of SinglyLL gets created.
| 11 | -> | 21 | -> | 51 | -> NULL
Number of nodes are : 3
| 11 | -> | 21 | -> | 51 | -> | 101 | -> | 111 | -> | 121 | -> NULL
Number of nodes are : 6
| 21 | -> | 51 | -> | 101 | -> | 111 | -> | 121 | -> NULL
Number of nodes are : 5
| 21 | -> | 51 | -> | 101 | -> | 111 | -> NULL
Number of nodes are : 4
| 21 | -> | 51 | -> | 101 | -> | 105 | -> | 111 | -> NULL
Number of nodes are : 5
| 21 | -> | 51 | -> | 101 | -> | 111 | -> NULL
Number of nodes are : 4
*/
