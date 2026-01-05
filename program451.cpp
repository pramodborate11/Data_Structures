
// Singly CL
#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;

class SinglyCL
{
private:
    PNODE first;
    PNODE last;
    int iCount;

public:
    SinglyCL()
    {
        cout << "Object of SinglyCL gets Created..\n";
        this->first = NULL;
        this->last = NULL;
        this->iCount = 0;
    }

    void InsertFirst(int no)
    {
        PNODE newn = new node();
        newn->data = no;
        newn->next = NULL;

        if (first == NULL && last == NULL) // Linked List is Empty
        {
            first = newn;
            last = newn;
            newn->next = first;
        }
        else
        {
            newn->next = first;
            first = newn;
            last->next = first;
        }
        iCount++;
    }

    void InsertLast(int no)
    {
        PNODE newn = new node();
        newn->data = no;
        newn->next = NULL;

        if (first == NULL && last == NULL) // Linked List is Empty
        {
            first = newn;
            last = newn;
            newn->next = first;
            iCount++;
        }
        else if (first->next == first)
        {
            first->next = newn;
            newn->next = first;
            last = newn;
        }
        else
        {
            int i = 0;
            PNODE temp = NULL;
            temp = first;
            for (i = 1; i < iCount; i++)
            {
                temp = temp->next;
            }

            temp->next = newn;
            newn->next = first;
            last = newn;
        }
        iCount++;
    }

    void DeleteFirst()
    {
        if (first == NULL && last == NULL)
        {
            cout << "Linked is already Empty\n";
            return;
        }
        else if (first->next == first)
        {
            delete first;
            first = NULL;
            last = NULL;
            iCount--;
        }
        else
        {
            PNODE temp = NULL;
            temp = first;
            first = first->next;
            delete temp;
            last->next = first;
            iCount--;
        }
    }

    void DeleteLast()
    {
        if (first == NULL && last == NULL)
        {
            cout << "Linked List is Already Empty\n";
        }
        else if (first->next == first)
        {
            delete last;
            first = NULL;
            last = NULL;
            iCount--;
        }
        else
        {
            PNODE temp = NULL;
            temp = first;
            while (temp->next->next != first)
            {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = first;
            iCount--;
        }
    }

    void Display()
    {
        PNODE temp = first;
        int i = 0;
        for (i = 0; i < iCount; i++)
        {
            cout << "|" << temp->data << "|->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    int Count()
    {
        return iCount;
    }
    void InsertAtPos(int no, int pos)
    {
        int i = 0;
        PNODE temp = NULL;
        PNODE newn = NULL;

        if (pos < 1 || pos > iCount + 1)
        {
            cout << "Invalid Position\n";
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
            newn = new NODE();
            newn->data = no;
            newn->next = NULL;
            for (i = 1; i < pos - 1; i++)
            {
                temp = temp->next;
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
        int i = 0;
        if (pos < 1 && pos > iCount)
        {
            cout << "Invalid Position\n";
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
            temp->next = target->next;
            delete target;
            iCount--;
        }
    }
};

int main()
{
    SinglyCL obj;
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

    return 0;
}
