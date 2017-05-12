#include "stdafx.h"
#include <conio.h>
#include <iostream>

using namespace std;

class complex
{
public:
	double x;
	double y;

public:
	complex() { x = 0.0; y = 0.0; }

	complex(double x, double y)
	{
		this->x = x;
		this->y = y;
	}

    void print(ostream&)
    {
        cout << x << " + i*(" << y << ')' << endl;
    }

    friend ostream& operator << (ostream&, const complex&);

    complex add(complex ptr)
	{
        ptr.x = x + ptr.x;
        ptr.y = y + ptr.y;
	cout << "z + c = ";
        return ptr;
	}

    complex sub(complex ptr)
	{
        ptr.x = x - ptr.x;
        ptr.y = y - ptr.y;
	cout << "z - c = ";
        return ptr;
	}

    complex mult(int c)
	{
        complex ptr(0, 0);
        ptr.x = x * c;
        ptr.y = y * c;
	cout << "z*a = ";
        return ptr;
	}

    complex div(int c)
	{
        complex ptr(0, 0);
        ptr.x = x / c;out
        ptr.y = y / c;
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
	double x, y;
	int a;

	cout << "   Complex number z = x + i*y" << endl << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;

	cout << "z = ";
	complex complex_num(x, y);
    	cout << complex_num;

	cout << endl << "   '+' Complex number c = x + i*y" << endl << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;
	cout << "c = ";
	complex ptr(x, y);
	ptr = complex_num.add(ptr);
    	cout << ptr;

	cout << endl << "   '-' Complex number c = x + i*y" << endl << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;
	ptr.x = x;
	ptr.y = y;
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
