#pragma once
#include<iostream>
template <class T>  
class Stack {
	int Size;// ���-�� ��������� � ����� 
	T* mas; // ������ ��� �����
	int MaxSize;// ������ ������� ��� �����
public:
	Stack(int _MaxSize = 10)//�����������(�� ���������)
	{
		if (_MaxSize <= 0)
		{
			throw _MaxSize;
		}
		MaxSize = _MaxSize;
		mas = new T[MaxSize];
		Size = 0;
	}
	~Stack()//����������
	{
		delete[] mas;
	}
	Stack(const Stack<T>& s)//����������� �����������
	{
		MaxSize = s.MaxSize;
		Size = s.Size;
		mas = new T[MaxSize];
		for (int i = 0; i < Size; i++)
			mas[i] = s.mas[i];
	}
	Stack& operator = (const Stack<T>& s)//�������� ������������
	{
		if (this != &s)
		{
			if (MaxSize != s.MaxSize)
			{
				MaxSize = s.MaxSize;
				delete[] mas;
				mas = new T[MaxSize];
			}
			Size = s.Size;
			for (int i = 0; i < Size; i++)
			{
				mas[i] = s.mas[i];
			}
		}
		return (*this);
	}
	bool Empty()//�������� �������� ������� ����� �� �������
	{
		if (Size == 0)
			return true;
		return false;
	}
	bool Full()//�������� �������� ������� ����� �� �������
	{
		if (Size == MaxSize)
			return true;
		return false;
	}
	void Push(T a)// �������� ������� �� ���� �����
	{
		if (Full()==true)
			throw MaxSize;
		mas[Size] = a;
		Size++;
	}
	T Pop()// ������� ������� ������� �����
	{
		if (Empty())
			throw Size;
		return mas[--Size];
	}
	T Top()// ���������� ������� ������� �����
	{
		if (Empty())
			throw Size;
		return mas[Size - 1];
	}
	int StSize() 
	{ 
	return Size; 
	}
	void StClear() 
	{
		Size = 0;
	}
	int operator == (const Stack<T>& s)
	{
		if (this != &s)
		{
			if (MaxSize != s.MaxSize || Size != s.Size)
				return -1;
			for (int i = 0; i < Size; i++)
			{
				if (mas[i] != s.mas[i])
					return -1;
			}
		}
		return 1;
	}
	int operator != (const Stack<T>& s)
	{
		return !(*this == s);
	}
};
