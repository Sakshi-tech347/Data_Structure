#include<iostream>
using namespace std;


//////////////////////////////////////////////////////////////////////////////
//
//      function name : Multiply
//      Description   : multiply two numbers
//      Input         : T , T
//      Output        : T
//      Auther name   : Sakshi Laxman Kachate.
//      Date          : 10/01/2026
//
//////////////////////////////////////////////////////////////////////////////
template<class T>
T Multiply(T No1 , T No2)
{
    T Ans;
    Ans = No1 * No2;
    return Ans;
}

/////////////////////////////////////////////////////////////////////////////////
//
//      ENTRY POINT FUNCTION
//
/////////////////////////////////////////////////////////////////////////////////


int main()
{
    int iRet = 0;
    iRet = Multiply(10,20);

    cout<<iRet<<"\n";
    
    float fRet =Multiply(10.0f,20.0f);
    cout<<iRet<<"\n";
    return 0;
}
