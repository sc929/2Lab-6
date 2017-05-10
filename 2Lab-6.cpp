#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;

class complex
{
public:
	double x;
	double y;

public:
	complex() { x = 0; y = 0; }

	complex(double x, double y)
	{
		this->x = x;
		this->y = y;
		print(x, y);
	}

	void print(double x, double y)
	{
		cout << x;
		if (y >= 0) cout << " + " << y << "i" << endl;
		else cout << " - " << y*(-1) << "i" << endl;
	}

	void add(complex ptr)
	{
		double a, b;
		a = x + ptr.x;
		b = y + ptr.y;
		cout << "z + c = ";
		print(a, b);
	}

	void sub(complex ptr)
	{
		double a, b;
		a = x - ptr.x;
		b = y - ptr.y;
		cout << "z - c = ";
		print(a, b);
	}

	void mult(int c)
	{
		double a, b;
		a = x * c;
		b = y * c;
		cout << "z*a = ";
		print(a, b);
	}

	void div(int c)
	{
		double a, b;
		a = x / c;
		b = y / c;
		cout << "z/a = ";
		print(a, b);
	}
};

int main(void)
{
	double x, y;
	int a;

	cout << "   Complex number z = x + yi" << endl << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;

	cout << "z = ";
	complex complex_num(x, y);

	cout << endl << "   '+' Complex number c = x + yi" << endl << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;
	cout << "c = ";
	complex ptr(x, y);
	complex_num.add(ptr);

	cout << endl << "   '-' Complex number c = x + yi" << endl << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;
	ptr.x = x;
	ptr.y = y;
	cout << "c = ";
	ptr.print(x, y);
	complex_num.sub(ptr);

	cout << endl << "   '*' z*a = x*a + (y*a)i" << endl << "a = ";
	cin >> a;
	complex_num.mult(a);

	cout << endl << "   '/' z/a = x/a + (y/a)i" << endl << "a = ";
	cin >> a;
	complex_num.div(a);
	
	_getch();
	return 0;
}