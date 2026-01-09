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
void Display(T Value ,int Size)
{
    int iCnt = 0;
    for(iCnt = 1; iCnt <= Size ; iCnt++ )
    {
        cout<<Value<<"\t";
    }
    cout<<"\n";
}


/////////////////////////////////////////////////////////////////////////////////
//
//      ENTRY POINT FUNCTION
//
/////////////////////////////////////////////////////////////////////////////////

int main()
{
    

    Display('M' ,3);
    Display(11 ,3);
    Display(3 ,6);

    
    return 0;
}
