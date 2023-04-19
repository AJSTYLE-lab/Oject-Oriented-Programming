#pragma once
#include<iostream>
using namespace std;
class TIME {
	float hours, minutes, seconds;
	float n;
public:
	TIME();
	TIME(int hours, int minutes, int seconds);
	int operator++();//work pre increment
	int operator++(int);//work post increment
	int operator--();//work pre decrement
	int operator--(int);//work post increment
	TIME operator-(TIME obj);
	TIME operator*(TIME obj);
	void DISPLAY_PRODUCT();
	void DISPLAY();
	void INPUT();
	void INPUT_FOR_FLOAT();
};
class Faculty
{
    private:
    char FN[30],FC[30],D[30],Sal[30];
    char E[30];
    char *faculty_name,*faculty_code,*salary, *e;
    string *department;
    int counter1,counter2,counter3,counter4,counter5;
    public:
    Faculty()
    {
        counter1=0;
        counter2=0;
        counter3=0;
        counter4=0;
        counter5=0;
        faculty_name=NULL;
        faculty_code=NULL;
        department=NULL;
        salary=NULL;
        e=NULL;
    }
    friend istream & operator >> (istream & IN, Faculty & obj1)
    {
        int i=0,j=0,k=0,l=0;
        cout<<endl<<"Enter the faculty experience: ";
        IN.getline(obj1.E,30);
        while(obj1.E[i]!='\0')
        {
            i++;
            obj1.counter5++;
        }
        
        obj1.e = new char [obj1.counter5];
        
        for(int x=0;x<obj1.counter5;x++)
        {
            obj1.e[x]=obj1.E[x];
        }
        cout<< "Enter the faculty code:"<<endl;
        IN.getline(obj1.FC,30);
        
        while(obj1.FC[j]!='\0')
        {
            j++;
            obj1.counter2++;
        }
        
        obj1.faculty_code = new char [obj1.counter2];
        
        for(int x=0;x<obj1.counter2;x++)
        {
            obj1.faculty_code[x]=obj1.FC[x];
        }
        cout << endl << "Enter the salary of the faculty member: " << endl;
        
        IN.getline(obj1.Sal,30);
        
        while(obj1.Sal[l]!='\0')
        {
            l++;
            obj1.counter4++;
        }
        
        obj1.salary = new char [obj1.counter4];
        
        for(int x=0;x<obj1.counter4;x++)
        {
            obj1.salary[x]=obj1.Sal[x];
        }
        cout<< "Enter the faculty member name: ";
        IN.getline(obj1.FN,30);
        while(obj1.FN[i]!='\0')
        {
            i++;
            obj1.counter1++;
        }
        obj1.faculty_name = new char [obj1.counter1];
        for(int x=0;x<obj1.counter1;x++)
        {
            obj1.faculty_name[x]=obj1.FN[x];
            
        }
        
        return IN;
    
        
    }
    friend ostream & operator << (ostream & OUT, const Faculty & obj2)
    {
        OUT << "The faculty member name: " << obj2.faculty_name << endl;
        OUT << "The faculty code of this faculty member is: " << obj2.faculty_code << endl;
        OUT << "The department_experience of this faculty member is: " << obj2.department << " years " << endl;
        OUT << "The salary of this faculty member is: " << obj2.salary << endl;
        return OUT;
    }
    Faculty& operator= (const Faculty& obj) {  
		this->faculty_name=obj.faculty_name;
		this->faculty_code=obj.faculty_code;
		this->department=obj.department;
		this->salary=obj.salary;
		this->e=obj.e;
	 	return *this;
    }
	~Faculty(){
	  delete faculty_name,faculty_code,salary,e,department;
	}
};
class Matrix
{
	float** matrix;
	int r = 0;
	int c = 0;
public:
	~Matrix();
	Matrix(int, int);
	Matrix();
	Matrix(const Matrix&);
	void allocSpace();
	Matrix& operator=(const Matrix&);
	Matrix operator+=(Matrix m);// incremental addition 
	Matrix operator-=(Matrix m);//decremental subtraction 
	friend ostream& operator<<(ostream&, const Matrix&);// for input 
	friend istream& operator>>(istream&, Matrix&);// for output 
};
Matrix operator+(const Matrix&, const Matrix&);// addition of two 
Matrix operator-(const Matrix&, const Matrix&);//subtraction of two

