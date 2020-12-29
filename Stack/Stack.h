#pragma once
#include<iostream>
template <class T>  
class Stack {
	int Size;// кол-во элементов в стэке 
	T* mas; // массив для стэка
	int MaxSize;// размер массива для стэка
public:
	Stack(int _MaxSize = 10)//конструктор(по умолчанию)
	{
		if (_MaxSize <= 0)
		{
			throw _MaxSize;
		}
		MaxSize = _MaxSize;
		mas = new T[MaxSize];
		Size = 0;
	}
	~Stack()//деструктор
	{
		delete[] mas;
	}
	Stack(const Stack<T>& s)//конструктор копирования
	{
		MaxSize = s.MaxSize;
		Size = s.Size;
		mas = new T[MaxSize];
		for (int i = 0; i < Size; i++)
			mas[i] = s.mas[i];
	}
	Stack& operator = (const Stack<T>& s)//оператор присваивания
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
	bool Empty()//проверка текущего объекта стека на пустоту
	{
		if (Size == 0)
			return true;
		return false;
	}
	bool Full()//проверка текущего объекта стека на полноту
	{
		if (Size == MaxSize)
			return true;
		return false;
	}
	void Push(T a)// Добавить элемент на верх стека
	{
		if (Full()==true)
			throw MaxSize;
		mas[Size] = a;
		Size++;
	}
	T Pop()// Забрать верхний элемент стека
	{
		if (Empty())
			throw Size;
		return mas[--Size];
	}
	T Top()// Посмотерть верхний элемент стэка
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
