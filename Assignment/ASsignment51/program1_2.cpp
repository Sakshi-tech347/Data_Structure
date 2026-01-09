#include<iostream>
using namespace std;


//////////////////////////////////////////////////////////////////////////////
//
//      function name : Display
//      Description   : used to Display value
//      Input         : T(Generic Value),int
//      Output        : nothing
//      Auther name   : Sakshi Laxman Kachate.
//      Date          : 09/01/2026
//
//////////////////////////////////////////////////////////////////////////////

template <class T>
int Frequency(T *arr ,int iSize,T ino)
{
    int iCnt = 0;
    int iFrequency = 0;
    for(iCnt = 0; iCnt <= iSize ; iCnt++ )
    {
        if(arr[iCnt]== ino)
        {
            iFrequency++;
        }
        
    }
    return iFrequency;
}


/////////////////////////////////////////////////////////////////////////////////
//
//      ENTRY POINT FUNCTION
//
/////////////////////////////////////////////////////////////////////////////////

int main()
{
    int arr[] = {10,20,30,10,30,40,10,40,10};
    int iRet = Frequency(arr,9,10);
    cout<<iRet;
    return 0;

    
}
