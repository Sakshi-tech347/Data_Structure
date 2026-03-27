
class node
{
    int data;
    node next;
    node prev;
}

class DoublyCL
{
    public node first;
    public node last;
    public int iCount;

    DoublyCL()
    {
        first = null;
        last = null;
        iCount = 0;

    }

    public void Display()
    {
        node temp = null;
        temp = first;
            System.out.print("<=>");
        do
            {
                System.out.print("|"+temp.data+"|<=>");
                temp = temp.next;
            }while(temp != first);
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
        newn.prev = null;
        newn.data = no;

        if(first == null  && last == null)
            {
                first = newn;
                last = newn;

            }
            else
                {
                    newn.next = first;
                    first.prev = newn;

                    first = newn;

                }

                first.prev = last;
                last.next =first;
                iCount++;

    }


    public void InsertLast(int no)
    {
        node newn = null;
        node temp = null;

        newn = new node();

        newn.next = null;
        newn.prev = null;
        newn.data = no;

        if(first == null && last == null )
            {
                first = newn;
                last = newn;

            }
            else
                {
                    temp = first;

                    while(temp != last)
                        {
                            temp =temp.next;
                        }
                        temp.next= newn;
                        newn.prev = temp;

                        last = newn;

                }


                first.prev = last;
                last.next =first;
                iCount++;

    }

    public void InsertAtPos(int no , int pos)
    {
        node newn = null;
        node temp = null;

        int i = 0;

        newn = new node();


        newn.next = null;
        newn.prev = null;
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
                    newn.prev= temp;


                    temp.next.prev = newn;
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
                first.prev = last;
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

                    last = last.prev;
                    last.next = first;
                    temp = null;

                     

                }
                last.next = first;
                first.prev = last;

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
                    target.next.prev = temp; 

                     
                    System.gc();
                    iCount-- ;
            }

    }


}

class program4
{
    public static void main(String A[])
    {
        DoublyCL dobj;
        dobj = new DoublyCL();


        dobj.InsertFirst(51);
        dobj.InsertFirst(21);
        dobj.InsertFirst(11);


        dobj.Display();
        System.out.println("Number of nodes are :"+dobj.Count());

        dobj.InsertLast(101);
        dobj.InsertLast(111);
        dobj.InsertLast(121);

        dobj.Display();
        System.out.println("Number of nodes are :"+dobj.Count());


        dobj.InsertAtPos(105,4 );
        dobj.Display();
        System.out.println("Number of nodes are :"+dobj.Count());

        dobj.DelelteAtPos(4);
        dobj.Display();
        System.out.println("Number of nodes are :"+dobj.Count());


        dobj.DelelteFirst();
        dobj.Display();
        System.out.println("Number of nodes are :"+dobj.Count());

        dobj.DelelteLast();
        dobj.Display();
        System.out.println("Number of nodes are :"+dobj.Count());





        dobj = null;
    }
}

