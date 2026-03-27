
class node 
{
    public int data;
    public node next;
    public node prev;

}

class DoublyLL
{
    public node first;
    public int iCount;

    public DoublyLL()
    {
        first = null;
        iCount = 0;
    }

    public void Display()
    {
        node temp = null;
        temp = first;
        while(temp != null)
            {
                System.out.print("|"+temp.data+"|<=>");
                temp = temp.next;
            }
            System.out.println("NULL");
    }

    public int Count()
    {
        return iCount;  
    }

    public void InsertFirst(int no )
    {
        node newn = null;
        newn  = new node();
        newn.data = no;
        newn.next = null;
        newn.prev = null;

        if(first == null)
            {
                first = newn;
            }
        else
            {
                newn.next = first;
                first.prev = newn;

                first = newn;

            }
            iCount++;

    }

    public void InsertLast(int no )
    {   node newn = null;
        node temp = null;

        newn  = new node();
        newn.data = no;
        newn.next = null;
        newn.prev = null;

        if(first == null)
            {
                first = newn;
            }
        else
            {

                temp = first;
                while (temp.next != null) 
                {
                        temp = temp.next;
                }
                 

                temp.next = newn;
                newn.prev = temp;


            }
            iCount++;
 }

    public void InsertAtPos(int no ,int pos)
    {
        node newn = null;
        node temp = null;
        int i = 0;

        newn  = new node();
        newn.data = no;
        newn.next = null;
        newn.prev = null;

        if (pos<1 || pos> iCount + 1)
            {
                System.out.println("Invalid position");
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
                            temp = first;
                            for(i = 1; i<pos-1 ; i++ )
                                {
                                    temp = temp.next;
                                }
                                newn.next = temp.next;
                                newn.prev = temp;

                                temp.next.prev = newn;
                                temp.next= newn;


                                iCount++;
                        }

    }

    public void DelelteFirst()
    {
        if(first == null)
            {
                return;
            }
            else if(first.next == null)
                {
                    first = null;
                }
                else
                    {
                        first = first.next;
                        first.prev = null;

                    }

                    System.gc();
                    iCount--;
    }

    public void DelelteLast()
    {
        node temp = null;
        if(first == null)
            {
                return;
            }
            else if(first.next == null)
                {
                    first = null;
                }
                else
                    {
                        temp = first;

                        while(temp.next.next != null)
                            {
                                temp = temp.next;
                            }

                            temp.next = null;
                         

                    }

                    System.gc();
                    iCount--;
    }

    public void DelelteAtPos(int pos)
    {
        node temp = null;
        node target = null;

        int i = 0;

        

        if (pos<1 || pos> iCount + 1)
            {
                System.out.println("Invalid position");
                return;
            }

            if(pos == 1)
                {
                    DelelteFirst();
                }
                else if(pos == iCount+1)
                    {
                        DelelteLast();
                    }
                    else
                        {
                            temp = first;
                            for(i = 1; i<pos-1 ; i++ )
                                {
                                    temp = temp.next;
                                }
                                 target = temp.next;
                                 temp.next = temp.next.next;
                                 target.next.prev = temp;

                                 target= null;

                                iCount--;
                                System.gc();
                        }
    }

}


class program3
{
    public static void main(String A[])
    {
         
        DoublyLL dobj = new DoublyLL();
        int iRet = 0;

        dobj.InsertFirst(51);
        dobj.InsertFirst(21);
        dobj.InsertFirst(11);

        dobj.Display();
        iRet = dobj.Count();
        System.out.println(" Number of nodes are : "+iRet);

        dobj.InsertLast(101);
        dobj.InsertLast(111);
        dobj.InsertLast(121);

        dobj.Display();
        iRet = dobj.Count();
        System.out.println(" Number of nodes are : "+iRet);

        dobj.InsertAtPos(105, 4);
        dobj.Display();
        iRet = dobj.Count();
        System.out.println(" Number of nodes are : "+iRet);

        dobj.DelelteAtPos(4);
        dobj.Display();
        iRet = dobj.Count();
        System.out.println(" Number of nodes are : "+iRet);

        dobj.DelelteFirst();
        dobj.Display();
        iRet = dobj.Count();
        System.out.println(" Number of nodes are : "+iRet);

        dobj.DelelteLast();
        dobj.Display();
        iRet = dobj.Count();
        System.out.println(" Number of nodes are : "+iRet);


        dobj =null;
    }   
}
