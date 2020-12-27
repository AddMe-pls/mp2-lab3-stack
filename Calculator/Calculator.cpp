#include "../Stack/Stack.h"
#include "Calculator.h"
#include<iostream>
#include<string>
#include<cmath>
int Calculator::Priority(char elem)
{
	switch (elem)
	{
	case'(':return 1;
	case')':return 1;
	case'+': return 2;
	case'-': return 2;
	case'*': return 3;
	case'/': return 3;
	case'^':return 4;
	}
}
bool Calculator:: CheckBrackets()
{
	st1.StClear();
	st2.StClear();
	for (int i = 0; i < postfix.size(); i++)
	{
		if (infix[i] == '(' || infix[i] == 's' || infix[i] == 'c' || infix[i] == 'e' || infix[i] == 'l')
		{
			st1.Push(infix[i]);
		}
		if (infix[i] == ')')
		{
			if (st1.Empty() == true)
			{
				return false;
			}
			st1.Pop();
		}
	}
	return st1.Empty();
}
void Calculator::SetFormula(std::string str)
{
	infix = " ";
	for (unsigned int i = 0; i < str.size(); i++)
	{
		if (str[i] == 's' || str[i] == 'c' || str[i] == 'e' || str[i] == 'l')
		{
			infix += " ";
			infix += str[i];
			i += 3;
			if (i >= str.size() - 2)
				throw 0;
		}
		else
		{
			if (Priority(str[i]) != 0)
			{
				infix += " ";
			}
			infix += str[i];
		}

	}
	infix += ' ';
	if (CheckBrackets() != true)
	{
		throw 0;
	}
	Stack<char> c(infix.size());
	Stack<double> d(infix.size());
	st1 = c;
	st2 = d;
}
double Calculator::Calc()
{
	ToPostfix();
	st1.StClear();
	st2.StClear();
	for (int i = 0; i < postfix.size(); i++)
	{
		double a, b;
		switch (postfix[i])
		{
		case'+': a = st2.Pop(); b = st2.Pop();
			st2.Push(a + b);
			break;
		case'-': a = st2.Pop(); b = st2.Pop();
			st2.Push(b - a);
			break;
		case'*': a = st2.Pop(); b = st2.Pop();
			st2.Push(b * a);
			break;
		case'/': a = st2.Pop(); b = st2.Pop();
			st2.Push(b / a);
			break;
		case'^': a = st2.Pop(); b = st2.Pop();
			st2.Push(pow(b, a));
			break;
		case's': a = st2.Pop(); st2.Push(sin(a));
			break;
		case'c': a = st2.Pop(); st2.Push(cos(a));
			break;
		case'e': a = st2.Pop(); st2.Push(exp(a));
			break;
		case'l': a = st2.Pop(); st2.Push(log(a));
			break;
		default:
			if (postfix[i] != ' ')
			{
				unsigned int k = i, point = 0, flag = 0;;
				while (postfix[k] != ' ' && k != postfix.size())
				{
					if (postfix[k] == '.')
					{
						point = k;
						flag = 1;
					}
					k++;
				}
				unsigned int delta = k - i - flag;
				if (flag == 1)
				{
					point = k - point - flag;
				}
				k = i;
				double z = 0;
				while (postfix[k] != ' ' && k != postfix.size())
				{
					if (postfix[k] != '.')
					{
						delta--;
						z += (postfix[k] - '0') * pow(10, delta);
					}
					k++;
				}
				if (flag == 1)
				{
					z /= pow(10, point);
				}
				st2.Push(z);
				i = k;
			}
			break;
		}
	}
	if (st2.StSize() != 1)
	{
		throw 0;
	}
	return st2.Pop();
}
void Calculator::ToPostfix()
{
	/*postfix = "";
	std::string src = "(" + infix + ")";
	char elem = '!';
	unsigned int i = 0;
	st1.StClear();
	while (i < src.size())
	{
		if (src[i] == '+' || src[i] == '-' || src[i] == '*' || src[i] == '/' || src[i] == '^')
		{
			postfix += " ";
			elem = st1.Pop();
			while (Priority(elem) >= Priority(src[i]))
			{
				postfix += elem;
				elem = st1.Pop();
			}
			st1.Push(elem);
			st1.Push(src[i]);
		}
		else if (src[i] == '(')
		{
			st1.Push(src[i]);
		}
		else if (src[i] == ')')
		{
			elem = st1.Pop();
			while (elem != '(')
			{
				postfix += elem;
				elem = st1.Pop();
			}
		}
		else if (src[i] >= '0' && src[i] <= '9')//добавить символ точку
		{
			postfix += src[i];
		}
		i++;
	}*/
	st1.StClear();
	st2.StClear();
	postfix = "";
	std::string tmp = "(" + infix + ")";
	for (unsigned int i = 0; i < tmp.size(); i++)
	{
		if (Priority(tmp[i]) == 0)
		{
			postfix += tmp[i];
		}
		else
		{
			if (tmp[i] == '(' || tmp[i] == 's' || tmp[i] == 'c' || tmp[i] == 'l' || tmp[i] == 'e')
			{
				st1.Push(tmp[i]);
			}
			else
			{
				if (tmp[i] == ')')
				{
					while (st1.Top() != '(' && st1.Top() != 's' && st1.Top() != 'c' && st1.Top() != 'l' && st1.Top() != 'e')
					{
						char a = st1.Pop();
						postfix += ' ';
						postfix += a;
					}
					if (st1.Top() == '(')
						st1.Pop();
					else
					{
						char a = st1.Pop();
						postfix += ' ';
						postfix += a;
					}
				}
				else
				{
					while (Priority(st1.Top()) >= Priority(tmp[i]))
					{
						char a = st1.Pop();
						postfix += ' ';
						postfix += a;
					}
					st1.Push(tmp[i]);
				}
			}
		}
	}
	if (!st1.Empty())
	{
		throw 0;
	}
}
double Calculator:: CalcPostfix()
{
	unsigned int i = 0;
	st2.StClear();
	while (i < postfix.size())
	{
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^')
		{
			double k2 = st2.Pop();
			double k1 = st2.Pop();
			switch (postfix[i])
			{
			case '+':
				{
				st2.Push(k1+k2);
				break;
				}
			case '-':
			{
				st2.Push(k1 - k2);
				break;
			}
			case '*':
			{
				st2.Push(k1 * k2);
				break;
			}
			case '/':
			{
				st2.Push(k1 / k2);
				break;
			}
			case '^':
			{
				st2.Push(pow(k1,k2));
				break;
			}
			}
		}
		if (postfix[i] >= '0' && postfix[i] <= '9')
		{
			double tmp = postfix[i] - '0';
			st2.Push(tmp);
		}
		i++;
	}
	return st2.Top();
}