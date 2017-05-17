#include "stdafx.h"
#include <conio.h>
#include <iostream>

using namespace std;

class complex
{
public:
	double real;
	double im;

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

	complex add(complex res)
	{
		res.real = real + res.real;
		res.im = im + res.im;
		return res;
	}

	complex sub(complex res)
	{
		res.real = real - res.real;
		res.im = im - res.im;
		return res;
	}

	complex mult(int c)
	{
		complex res(0, 0);
		res.real = real * c;
		res.im = im * c;
		return res;
	}

	complex div(int c)
	{
		complex res(0, 0);
		try
		{
			if (c == 0) throw c;
		}
		catch (int c)
		{
			cout << endl << "ERROR!!! You can't divide by zero" << endl;
			return res;
		}
		res.real = real / c;
		res.im = im / c;
		return res;
	}
};

ostream & operator<<(ostream & ciout, complex &numb)
{
	numb.print(ciout);
	return ciout;
}

int main(void)
{
	complex result(0, 0);

	cout << "z = ";
	complex complex_num(13, 7);
	cout << complex_num;

	cout << "c = ";
	complex plus(4, 9);
	cout << plus;
	cout << "z + c = ";
	result = complex_num.add(plus);
	cout << result;

	cout << "d = ";
	complex minus(3, 16);
	cout << minus;
	cout << "z - d = ";
	result = complex_num.sub(minus);
	cout << result;

	cout << "z*5 = ";
	result = complex_num.mult(5);
	cout << result;

	cout << "z/3 = ";
	result = complex_num.div(3);
	cout << result;
	_getch();
	return 0;
}
