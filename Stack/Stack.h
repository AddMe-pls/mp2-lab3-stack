#pragma once
#include<iostream>

template <class T>
struct TLink
{
	T val;
	TLink* pNext;
};


template <class T>  
class Stack {
	TLink<T>* pFirst;
public:
	Stack()
	{
		pFirst = NULL;
	}
	~Stack()
	{
		while (pFirst)
		{
			TLink<T>* tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
		}
	}
	Stack(const Stack<T>& s)
	{
		TLink<T>* tmp = new TLink<T>;
	    TLink<T>*tmp1 = s.pFirst;
		tmp->val = s.pFirst->val;
		pFirst = tmp;
		tmp1 = tmp1->pNext;
		while (tmp1)
		{
			TLink<T>* t = new TLink<T>;
			tmp->pNext = t;
			t->val = tmp1->val;
			tmp = tmp->pNext;
			tmp1 = tmp1->pNext;
		}
		tmp->pNext = NULL;
	}
	Stack& operator = (const Stack<T>& s)
	{

		if (s.pFirst != NULL)
		{
			while (pFirst != NULL)
			{
				this->StClear();
			}
			TLink<T>* tmp = new TLink<T>;
			TLink<T>* tmp1 = s.pFirst;
			tmp->val = s.pFirst->val;
			pFirst = tmp;
			tmp1 = tmp1->pNext;
			while (tmp1)
			{
				TLink<T>* t = new TLink<T>;
				tmp->pNext = t;
				t->val = tmp1->val;
				tmp = tmp->pNext;
				tmp1 = tmp1->pNext;
			}
			tmp->pNext = NULL;
		}
		else
			pFirst = NULL;
		return (*this);
	}
	bool Empty()
	{
		if (pFirst = NULL);
			return true;
		return false;
	}
	bool Full()
	{
		return false;
	}
	void Push(T a)
	{
		TLink<T>* tmp = new TLink<T>;
		tmp->pNext = pFirst;
		tmp->val = a;
		pFirst = tmp;
	}
	T Pop()
	{
		T tmp = pFirst->val;
		TLink<T>* t = pFirst;
		pFirst = pFirst->pNext;
		delete t;
		return tmp;
	}
	T Top()
	{
		if (pFirst == NULL)
			throw 0;
		return pFirst->val;
	}
	int StSize() 
	{ 
		int k = 0;
		TLink<T>* t = pFirst;
		while (t)
		{
			t = t->pNext;
			k++;
		}
		return k;
	}
	void StClear() 
	{
		while (pFirst)
		{
			TLink<T>* tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
		}
	}
	int operator == (const Stack<T>& s)
	{
			TLink<T>* tmp = s.pFirst;
			TLink<T>* tmp1 = pFirst;
			while (tmp)
			{
				if (tmp->val != tmp1->val)
					return false;
				tmp = tmp->pNext;
				tmp1 = tmp1->pNext;
			}
		return true;
	}
	int operator != (const Stack<T>& s)
	{
		return !(*this == s);
	}
};
