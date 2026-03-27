
class node
{
    int data;
    node next;
}

class SinglyCL
{
    public node first;
    public node last;
    public int iCount;

    SinglyCL()
    {
        first = null;
        last = null;
        iCount = 0;

    }

    public void Display()
    {
        node temp = null;
        temp = first;
            System.out.print("<->");
        do
            {
                System.out.print("|"+temp.data+"|<->");
                temp = temp.next;
            }while(temp.next != first);
            System.out.println("");
    }

    public int Count()
    {
        return iCount;
    }

    public void InsertFirst(int no)
    {
        node newn = null;
        newn = new node();

        newn.next = null;
        newn.data = no;

        if(first == null )
            {
                first = newn;
                last = newn;
            
            }
            else
                {
                    newn.next = first;
                    first = newn;
                }

                last.next = first;
                iCount++;

    }


    public void InsertLast(int no)
    {
        node newn = null;
        newn = new node();

        newn.next = null;
        newn.data = no;

        if(first == null )
            {
                first = newn;
                last = newn;
            
            }
            else
                {
                    last.next = newn;
                    last = newn;

                }

                
                last.next = first;

                iCount++;

    }

    public void InsertAtPos(int no , int pos)
    {
        node newn = null;
        node temp = null;

        int i = 0;

        newn = new node();


        newn.next = null;
        newn.data = no;

        if(pos < 1 || pos > iCount + 1)
            {
                System.out.println("Invalid position ");
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
                for(i = 1 ; i<pos -1 ; i++)
                    {
                        temp = temp.next;
                    }

                    newn.next = temp.next;


                    temp.next = newn;

                    
                    iCount++;

            }
    }

    public void DelelteFirst()
    {

        node temp = null;

        if(first == null && last == null)
            {   
                System.out.println("Linked list is empty");
                return;
            }
            else if(first == last)
                {
                    first = null;
                    last = null;

                }
                else
                {
                    temp = first;
                    first = first.next;
                    
                    temp = null;

                }
                last.next= first;
                System.gc();
                iCount--;
        
    }

    public void DelelteLast()
    {
            node temp = null;
        
            if(first == null && last ==null)
            {   
                System.out.println("Linked list is empty");
                return;
            }
            else if(first== last)
                {
                    first = null;
                    last =null;

                }
                else
                {
                    temp = last;

                    last.next = first;
                    temp = null;

                     

                }
                last.next = first;

                System.gc();
                iCount--; 
    }

    public void DelelteAtPos(int pos)
    {
        node temp = null;
        node target = null;

        int i = 0;

         

        if(pos < 1 || pos > iCount + 1)
            {
                System.out.println("Invalid position ");
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
                for(i = 1 ; i<pos -1 ; i++)
                    {
                        temp = temp.next;
                    }

                    target = temp.next;

                    temp.next = target.next;

                     
                    System.gc();
                    iCount-- ;
            }

    }


}

class program2
{
    public static void main(String A[])
    {
        SinglyCL sobj;
        sobj = new SinglyCL();


        sobj.InsertFirst(51);
        sobj.InsertFirst(21);
        sobj.InsertFirst(11);


        sobj.Display();
        System.out.println("Number of nodes are :"+sobj.Count());

        sobj.InsertLast(101);
        sobj.InsertLast(111);
        sobj.InsertLast(121);

        sobj.Display();
        System.out.println("Number of nodes are :"+sobj.Count());

        sobj.InsertAtPos(105, 4);
        sobj.Display();
        System.out.println("Number of nodes are :"+sobj.Count());

        sobj.DelelteAtPos(4);
        sobj.Display();
        System.out.println("Number of nodes are :"+sobj.Count());

        sobj.DelelteFirst();
        sobj.Display();
        System.out.println("Number of nodes are :"+sobj.Count());

        sobj.DelelteLast();
        sobj.Display();
        System.out.println("Number of nodes are :"+sobj.Count());
         
        sobj = null;
    }
}

