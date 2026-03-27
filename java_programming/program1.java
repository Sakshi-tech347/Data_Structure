
class node
{
    public int data;
    public node next;
}

class SinglyLL
{
    public int iCount;
    public node first; 

    public SinglyLL()
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
            System.out.print("|"+temp.data+"|->");
            temp = temp.next;
        }
        System.out.println("NULL\n");
    }

    public int Count()
    {
        return iCount;
    }

    public void InsertFirst(int no)
    {   
        node newn = null;
        newn = new node();

        newn.data = no;
        newn.next = null;

        if(first == null)
            {
                first = newn;
            }
        else{
            newn.next = first;
            first = newn;
        }
        iCount++;

    }

    public void InsertLast(int no)
    {
        node newn = null;
        node temp =null;
        newn = new node();

        newn.data = no;
        newn.next = null;

        if(first == null)
            {
                first = newn;
            }
        else{
            temp =first;

            while(temp.next != null)
                {
                    temp = temp.next;
                }
                temp.next= newn;
               
        }
        iCount++;
    }
    public void InsertAtPos(int no , int pos )
    {
        node newn = null;
        node temp =null;
         int i =0;

        if(pos <1 || pos > iCount+1)
            {
                System.out.println("Invalid position");
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

                newn = new node();

                newn.data = no;
                newn.next = null;

                for(i = 1; i < pos - 1; i++)
                    {
                        temp = temp.next;
                    }

                    newn.next = temp.next;
                    temp.next = newn;

                    
            }
            iCount++;
    }

    public void DelelteFirst()
    {
        if(first == null)
            {
                return;
            }
            if(first.next == null)
                {
                        first= null;
                }
            else 
                {
                    node temp = null;
                    temp = first;

                    first = first.next;
                    temp = null;

                }
                System.gc();

                iCount --;
    }

    public void DelelteLast()
    { if(first == null)
            {
                return;
            }
            if(first.next == null)
                {
                        first= null;
                }
            else 
                {
                    node temp = null;
                    node target = null;
                    temp = first;
                    while(temp.next.next != null )
                        {
                            temp = temp.next;
                        }

                       target =  temp.next ;
                       target = null;

                       temp.next = null;


                     
                     

                }
                System.gc();

                iCount --;}

    public void DelelteAtPos(int pos)
    {    
        node temp = null;
        node target = null;

        int i =0;

        if(pos <1 || pos > iCount)
            {
                System.out.println("Invalid position");
                return;
            }
        if(pos == 1)
            {
                DelelteFirst();
            }

        else if(pos == iCount)
            {
                DelelteLast(); 
            }
        else
            {
                temp = first;

                
                for(i = 1; i< pos -1 ; i++)
                    {
                        temp = temp.next;
                    }

                    target =temp.next;

                    temp.next= temp.next.next;

                    target = null;


                    
            }
            System.gc();

            iCount--;
        
        }

    


}


class program1
{
    public static void main(String A [])
    {
        SinglyLL sobj;
        sobj = new SinglyLL();
        int iRet = 0;

        sobj.InsertFirst(11);
        sobj.InsertFirst(21);
        sobj.InsertFirst(51);

        sobj.Display();
        iRet = sobj.Count();
        System.out.println("Number of nodes are :"+iRet);

        sobj.InsertLast(101);
        sobj.InsertLast(121);
        sobj.InsertLast(151);

        sobj.Display();
        iRet = sobj.Count();
        System.out.println("Number of nodes are :"+iRet);

        sobj.InsertAtPos(105, 4);
        sobj.Display();
        iRet = sobj.Count();
        System.out.println("Number of nodes are :"+iRet); 

        sobj.DelelteAtPos( 4);
        sobj.Display();
        iRet = sobj.Count();
        System.out.println("Number of nodes are :"+iRet); 

        sobj.DelelteFirst();
        sobj.Display();
        iRet = sobj.Count();
        System.out.println("Number of nodes are :"+iRet);

        sobj.DelelteLast();
        sobj.Display();
        iRet = sobj.Count();
        System.out.println("Number of nodes are :"+iRet);   

    }
}
