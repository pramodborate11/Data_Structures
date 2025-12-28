class node
{
    public int data;
    public node next;

    public node(int no)
    {
        this.data = no;
        this.next = null;
    }
}

class SinglyLL
{
    public node first;
    public int iCount;

    SinglyLL()
    {
        System.out.println("Object of SinglyLL gets created");
        this.first = null;
        this.iCount = 0;
    }

    // Insert at first
    public void InsertFirst(int no)
    {
        node newn = new node(no);

        newn.next = this.first;
        this.first = newn;
        this.iCount++;
    }

    // Insert at last
    public void InsertLast(int no)
    {
        node newn = new node(no);

        if(this.first == null)
        {
            this.first = newn;
        }
        else
        {
            node temp = this.first;

            while(temp.next != null)
            {
                temp = temp.next;
            }
            temp.next = newn;
        }
        this.iCount++;
    }

    // Insert at position
    public void InsertAtPos(int no, int pos)
    {
        if(pos < 1 || pos > iCount + 1)
        {
            System.out.println("Invalid Position");
            return;
        }

        if(pos == 1)
        {
            InsertFirst(no);
        }
        else if(pos == iCount + 1)
        {
            InsertLast(no);
        }
        else
        {
            node newn = new node(no);
            node temp = this.first;

            for(int i = 1; i < pos - 1; i++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next = newn;
            iCount++;
        }
    }

    // Delete first
    public void DeleteFirst()
    {
        if(this.first == null)
        {
            return;
        }

        this.first = this.first.next;
        this.iCount--;
    
    }

    // Delete last
    public void DeleteLast()
    {
        if(this.first == null)
        {
            return;
        }
        else if(this.first.next == null)
        {
            this.first = null;
        }
        else
        {
            node temp = this.first;

            while(temp.next.next != null)
            {
                temp = temp.next;
            }
            temp.next = null;
        }
        this.iCount--;
    }

    // Delete at position
    public void DeleteAtPos(int pos)
    {
        if(pos < 1 || pos > iCount)
        {
            System.out.println("Invalid Position");
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
            node temp = this.first;

            for(int i = 1; i < pos - 1; i++)
            {
                temp = temp.next;
            }

            temp.next = temp.next.next;
            iCount--;
        }
    }

    // Display list
    public void Display()
    {
        node temp = this.first;

        while(temp != null)
        {
            System.out.print(" | " + temp.data + " | -> ");
            temp = temp.next;
        }
        System.out.println("null");
    }

    public int Count()
    {
        return this.iCount;
    }
}

class program444
{
    public static void main(String A[])
    {
        SinglyLL obj = new SinglyLL();
        int iRet = 0;

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);

        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of Nodes are : "+iRet);

        obj.InsertLast(101);

        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of Nodes are : "+iRet);

        obj.InsertAtPos(75, 3);

        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of Nodes are : "+iRet);


        obj.DeleteAtPos(3);

        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of Nodes are : "+iRet);
        

        obj = null;
        System.gc();
    }
}
