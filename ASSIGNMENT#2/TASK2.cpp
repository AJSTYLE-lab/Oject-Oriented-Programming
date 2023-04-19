#include <iostream>

using namespace std;
void circular_shift(int &A,int &B,int &C){
    int tmp_A=A;
    int tmp_C=B;
    int *pntra=&A;
    int *pntrb=&B;
    int *pntrc=&C;
    pntrc=&A;
    pntra=&B;
    pntrb=&C;
    cout<<"A="<<*pntrb<<","<<"B="<<*pntrc<<","<<"C="<<*pntra<<endl;
A=C;
B=tmp_A;
C=tmp_C;

    }
int main()
{
int a=0,b=0,c=0;
cout<<"A=";cin>>a;
cout<<"B=";cin>>b;
cout<<"C=";cin>>c;
char option;
do{
circular_shift(a,b,c);
cout<<"AGAIN CIRCULAR SHIFT? PRESS Y.";
cin>>option;
}while(option=='y'||option=='Y');
    return 0;
}