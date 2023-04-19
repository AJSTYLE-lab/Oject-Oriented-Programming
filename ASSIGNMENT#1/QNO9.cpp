#include <iostream>
using namespace std;

int main()
{
    long int value1=200000,value2;//1
    cout<<"VLAUE OF VALUE1 OBJECT BY VARIABLE ="<<value1<<endl;//cout the value of varaible value1 of type long
    long int *longptr=&value1;// points towdars the value1 
    cout<<"THE VALUE OF OBJECT POINTED TO BY *longPtr="<< *longptr<<endl;
    value2=*longptr;
    cout<<"VALUE 2="<<value2<<endl;
    cout<<"ADDRESS OF VALUE1="<<&value1<<endl;
    cout<<"ADDRESS OF longptr="<<longptr<<endl;
    cout<<"YES THE ADDRESS ARE SAME.";
    return 0;
}