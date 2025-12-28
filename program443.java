class node
{
    public int data;
    public node next;
// ***********************IMPORTANT*********************************
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
        this.iCount=0;
    }

    public void InsertFirst(int no)
    {
        node newn = null;
        //******************Change Code ***********************
        newn = new node(no);
        
        newn.next = this.first;
        this.first = newn;

        this.iCount++;
    }

    public void InsertLast(int no)
    {
        node newn = null;
        newn = new node(no);
        node temp = null;

        if(this.first == null)
        {
            this.first = newn;
        }
        else
        {
           temp = this.first;
           while(temp.next != null)
           {
            temp =temp.next;

           }
        }
        this.iCount++;
    }

    public void InsertAtPos(int no,int pos)
    {}
//*****************************************************************************
    public void DeleteFirst()
    {}

    public void DeleteLast()
    {}

    public void DeleteAtPos(int pos)
    {}
//****************************************************************************
    public void Display()
    {
        node temp = null;
        temp = this.first;

        while(temp != null)
        {
            System.out.print(" | "+temp.data+ " | ->");
            temp = temp.next;
        }
        System.out.println("null");
    }


    public int Count()
    {
        return this.iCount;
    }



}
class program443
{
    public static void main(String A[])
    {
        SinglyLL obj = null;
        obj = new SinglyLL();
        int iRet = 0;

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);

        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of Nodes are : "+iRet);

        obj.Insertlast();
        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of Nodes are : "+iRet);

        // ********************IMPORTANT FOR MEMORY DEALLOCATION********************************
        obj = null;
        System.gc();
    }
}