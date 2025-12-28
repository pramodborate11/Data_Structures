class node {
    public int data;
    public node next;

    // Impornat
    public node(int no) {
        this.data = no;
        this.next = null;
    }
}

class SinglyLL {
    public node first;
    public int iCount;

    SinglyLL() {
        System.out.println("Object of SinglyLL gets Created");
        this.first = null;
        this.iCount = 0;
    }

    public void InsertFirst(int no) {
        node newn = null;

        newn = new node(no);

        newn.next = this.first;
        this.first = newn;
        this.iCount++;
    }

    public void InsertLast(int no) {
        node newn = null;
        newn = new node(no);

        if (this.first == null) {
            this.first = newn;
        } else {
            node temp = null;
            temp = this.first;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = newn;

        }
        this.iCount++;

    }

    public void InsertAtPos(int no, int pos) {

    }

    public void DeleteFirst() 
    {
        if (this.first==null) 
        {
            return;    
        }
        else if(this.first.next==null)
        {
            this.first=null;
        }
        else
        {
            this.first=this.first.next;
        }
        iCount--;
        System.gc();
    }

    public void DeleteLast()
    {
        node temp = null;
        
        if (this.first==null) 
            {
                return;    
            }
            else if(this.first.next==null)
            {
                this.first=null;
            }
            else
            {
                temp = this.first;
                
                while(temp.next.next != null)
                {
                    temp = temp.next;
                    
                }
                temp.next = null;
            }
            System.gc();
            iCount--;
    }

    public void DeleteAtPos() {

    }

    public void Display() {
        node temp = null;
        temp = this.first;

        while (temp != null) {
            System.out.print("| " + temp.data + "|->");
            temp = temp.next;
        }
        System.out.println("null");

    }

    public int Count() {
        return iCount;
    }

}

public class program445 {
    public static void main(String[] A) {
        SinglyLL obj = null;
        int iRet = 0;

        obj = new SinglyLL();

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);

        obj.Display();

        iRet = obj.Count();

        System.out.println("No.of Node is :" + iRet);

        obj.InsertLast(101);
        obj.InsertLast(111);
        obj.InsertLast(121);

        obj.Display();

        iRet = obj.Count();

        System.out.println("No.of Node is :" + iRet);

        obj.DeleteFirst();

        obj.Display();
        iRet = obj.Count();
        System.out.println("No.of Node is :" + iRet);

        obj.DeleteLast();

        obj.Display();
        iRet = obj.Count();
        System.out.println("No.of Node is :" + iRet);

        // Important For Memory Deallocation
        obj = null;
        System.gc();

    }
}
