// USE OF this->
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
    private :
        PNODE first;
        int iCount;
        
    public :    
        SinglyLL()
        {
            cout<<"Object of SinglyLL gets created.\n";
            this->first = NULL;
            this->iCount = 0;
        }
        
        void InsertFirst(int no)
        {
            PNODE newn = NULL;
            newn = new NODE;
            
            newn->data = no;
            newn->next = NULL;
            
            newn->next = this->first;         //Update 
            this->first = newn;
    
            this->iCount++;                     //IMP
        }
        
        void InsertLast(int no)
        {
            PNODE temp = NULL;
            PNODE newn = NULL;
            newn = new NODE;
            
            newn->data = no;
            newn->next = NULL;

            if(this->iCount == 0)   // Updated
            {
                first = newn;
               
            }
            else                // list has nodes
            {
                temp = this->first ;

                while(temp -> next != NULL)
                {
                    temp = temp -> next;
                }

                temp -> next = newn;
            }

            this->iCount++;
        }

        
 //------------------------------------------------------------------------------------------       
        void DeleteFirst()
        {
            PNODE temp = NULL;
            if(first == NULL)
            {
                return;
            }
            else if(this->first -> next == NULL)         // iCount == NULL
            {
                delete this->first;
                this->first = NULL;
            }
            else
            {
               temp = this->first;
               this->first = this->first -> next;
               delete temp;
            }
            this->iCount--;
        }
        
        void DeleteLast()
        {
            PNODE temp = NULL;
            if(this->first == NULL)
            {
                return;
            }
            else if(this->first -> next == NULL)         // iCount == NULL
            {
                delete this->first;
                this->first = NULL;
            }
            else
            {
                temp = this->first ;

                while (temp -> next -> next != NULL)
                {
                    temp = temp -> next;
                }
                delete temp-> next;
                temp-> next = NULL;
            }
            this->iCount--;
        }
        
        
        
        void Display()
        {
            PNODE temp = NULL;
            int iCnt = 0;
            temp = this->first;
            
            for(iCnt = 1; iCnt <= iCount ;iCnt++)         // UPDATED
            {
                cout<<"| "<<temp->data<<" | -> ";
                temp = temp -> next;
            }
            
            cout<<"NULL\n";
        }
        
        int Count()
        {
            return this->iCount;
        }

        
        void InsertAtPos(int  no, int pos)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;
            int iCnt = 0;
            
            if((pos < 1) || (pos > this->iCount+1))   // for negative position 
            {
                cout<<"Invalid Position\n";
                return;
            }
            
            if(pos == 1)
            {
                this->InsertFirst(no);
            }
            else if(pos == this->iCount+1)
            {
                this->InsertLast(no);
            }
            else
            {
                newn = new NODE;
                newn->data = no;
                newn->next = NULL;
                temp  = this->first;
                
                for(iCnt = 1; iCnt < pos-1; iCnt++)
                {
                    temp = temp -> next;
                }
                newn->next = temp->next;
                temp->next = newn;
                
                this->iCount++;
            }
        }

        void DeleteAtPos(int pos)
        {
            PNODE temp = NULL;
            PNODE target = NULL;                           
            int iCnt = 0;
            
            if((pos < 1) || (pos > this->iCount))
            {
                cout<<"Invalid Position\n";
                return;
            }
            
            if(pos == 1)
            {
                this->DeleteFirst();
            }
            else if(pos == iCount)
            {
                this->DeleteLast();
            }
            else
            {
                temp = this->first;
                
                for(iCnt = 1; iCnt < pos-1; iCnt++)
                {
                    temp = temp -> next;
                }
                
                target = temp->next;
                
                temp->next = target->next;
                delete target;
                
                this->iCount--;
            }
        }
};



int main()
{
    SinglyLL obj1;
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


*/
