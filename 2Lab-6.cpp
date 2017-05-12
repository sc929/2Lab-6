#include "stdafx.h"
#include <conio.h>
#include <iostream>

using namespace std;

class complex
{
public:
	double real;
	double im;

public:
	complex() { real = 0.0; im = 0.0; }

	complex(double real, double im)
	{
		this->real = real;
		this->im = im;
	}

    void print(ostream&)
    {
        cout << real << " + i*(" << im << ')' << endl;
    }

    friend ostream& operator << (ostream&, const complex&);

    complex add(complex ptr)
	{
        ptr.real = real + ptr.real;
        ptr.im = im + ptr.im;
	cout << "z + c = ";
        return ptr;
	}

    complex sub(complex ptr)
	{
        ptr.real = real - ptr.real;
        ptr.im = im - ptr.im;
	cout << "z - c = ";
        return ptr;
	}

    complex mult(int c)
	{
        complex ptr(0, 0);
        ptr.real = real * c;
        ptr.im = im * c;
	cout << "z*a = ";
        return ptr;
	}

    complex div(int c)
	{
        complex ptr(0, 0);
        ptr.real = real / c;
        ptr.im = im / c;
	cout << "z/a = ";
        return ptr;
	}
};

ostream & operator<<(ostream & ciout, complex &numb)
{
    numb.print(ciout);
    return ciout;
}

int main(void)
{
	double real, im;
	int a;

	cout << "   Complex number z = x + i*y" << endl << "x = ";
	cin >> real;
	cout << "y = ";
	cin >> im;

	cout << "z = ";
	complex complex_num(real, im);
    	cout << complex_num;

	cout << endl << "   '+' Complex number c = x + i*y" << endl << "x = ";
	cin >> real;
	cout << "y = ";
	cin >> im;
	cout << "c = ";
	complex ptr(real, y);
	ptr = complex_num.add(ptr);
    	cout << ptr;

	cout << endl << "   '-' Complex number c = x + i*y" << endl << "x = ";
	cin >> real;
	cout << "y = ";
	cin >> im;
	ptr.real = real;
	ptr.im = im;
	cout << "c = ";
    	cout << ptr;
	ptr = complex_num.sub(ptr);
    	cout << ptr;

	cout << endl << "   '*' z*a = x*a + i*(y*a)" << endl << "a = ";
	cin >> a;
	ptr = complex_num.mult(a);
    	cout << ptr;

	cout << endl << "   '/' z/a = x/a + i*(y/a)" << endl << "a = ";
	cin >> a;
	try
	{
		if (a == 0) throw a;
	}
	catch (int a)
	{
		cout << endl << "ERROR!!! You can't divide by zero" << endl;
		return 0;
	}
	ptr = complex_num.div(a);
    	cout << ptr;

	return 0;
}
