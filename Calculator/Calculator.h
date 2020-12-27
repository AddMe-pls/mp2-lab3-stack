#pragma once

#include "../Stack/Stack.h"
#include <iostream>
#include <string>

//using namespace std;

class Calculator
{
	std::string infix;// строка в инфиксной записи
	std::string postfix;// строка в постфиксной записи
	Stack<char> st1;// дл€ перевода из infix в postfix
	Stack<double> st2;// дл€ вычислени€ выражени€
	int Priority(char elem);
	void ToPostfix();
public:
	Calculator() :st1(100), st2(100)
	{
		infix = "";
		postfix = "";
	}
	void SetExpression(std::string str)
	{
		infix = str;
	}
	std::string GetExpression()
	{
		return infix;
	}
	std::string GetPosfix()
	{
		return postfix;
	}
	//int Priority(char elem);
	void SetFormula(std::string str);
	double Calc();
	double CalcPostfix();
	bool CheckBrackets();
};
