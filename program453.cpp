// DoublyLL
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

class DoublyLL
{
private:
    PNODE first;
    int iCount;

public:
    DoublyLL()
    {

        this->first = NULL;
        this->iCount = 0;
    }

    void InsertFirst(int no)
    {
        PNODE newn = NULL;
        newn = new node();
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        if (first == NULL)
        {
            first = newn;
        }
        else
        {
            newn->next = first;
            first->prev = newn;
            first = newn;
        }

        iCount++;
    }

    void InsertLast(int no)
    {
        PNODE temp = NULL;
        PNODE newn = NULL;
        newn = new node();
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;
        if (first == NULL)
        {
            first = newn;
        }
        else
        {
            temp = first;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;
            newn->prev = temp;
        }
        iCount++;
    }

    void InsertAtPos(int no, int pos)
    {
        PNODE newn = NULL;
        PNODE temp = NULL;
        int i = 0;

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
            newn = new node();
            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            for (i = 1; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            newn->next = temp->next;
            newn->prev = temp;
            temp->next = newn;
            newn->next->prev = newn;
            iCount++;
        }
    }

    void DeleteFirst()
    {
        if (first->next == NULL)
        {
            delete first;
            iCount--;
        }
        else
        {
            first = first->next;
            delete first->prev;
            first->prev = NULL;
            iCount--;
        }
    }

    void DeleteLast()
    {
        PNODE temp = NULL;

        if (first->next == NULL)
        {
            delete first;
            iCount--;
        }
        else
        {
            temp = first;
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
            iCount--;
        }
    }

    void DeleteAtPos(int pos)
    {
        PNODE temp = NULL;
        int i = 0;

        if (pos < 1 && pos > iCount + 1)
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
            temp->next = temp->next->next;
            delete temp->next->prev;
            temp->next->prev = temp;
            iCount--;
        }
    }

    void Display()
    {
        PNODE temp = NULL;
        temp = first;
        while (temp != NULL)
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
};

int main()
{
    DoublyLL obj;
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