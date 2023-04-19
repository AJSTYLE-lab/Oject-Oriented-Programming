#include <iostream>
using namespace std;
char* ALPHABET_ARRAY_MAKING(char*& PNTRALPHA) {
    PNTRALPHA = new char[26];
    char alphabet[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

    for (int i = 0; i < 26; i++) {
        PNTRALPHA[i] = alphabet[i];
    }
    return PNTRALPHA;
    delete[] PNTRALPHA;
}
char* INPUT_ARRAY_A(char*& pntra, int& sizea) {
    cout << "A:ENTER NUMBER OF LETTERS=";
    cin >> sizea;
    pntra = new char[sizea];
    cout << "ENTER LETTERS FOR A=";
    for (int i = 0; i < sizea; i++) {
        cin >> pntra[i];
    }
    return pntra;
    delete[] pntra;
}
char* INPUT_ARRAY_B(char*& pntrb, int& sizeb) {
    cout << "B:ENTER NUMBER OF LETTERS=";
    cin >> sizeb;
    pntrb = new char[sizeb];
    cout << "ENTER LETTERS FOR B=";
    for (int i = 0; i < sizeb; i++) {
        cin >> pntrb[i];
    }
    return pntrb;
    delete[] pntrb;
}
char* A_OR_B(char*& A, char*& B, int &S_A, int &S_B) {
    int i,j,check=0;
    cout<<"A UNION B={";
   for(i=0;i<S_A;i++)
  {
    cout<<A[i]<<" ";
  }
    for(j=0;j<S_B;j++)
  {
    check=0;
    for(i=0;i<S_A;i++)
    {
      if(A[i]==B[j])
      {
        check=1;
        break;
      }
    }
    if(check!=1)
    {
      cout<<B[j]<<" ";
    }
    
  }
  cout<<"\b}"<<endl;
    return A;
    delete A,B;
}
char* A_AND_B(char*& PTRA, char*& PTRB, int &size_a, int &size_b) {
if (size_a >=size_b) {
        cout << "A INTERSECTION B={";
        for (int i = 0; i < size_a; i++)
            for (int j = 0; j <= size_b; j++) {
                if (PTRA[i] == PTRB[j]) {
                    cout << PTRA[i] << ",";
                }
            }
        cout << "\b}";
    }
    if (size_a < size_b) {
        cout << "A INTERSECTION B={";
        for (int i = 0; i < size_b; i++)
            for (int j = 0; j <= size_a; j++) {
                if (PTRA[i] == PTRB[j]) {
                    cout << PTRA[i] << " ";
                }
            }
        cout << "\b}";
    }
   cout<<endl;
    return PTRA;
    delete PTRA,PTRB;
}
char* A_COMPLEMENT(char*& U,char*& A, int &S_A){
    char a='>';
    char *pntr=&a;
         for(int i=0;i<26;i++)
             for(int j=0;j<S_A;j++){
                 if(U[i]==A[j]){
                     U[i]=*pntr;
                 }
}
cout<<"U-A={";
for(int i=0;i<26;i++){
    if(U[i]!=*pntr){
    cout<<U[i]<<",";
    }
}                 
cout<<"}"<<endl;
         return U;
         delete[]U,A;
}
char* B_COMPLEMENT(char*& U,char*& B, int &S_B){
    char a='>';
    char *pntr=&a;
         for(int i=0;i<26;i++)
             for(int j=0;j<S_B;j++){
                 if(U[i]==B[j]){
                     U[i]=*pntr;
                 }
}
cout<<"U-B={";
for(int i=0;i<26;i++){
    if(U[i]!=*pntr){
    cout<<U[i]<<",";
    }
}                 
cout<<"}"<<endl;
         return U;
         delete[]U,B;
}
char* U_COMPLEMENT_A_UNION_B(char *&U,char*&B,int S_B,char* &A,int S_A){
 char *pntrAUB=new char[S_A+S_B];
 int i,j,check=0;
   for(i=0;i<S_A;i++)
  {
      pntrAUB[i]=A[i];
  }
    for(j=0;j<S_B;j++)
  {
    check=0;
    for(i=0;i<S_A;i++)
    {
      if(A[i]==B[j])
      {
        check=1;
        break;
      }
    }
    if(check!=1)
    {
        pntrAUB[j]=B[j];
    }
    
  }
  //
    char a='>';
    char *pntr=&a;
         for(int i=0;i<26;i++)
             for(int j=0;j<S_B+S_A;j++){
                 if(U[i]==pntrAUB[j]){
                     U[i]=*pntr;
                 }
}
cout<<"U-(AUB)={";
for(int i=0;i<26;i++){
    if(U[i]!=*pntr){
    cout<<U[i]<<",";
    }
}                 
cout<<"}"<<endl;
  
  return U;
  delete[]U,A,B,pntrAUB;
}
int main()
{
    char* pntralphabet = ALPHABET_ARRAY_MAKING(pntralphabet);
    int sizea = 0, sizeb = 0;
    char* pntra = INPUT_ARRAY_A(pntra, sizea);
    char* pntrb = INPUT_ARRAY_B(pntrb, sizeb);
    cout<<"*******************************"<<endl;
    char* pntra_intrsection_b = A_AND_B(pntra, pntrb, sizea, sizeb);
    cout<<"*******************************"<<endl;
    char* pntraUb = A_OR_B(pntra, pntrb, sizea, sizeb);
    cout<<"*******************************"<<endl;
    char* u_minus_a=A_COMPLEMENT(pntralphabet,pntra,  sizea);
    cout<<"*******************************"<<endl;
    char* u_minus_a_union_b=U_COMPLEMENT_A_UNION_B(pntralphabet,pntrb,sizeb,pntra,sizea);
    cout<<"*******************************"<<endl;
    pntralphabet = ALPHABET_ARRAY_MAKING(pntralphabet);
    char* u_minus_b=B_COMPLEMENT(pntralphabet,pntrb,  sizeb);
    cout<<"*******************************"<<endl;
    delete pntralphabet,u_minus_a_union_b,pntra,u_minus_a,u_minus_b, pntrb,pntraUb,pntra_intrsection_b;
    return 0;
}
