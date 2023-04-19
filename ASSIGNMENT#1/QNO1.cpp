#include<iostream>
using namespace std;
int* INPUT(int*& pntr_1, int& size) {
	cout << "ENTER SIZE=";
	cin >> size;
	if (size > 2) {
		pntr_1 = new int[size];
		cout << "ENTER " << size << " ELEMENTS." << endl;
		for (int i = 0; i < size; i++) {
			cin >> pntr_1[i];
		}
	}
	else cout << "SIZE SHOULD BE GREATER THAN 2." << endl;
	return pntr_1;
	delete[] pntr_1;
}
int* SECOND_LARGEST(int*& pntr_2, int& size) {
	int first_largest = 0,second_largest=0;
	if (pntr_2[0] < pntr_2[1])
	{
		first_largest = pntr_2[1];
		 second_largest = pntr_2[0];
	}
	else
	{
		first_largest = pntr_2[0];
		second_largest = pntr_2[1];
	}
	for (int i = 2; i < size; i++)
	{
		if(pntr_2[i] >first_largest)
		{
			second_largest = first_largest;
                	first_largest = pntr_2[i];
		}
		else if((pntr_2[i] >second_largest) && (pntr_2[i] != first_largest))
		{
			second_largest = pntr_2[i];
		}
	}
	//cout<<		second_largest<<endl;
	int  *second_value_pntr=&second_largest;
	
	cout<<"************************"<<endl<<"ANSWER="<<*second_value_pntr<<endl;
	return second_value_pntr;
	delete[] pntr_2;
}
int main() {
	int size = 0;
	int* pntr = INPUT(pntr, size);
	int* secondpntr = SECOND_LARGEST(pntr, size);
	
	return 0;

}