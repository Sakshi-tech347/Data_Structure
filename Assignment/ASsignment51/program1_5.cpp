#include<iostream>
using namespace std;

 

//////////////////////////////////////////////////////////////////////////////
//
//      function name : Reverse
//      Description   : used to Display in reverse order
//      Input         : T *arr , int 
//      Output        :     nothing
//      Auther name   : Sakshi Laxman Kachate.
//      Date          : 09/01/2026
//
//////////////////////////////////////////////////////////////////////////////



template <class T>
void Reverse(T *arr ,int iSize)
{
    int i = 0;
    for(i = iSize-1; i >=0 ; i-- )
    {
       
        
            cout<<arr[i]<<"\t";
         
        
    }


}




/////////////////////////////////////////////////////////////////////////////////
//
//      ENTRY POINT FUNCTION
//
/////////////////////////////////////////////////////////////////////////////////

int main()
{
    int arr[] = {10,20,30,10,30,40,10,40,10};
    Reverse(arr,9);

    
    return 0;

    
}
