#include<iostream>
using namespace std;
int* INPUT(int*& p_1, int& size) {
	cout << "ENTER SIZE=";
	cin >> size;
	p_1 = new int[size];
	cout << "ENTER " << size << " ELEMENTS." << endl;
	for (int i = 0; i < size; i++) {
		cin >> p_1[i];
	}
	return p_1;
	delete[] p_1;
}
int* ASCENDNIG(int*& p_2, int& size) {
int TEMP=0;
 for(int i=0;i<size;i++)
	{		
		for(int j=i+1;j<size;j++)
		{
			if(p_2[i]>p_2[j])
			{
				TEMP  =p_2[i];
				p_2[i]=p_2[j];
				p_2[j]=TEMP;
			}
		}
	}
	cout<<"OUTPUT."<<endl;
	for(int i=0;i<size;i++)
		cout<<p_2[i]<<",";
return p_2;
delete p_2;
}
int main() {
	int size = 0;
	int* pntr = NULL;
	pntr = INPUT(pntr, size);
	int* ascending_pntr = ASCENDNIG(pntr, size);
	delete pntr, ascending_pntr;
	return 0;
}