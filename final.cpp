// final.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

template <typename T, typename U>
int counter(const T& start, const T& end, const U& toFind)
{
	int res = 0;
	for (auto i = start; i != end; ++i)
	{
		if (*i == toFind)
		{
			res++;
		}
	}
	return res;
}

void f(int n)
{
	cout << 'a';
	if (n > 1)
	{
		f(n / 2);
		cout << 'b';
		f(n / 2);
		cout << 'c';
	}
}



class Embedded
{
public:
	Embedded() { cout << '1'; }
	~Embedded() { cout << '2'; }
};

class Grandparent
{
public:
	Grandparent() { cout << '3'; }
	~Grandparent() { cout << '4'; }
};

class Parent : public Grandparent
{
public:
	Parent() { cout << '5'; }
	~Parent() { cout << '6'; }
private:
	Embedded embed;
};

class Child : public Parent
{
public:
	Child() { cout << '7'; }
	~Child() { cout << '8'; }
};

struct OurException {};

struct OurOtherException : public exception {
	OurOtherException(int n) : n(n) {}
	const char* what() const noexcept { return "In OurOtherException"; }
	int n;
};

struct OurOtherException2 : public logic_error {
	OurOtherException2() : logic_error("In OurOtherException2") {}
};

void bar(int n) {
	//assert(n <= 200);
	if (n > 200) {
		// what to do?
		// throw 3.141;
		//throw OurException();
		//throw OurOtherException(n);
		throw OurOtherException2();
	}
}

void foo(int n) {
	bar(n);
}

class Integer
{
public:
	Integer(int n) : n(n) {}
	explicit operator bool() const
	{
		return (n % 2 == 0);
	}
private:
	int n;
};



int main()
{
	try {
		cout << "=========Counter find if=========" << endl;
		vector <int> vec = { 1,2,3,3,3,2,8,7,9 };
		cout << counter(vec.begin(), vec.end(), 2) << endl;
		cout << counter(vec.begin(), vec.end(), 3) << endl;
		cout << counter(vec.begin(), vec.end(), 1) << endl;
		cout << endl << endl;


		cout << "=========Recursion Question=========" << endl;
		f(5);
		cout << endl;
		cout << endl << endl;


		cout << "=========Auto=========" << endl;
		auto x = 17;
		x = 3.141;
		cout << "x: " << x << endl;
		auto y = 1.32;
		y = 100;
		cout << "y: " << y << endl;
		cout << 2.00 << endl;
		cout << endl << endl;



		cout << "=========Exception Handling=========" << endl;
		try {
			foo(300);
		}
		catch (int x) { cerr << "caught int: " << x << endl; }
		catch (double x) { cerr << "caught double: " << x << endl; }
		catch (exception& x) {
			cerr << "caught exception: " << x.what() << endl;
		}
		cout << endl << endl;

		cout << "=========Bool Operator=========" << endl;
		Integer i(2);
		if (i) { cout << "is even" << endl; }
		else { cout << "is odd" << endl; }


		//this should be last thing in cpp so constructors and destructors appear on same line jsyk
		cout << "=========Inheritance Stack=========" << endl;
		Child c;
		return 0;
	}
	catch (...) { cerr << "so long and thanks for all the fish!" << endl; }
}