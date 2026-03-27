
class node:
    def __init__(self,value):
        self.Data = value
        self.next = None

class SinglyLL:
    
    def __init__(self):
        self.first = None
        self.iCount = 0
    
    
    def InsertFirst(self,no):
        newn = node(no)

      
        if(self.first == None):
            self.first = newn
      
        else:
            newn.next= self.first
            self.first = newn
        
        self.iCount = self.iCount + 1

    
    def InsertLast(self,no):
        newn = node(no)

        
        if(self.first == None):
            self.first = newn
        
        else:
            temp = self.first

            while(temp.next != None):
                temp = temp.next
            temp.next = newn
        
        self.iCount = self.iCount + 1

    
    def InsertAtPos(self,no,pos):
        
        if(pos < 1 or pos > (self.iCount+1)):
            print("Invalid Position ")
            return
        if(pos == 1):
            self.InsertFirst(no)
            return
        elif(pos == self.iCount+1):
            self.InsertLast(no)
            return
        else:
            newn = node(no)
            temp = self.first

            for i in range(1,pos-1):
                temp = temp.next

            newn.next = temp.next
            temp.next = newn
            
            self.iCount = self.iCount + 1
            
        


  
    def DeleteFirst(self):
        if(self.first == None):
            return
        
        temp = self.first
        self.first = self.first.next

        del temp 

        self.iCount = self.iCount -1
    
    def DeleteLast(self):
        
        if(self.first == None):
            return
      
        if(self.first.next == None):
            del self.first
            self.first = None
            self.iCount = 0
    
        else:
            temp = self.first

            while(temp.next.next != None):
                temp = temp.next
        
            del temp.next        
            temp.next= None
            self.iCount = self.iCount -1

    def DeleteAtPos(self,pos):
        
        if(pos < 1 or pos > (self.iCount)):
            print("Invalid Position ")
            return
        if(pos == 1):
            self.DeleteFirst()
            return
        elif(pos == self.iCount):
            self.DeleteLast()
            return
        else:
            temp = self.first

            for i in range(1,pos-1):
                temp = temp.next

            temp.next = temp.next.next
            
            self.iCount = self.iCount - 1
            
        
    
    
    def Count(self):
        return self.iCount 
  
    def Display(self):
        temp = self.first

        
        while temp is not None:
            print("| ",temp.Data,"|->",end=" ")
            temp = temp.next
        print(None)
        
def main():
    sobj = SinglyLL()

    sobj.InsertFirst(101) 
    sobj.InsertFirst(51)
    sobj.InsertFirst(21)
    sobj.InsertFirst(11)

    print("elements of LinkedList are :")
    sobj.Display()
    print("Number of elments in linked list are ",sobj.Count())

    sobj.InsertLast(111)
    sobj.InsertLast(121)

    print("elements of LinkedList are :")
    sobj.Display()
    print("Number of elments in linked list are ",sobj.Count())


    sobj.InsertAtPos(75,4)
    print("elements of LinkedList are :")
    sobj.Display()
    print("Number of elments in linked list are ",sobj.Count())


    sobj.DeleteFirst()
    print("elements of LinkedList are :")
    sobj.Display()
    print("Number of elments in linked list are ",sobj.Count())

     
    sobj.DeleteLast()
    print("elements of LinkedList are :")
    sobj.Display()
    print("Number of elments in linked list are ",sobj.Count())

    sobj.DeleteAtPos(3)
    print("elements of LinkedList are :")
    sobj.Display()
    print("Number of elments in linked list are ",sobj.Count())

if __name__ == "__main__":
    main()

