#include <iostream>
using namespace std;
#include "TASK6.h"
//operations for class TIME
void TIME::INPUT() {
	cout << "ENTER HOURS"; cin >> hours;
	cout << "ENTER MINUTES"; cin >> minutes;
	cout << "ENTER SECONDS"; cin >> seconds;
}
void TIME::DISPLAY() {
	cout << "***********************************" << endl;
	if ((hours > -1 && hours < 25) && (minutes > -1 && minutes < 61) && (seconds > -1 && seconds < 61) && n > 0) {
		cout << hours << ":" << minutes << ":" << seconds << endl;
	}
	else
		cout << "ERROR" << endl;
}
TIME::TIME() {
	hours = 1;
	minutes = 1;
	seconds = 1;
	n = 1;
}
TIME::TIME(int hours, int minutes, int seconds) {
	this->hours = hours;
	this->minutes = minutes;
	this->seconds = seconds;
}
int TIME::operator++() {//work pre increment
	++hours;
	++minutes;
	++seconds;
	return hours, minutes, seconds;
}
int TIME::operator++(int) {//work post increment
	hours++;
	minutes++;
	seconds++;
	return hours, minutes, seconds;
}
int TIME::operator--() {//work pre decrement
	--hours;
	--minutes;
	--seconds;
	return hours, minutes, seconds;
}
int TIME::operator--(int) {//work post decrement		 
	hours--;
	minutes--;
	seconds--;
	return hours, minutes, seconds;
}
//task 1 operation ends here
//task 2 operations starts from here
void TIME::INPUT_FOR_FLOAT() {
	cout << "ENTER FLAOT NUMBER"; cin >> n;
	hours = minutes = seconds = n;
}
void TIME::DISPLAY_PRODUCT() {
	cout << "***********************************" << endl;
	cout << hours << ":" << minutes << ":" << seconds << endl;

}
TIME TIME::operator-(TIME obj) {
	TIME TMP;
	TMP.hours = hours - obj.hours;
	TMP.minutes = minutes - obj.minutes;
	TMP.seconds = seconds - obj.seconds;
	return TMP;
}
TIME TIME::operator*(TIME obj) {
	TIME TMP;
	TMP.hours = hours * obj.hours;
	TMP.minutes = minutes * obj.minutes;
	TMP.seconds = seconds * obj.seconds;
	return TMP;
}
//task 2 operations ends here
//opeartions for class FACULTY 
//task3 start from here

//task 4 ended,task 5 start from here
void Matrix::allocSpace() // Element allocataion of matrix initialization
{
	matrix = new float* [r];
	for (int i = 0; i < r; ++i) {
		matrix[i] = new float[c];
	}
}
Matrix::Matrix(int rows, int cols) : r(rows), c(cols)
{
	allocSpace();
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			matrix[i][j] = 0;
		}
	}
}
Matrix::Matrix() : r(1), c(1)
{
	allocSpace();
	matrix[0][0] = 0;
}
Matrix::~Matrix()//Destructor
{
	for (int i = 0; i < r; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;
}
Matrix::Matrix(const Matrix& m) : r(m.r), c(m.c) //Copy 
{
	allocSpace();
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			matrix[i][j] = m.matrix[i][j];
		}
	}
}
ostream& operator<<(ostream& os, const Matrix& m)// cout the elements 
{
	for (int i = 0; i < m.r; ++i) {
		os << m.matrix[i][0];
		for (int j = 1; j < m.c; ++j) {
			os << " " << m.matrix[i][j];
		}
		os << endl;
	}
	return os;
}
istream& operator>>(istream& is, Matrix& m) //cin the elements 
{
	for (int i = 0; i < m.r; ++i) {
		for (int j = 0; j < m.c; ++j) {
			is >> m.matrix[i][j];
		}
	}
	return is;
}
Matrix& Matrix::operator=(const Matrix& m)// assign the value situation for object
{
	if (this == &m) {
		return *this;
	}
	if (r != m.r || c != m.c) {
		for (int i = 0; i < r; ++i) {
			delete[] matrix[i];
		}
		delete[] matrix;
		r = m.r;
		c = m.c;
		allocSpace();
	}
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			matrix[i][j] = m.matrix[i][j];
		}
	}
	return *this;
}
Matrix Matrix::operator+=(Matrix m)
{
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			matrix[i][j] += m.matrix[i][j];
		}
	}
	return *this;
}
Matrix Matrix::operator-=(Matrix m)
{
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			matrix[i][j] -= m.matrix[i][j];
		}
	}
	return *this;
}
Matrix operator+(const Matrix& m1, const Matrix& m2)// add like temp  = m1   temp = temp + m2 faster way
{
	Matrix temp(m1);
	return (temp += m2);
}
Matrix operator-(const Matrix& m1, const Matrix& m2)
{
	Matrix temp(m1);
	return (temp -= m2);
}

