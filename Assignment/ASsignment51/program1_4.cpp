#include<iostream>
using namespace std;


//////////////////////////////////////////////////////////////////////////////
//
//      function name : SearchFirst
//      Description   : used to search last occurence of any number 
//      Input         : T *arr , int , T no
//      Output        : int
//      Auther name   : Sakshi Laxman Kachate.
//      Date          : 09/01/2026
//
//////////////////////////////////////////////////////////////////////////////

template <class T>
int SearchLast(T *arr ,int iSize,T ino)
{
    int iCnt = 0;
    int ilastOcc = 0;
    for(iCnt = iSize-1; iCnt >= 0; iCnt-- )
    {
        if(arr[iCnt]== ino)
        {
        
           return iCnt; 
        }
        
    }

    return -1;
}



/////////////////////////////////////////////////////////////////////////////////
//
//      ENTRY POINT FUNCTION
//
/////////////////////////////////////////////////////////////////////////////////

int main()
{
    int arr[] = {10,20,30,10,30,40,10,40,10};
    int iRet = SearchLast(arr,9,40);
    cout<<iRet;
    return 0;

    
}
