#include<iostream>
using namespace std;
char* INPUT(char* &STR,int &size){
    cout<<"ENTER STRING."<<endl;
    for(int i=0;i<size;i++){
        cin>>STR[i];
    }
    return STR;
    delete[] STR;
}
char* OUTPUT(char* &INPUT,int SIZE){
int counta=0,counte=0,counti=0,counto=0,countu=0;
int sum=0;
int *pntr_sum=&sum;
    for(int i=0;i<SIZE;i++){
        if(INPUT[i]=='a'||INPUT[i]=='A'){
            counta++;
        }
        if(INPUT[i]=='e'||INPUT[i]=='E'){
            counte++;
        }
            if(INPUT[i]=='O'||INPUT[i]=='o'){
            counto++;
        }
            if(INPUT[i]=='i'||INPUT[i]=='I'){
            counti++;
        }
            if(INPUT[i]=='u'||INPUT[i]=='U'){
            countu++;
        }
    }
    char* VOWEL_ARRAY=new char[5];
    char vowel_static[5]={'a','e','i','o','u'};
    int*pntrarray=new int [5];
    int arrayvowel[5]={counta,counte,counti,counto,countu};
    int DESC_FOR_PNTR=0;//use for the counti,a,e,o,use
    int DESC_FOR_VOWEL=0;//use for the counti,a,e,o,use
    for(int i=0;i<5;i++){
        VOWEL_ARRAY[i]=vowel_static[i];//copying in array.
       pntrarray[i]=arrayvowel[i];
    }
    for (int i= 0; i < 5; ++i)   //  'for' loop is used for sorting the numbers in descending order
    {
        for (int j = i + 1; j < 5; ++j)
        {
            if (pntrarray[i] < pntrarray[j])
            {
                DESC_FOR_PNTR = pntrarray[i];
                pntrarray[i] = arrayvowel[j];
                pntrarray[j] = DESC_FOR_PNTR;
            }
        }
    }
    //
        for (int i= 0; i < 5; ++i)   //  'for' loop is used for sorting the numbers in descending order
    {
        for (int j = i + 1; j < 5; ++j)
        {
            if (pntrarray[i] < pntrarray[j])
            {
               DESC_FOR_VOWEL=VOWEL_ARRAY[i];
               VOWEL_ARRAY[i]=vowel_static[j];
                 VOWEL_ARRAY[i]=DESC_FOR_VOWEL;
            }
        }
    }
    
    cout<<"SORTING IN DESCENDING ORDER."<<endl;
    for (int i = 0; i < 5; ++i)
    {
        cout<<VOWEL_ARRAY[i]<<"="<<pntrarray[i]<<endl;//showing output
        sum+=pntrarray[i];
    }
    int *pntrcon=&SIZE;
    cout<<"TOTAL VOWEL ARE="<<*pntr_sum<<endl;
    SIZE=   SIZE - sum ;
    cout<<"TOTAL CONSONANT ARE="<<*pntrcon<<endl;
    
    return INPUT;
    delete[] INPUT,VOWEL_ARRAY,pntrarray;
}
int main(){
    int size=0;
    cout<<"SIZE=";
    cin>>size;
    char *str=new char[size];
    char* input=INPUT(str,size);
    char* pntr_O=OUTPUT(str,size);
    delete str,input,pntr_O;    
    return 0;
}