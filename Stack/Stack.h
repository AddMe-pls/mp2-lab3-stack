#pragma once
template <class T>  
class Stack {
	int Size;// ���-�� ��������� � ����� 
	T* mas; // ������ ��� �����
	int MaxSize;// ������ ������� ��� �����
public:
	Stack(int _MaxSize = 10)//�����������(�� ���������)
	{
		MaxSize = _MaxSize;
		mas = new T[MaxSize];
		size = 0;
	}
	~Stack()//����������
	{
		delete[] mas;
	}
	Stack(const Stack<T>& s)//����������� �����������
	{
		MaxSize = s.MaxSize;
		mas = new T[MaxSize];
		Size = s.Size;
		for (int i = 0; i < Size; i++)
			mas[i] = s.mas[i];
	}
	Stack& operator = (const Stack<T>& s)//�������� ������������
	{
		if MaxSize != s.MaxSize;
		{
			delete[]mas;
			MaxSize = s.MaxSize;
			mas = new T[MaxSize];
			Size = s.Size;
		}
		for (int i = 0; i < Size; i++)
			mas[i] = s.mas[i];
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
		if (Size = MaxSize)
			return true;
		return false;
	}
	void Push(T a)// �������� ������� �� ���� �����
	{
		if (Full())
			throw MaxSize;
		mas[Size] = a;
		Size++;
	}
	T Pop()// ������� ������� ������� �����
	{
		if (Empty())
			throw Size;
		Size--;
		return mas[Size];
	}
	T Top()// ���������� ������� ������� �����
	{
		if (Empty())
			throw Size;
		return mas[size - 1];
	}
};