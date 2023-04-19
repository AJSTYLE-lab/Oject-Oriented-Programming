#include<iostream>
using namespace std;
int* INPUT(int*& p_1, int& size) {
	cout << "ENTER SIZE=";
	cin >> size;
	p_1 = new int[size];
	cout << "ENTER " << size << " ELEMENT." << endl;
	for (int i = 0; i < size; i++) {
		cin >> p_1[i];
	}
	return p_1;
	delete[] p_1;
}
int* SHRINK(int*& p_2, int& old_size, int& n_size) {
	cout << "ENTER NEW SIZE=";
	cin >> n_size;
	int* newpntr = new int[n_size];
	if (n_size < old_size) {
		for (int i = 0; i < old_size; i++) {
			newpntr[i] = p_2[i];//copy into new d array
		}

	}
	else cout << "INVALID INPUT" << endl;
	return newpntr;
	delete[] newpntr;
	delete[] p_2;
}
int main() {
	int size = 0, new_size = 0;
	int* pntr = INPUT(pntr, size);
	int* output = SHRINK(pntr, size, new_size);
	cout << "***********************OUTPUT***********************" << endl;
	for (int i = 0; i < new_size; i++) {
		cout << output[i] << ",";
	}
	delete[] output;
	delete[] pntr;
	return 0;

}