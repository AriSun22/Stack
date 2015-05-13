// Стеки.cpp: определяет точку входа для консольного приложения.
//
/*!
\file Sortir.cpp
\brief Заголовочный файл с описанием классов

Данный файл содержит в себе определения основных 
классов, используемых в демонстрационной программе
*/

#include "stdafx.h"
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <locale.h>


struct Stack
{
	int value; //!< Переменная (элемент)
	Stack* next ; //!< Указатель
};

/**
	Функция инициализации стека
	*/



/**
	Функция добавления элемента в стек
	*/
void push(int a, Stack *&p) //Добавление элемента в стек
{
		Stack *newP = new Stack; //создаем новый элемент
		newP->value = a; //заполняем его.
		newP->next=p; //Заполняем его 
		p=newP;
}

/**
	Функция удаления элемента из стека
	*/
int pop (Stack *&p, int &data) //Удаление элемента из стека
{
	if (p!=0){
		data = p->value;
		p = p->next;
		return 0;
	}
	else{
		return -1;
	}
}

//!Главная функция
int main()
{
	setlocale(LC_ALL, "rus");

	srand(time(NULL));
	Stack *p=0;
		int n = 0; //кол-во операций
	cin >> n;

	int data;
	char op;
	for (int i = 0; i < n; i++) //изначально, заполним список
	{	
		cin >> op;
		if(op=='a')
		{
			cin >> data;
			push(data, p);
		}
		else
		if(op=='d'){
			if (pop(p, data)<0)
			{
				cout << "Ошибка! Стек пуст!" <<endl;
			}
		}
	}
	while(p){
		pop(p, data);
		cout<<data<< " ";

	}
	cout << "\n";
	system("pause");

	return 0;
}
