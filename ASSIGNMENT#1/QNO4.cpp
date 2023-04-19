#include <iostream>
using namespace std;
int** ALLOCATE_MEMORY(int& rows, int& cols) {
	int** matrix = new int* [rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[cols];
	}
	return matrix;
}
int** INPUT_ARRAY(int**& matrix_2, int& rows, int& cols) {//chances in matrix_2 also make change in **input,&rows+&cols also make changes in rows and cols of main. 
	cout << "ENTER DATA." << endl;
	for (int r = 0; r < rows; r++) {/*loop to enter data in 2d array of size r*c */
		for (int c = 0; c < cols; c++) {
			cin >> matrix_2[r][c];
		}
	}
	return matrix_2;//return back to **input in main
}
int* MINCOL_WISE(int**& matrix_3, int& rows, int& cols) {
	int* pntr = new int[cols];//create a dynnamic 1 d array of size=cols of 2d array
	int max = 100;
	for (int i = 0; i < rows; i++) {
		max = 10000;
		for (int j = 0; j < cols; j++) {
			if (matrix_3[j][i] <= max) {
				max = matrix_3[j][i];
				pntr[i] = max;
			}
		}
	}
	return pntr;
	delete[] pntr;
}
int* output(int*& pntr, int& cols) {
	cout << "**************************" << endl << "SMALL ELEMENTS IN EACH COLUMN:";
	cout << "{";
	for (int i = 0; i < cols; i++) {
		cout << pntr[i] << ",";
	}
	cout << "}";
	return pntr;
	delete pntr;
}
int main() {
	int row = 0, col = 0;
	cout << "ENTER ROWS="; cin >> row;
	cout << "ENTER COLUMNS= "; cin >> col;
	int** size = ALLOCATE_MEMORY(row, col);
	int** input = INPUT_ARRAY(size, row, col);
	int* sorting = MINCOL_WISE(size, row, col);
	int* OUTPUT = output(sorting, col);
	return 0;
}