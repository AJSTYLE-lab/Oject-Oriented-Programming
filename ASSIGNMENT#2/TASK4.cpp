
#include <iostream>

using namespace std;

int main()
{int size=0;
cout<<"SIZE=";
cin>>size;
int *pntr=new int [size];
cout<<"ENTER ELEMENTS=";
for(int i=0;i<size;i++){
    cin>>pntr[i];
}  
cout<<"ARRAY A\t\t\t"<<"HISTROGRAM"<<endl;
for(int i=0;i<size;i++){
    cout<<pntr[i]<<"\t\t\t ";
    for(int j=0;j<pntr[i]*2;j++)
    cout<<"*";
    cout<<endl;
}
    return 0;
}