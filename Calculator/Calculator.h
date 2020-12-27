#pragma once

#include "../Stack/Stack.h"
#include <iostream>
#include <string>

//using namespace std;

class Calculator
{
	std::string infix;// ������ � ��������� ������
	std::string postfix;// ������ � ����������� ������
	Stack<char> st1;// ��� �������� �� infix � postfix
	Stack<double> st2;// ��� ���������� ���������
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
