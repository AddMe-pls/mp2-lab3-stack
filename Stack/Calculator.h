#pragma once

#include "Stack.h"
#include <iostream>
#include <string>

using namespace std;

class Calculator
{
	string formula;
	Stack<char> st_c;
	Stack<double> st_d;
public:
	void SetFormula(string str)
	{

	}
	bool CheckBrackets()
	{
		Stack<char> c(formula.size());
		for (int i = 0; i < formula.length(); i++)
		{
			if (formula[i] == '(')
			{
				if (c.Full() == true)
				{
					return false;
				}
				c.Push('(');
			}
			if (formula[i] == ')')
			{
				if (c.Empty() == true)
				{
					return false;
				}
				char k = c.Pop();
			}
		}
		return c.Empty();
	}
	double res()
	{

	}
};

