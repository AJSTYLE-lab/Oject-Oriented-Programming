#include<iostream>
using namespace std;
#include"TASK6.h"
void QUESTION_1() {
	TIME T1, f_n;
	cout << "DEFAULT CONSTRUCTOR." << endl;
	T1.DISPLAY();
	cout << "***************************" << endl;
	T1.INPUT();
	cout << "***************************" << endl;
	T1++;
	cout << "AFETR POST INCREMENT=" << endl;
	T1.DISPLAY();
	--T1;
	cout << "AFETR PRE DCREMENT=" << endl;
	T1.DISPLAY();
	T1--;
	cout << "AFETR POST DECREMENT=" << endl;
	T1.DISPLAY();
	++T1;
	cout << "AFETR PRE INCREMENT=" << endl;
	T1.DISPLAY();
}
void QUESTION_2() {
	TIME T5, f_n;
	//cout<<"DEFAULT CONSTRUCTOR."<<endl;
//	T1.DISPLAY();
	cout << "***************************" << endl;
	T5.INPUT();
	cout << "***************************" << endl;
	TIME T6, SUB;
	T6.INPUT();
	SUB = T6 - T5;
	SUB.DISPLAY();
	f_n.INPUT_FOR_FLOAT();
	f_n = f_n * SUB;
	f_n.DISPLAY_PRODUCT();
}
void QUESTION_3() {
 Faculty tt;
    cout << "Enter the details:" << endl;
    cin >> tt;
    cout << endl << "The details are: " << endl << tt;
        }
void QUESTION_4() {
    Faculty f1, f2;
	cout << "ENTER FOR OBJECT 1" << endl;
	cin>>f1;
	cout << "************************************" << endl;
	cout << "ENTER FOR OBJECT 2" << endl;
	cin>>f2;
	cout << "************************************" << endl;
	f1 = f2;
	cout << "************************************" << endl;
	cout << " DEEP COPY IN OBJECT F1=" << endl;
	cout<<f1;
}
void QUESTION_5() {
	int i, j = 0;
	cout << "SIZE FOR A & B (rows , column)=" << endl;
	cin >> i >> j;
	Matrix A(i, j);
	cout << "Enter the elements of Matrix 1 : " << endl;
	cin >> A;
	Matrix B(i, j);
	cout << "Enter the elements of Matrix 2 : " << endl;
	cin >> B;
	Matrix C = A + B;
	Matrix D = A - B;
	cout << "The additon of two matrices is : " << endl << C;
	cout << "The subtraction  of two matrices is : " << endl << D;

}
int PRESENT_MENU(int& option) {
	cout << "1->QUESTION_1" << endl << "2->QUESTION_2" << endl << "3->QUESTION_3" << endl << "4->QUESTION_4" << endl
		<< "5->QUESTON_5" << endl;
	cout << "YOUR SELECTION=";
	cin >> option;
	return option;
}
int main() {
	int selection_opiton = 0, option = 0;
	do {
		selection_opiton = PRESENT_MENU(option);
		if (selection_opiton == 1) {
			cout << "**************************************************" << endl;
			QUESTION_1();
			cout << "**************************************************" << endl;
		}
		if (selection_opiton == 2) {
			cout << "**************************************************" << endl;
			QUESTION_2();
			cout << "**************************************************" << endl;
		}
		if (selection_opiton == 3) {
			cout << "**************************************************" << endl;
			QUESTION_3();
			cout << "**************************************************" << endl;
		}
		if (selection_opiton == 4) {
			cout << "**************************************************" << endl;
			QUESTION_4();
			cout << "**************************************************" << endl;
		}
		if (selection_opiton == 5) {
			cout << "**************************************************" << endl;
			QUESTION_5();
			cout << "**************************************************" << endl;
		}

	} while (option == 1 || option == 2 || option == 3 || option == 4 || option == 5);
	return 0;
}
