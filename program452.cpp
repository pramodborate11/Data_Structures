// DoublyCL
#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node *PNODE;

class DoublyCL
{
private:
    PNODE first;
    PNODE last;
    int iCount;

public:
    DoublyCL()
    {
        cout << "Object of DoublyCL gets Created..\n";
        this->first = NULL;
        this->last = NULL;
        this->iCount = 0;
    }

    void InsertFirst(int no)
    {
        PNODE newn = NULL;
        newn = new node();

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        if (first == NULL && last == NULL)
        {
            first = newn;
            last = newn;
            last->next = first;
            first->prev = last;
        }
        else
        {
            first->prev = newn;

            newn->next = first;
            newn->prev = last;
            first = newn;
            last->next = first;
        }
        iCount++;
    }

    void InsertLast(int no)
    {
        PNODE newn = NULL;
        newn = new node();

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        if (first == NULL && last == NULL)
        {
            first = newn;
            last = newn;
            last->next = first;
            first->prev = last;
        }
        else
        {
            last->next = newn;
            newn->prev = last;
            last = newn;
            last->next = first;
        }
        iCount++;
    }

    void InsertAtPos(int no, int pos)
    {
        int i = 0;
        PNODE newn = NULL;
        PNODE temp = NULL;
        if (pos < 1 || pos > iCount + 1)
        {
            cout << "Invalid Position";
            return;
        }

        if (pos == 1)
        {
            InsertFirst(no);
        }
        else if (pos == iCount + 1)
        {
            InsertLast(no);
        }
        else
        {
            temp = first;
            newn = new node();
            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;
            for (i = 1; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            newn->prev = temp;
            newn->next = temp->next;
            temp->next = newn;
            newn->next->prev = newn;
            iCount++;
        }
    }

    void DeleteFirst()
    {
        if (first == NULL && last == NULL)
        {
            cout << "Linked list is empty\n";
            return;
        }

        if (first == last)
        {
            delete first;
            first = NULL;
            last = NULL;
        }

        else
        {
            first = first->next;
            delete first->prev;
            first->prev = last;
        }
        iCount--;
    }

    void DeleteLast()
    {
        if (first == NULL && last == NULL)
        {
            cout << "Linked list is empty\n";
            return;
        }

        if (first == last)
        {
            delete first;
            first = NULL;
            last = NULL;
        }
        else
        {
            last = last->prev;
            delete last->next;
            last->next = first;
        }
        iCount--;
    }

    void DeleteAtPos(int pos)
    {
        int i = 0;
        PNODE temp = NULL;
        PNODE target = NULL;
        if (pos < 1 || pos > iCount)
        {
            cout << "Invalid Position\n";
            return;
        }

        if (pos == 1)
        {
            DeleteFirst();
        }
        else if (pos == iCount)
        {
            DeleteLast();
        }
        else
        {
            temp = first;
            for (i = 1; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            target = temp->next;
            temp->next = temp->next->next;
            temp->next->prev = temp;
            delete target;
            iCount--;
        }
    }

    void Display()
    {
        int i = 0;
        PNODE temp = NULL;
        temp = first;
        for (i = 1; i <= iCount; i++)
        {
            cout << "|" << temp->data << "|=>";
            temp = temp->next;
        }
        cout << "\n";
    }

    int Count()
    {
        return iCount;
    }
};

int main()
{
    DoublyCL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();
    iRet = obj.Count();
    cout << "Number Of Nodes are :" << iRet << "\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();
    iRet = obj.Count();
    cout << "Number Of Nodes are :" << iRet << "\n";

    obj.DeleteFirst();
    obj.Display();
    iRet = obj.Count();
    cout << "Number Of Nodes are :" << iRet << "\n";

    obj.DeleteLast();
    obj.Display();
    iRet = obj.Count();
    cout << "Number Of Nodes are :" << iRet << "\n";

    obj.InsertAtPos(105, 4);
    obj.Display();
    iRet = obj.Count();
    cout << "Number Of Nodes are :" << iRet << "\n";

    obj.DeleteAtPos(4);
    obj.Display();
    iRet = obj.Count();
    cout << "Number Of Nodes are :" << iRet << "\n";

    return 0;

   
}