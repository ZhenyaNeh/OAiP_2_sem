#include <iostream>
using namespace std;
///////////
float GetFirstEquation(float a, float x)
{
	return ((x * x * x) + (2 * x) - 4) * ((a * a * a) + (2 * a) - 4);
}

float GetSecondEquation(float a, float x)
{
	return ((x * x) - 1) * ((a * a) - 1);
}
/////////////////
float GetFirstEquation1(float a, float x)
{
	return ((x * x) + (4 * x) - 2) * ((a * a) + (4 * a) - 2);
}

float GetSecondEquation1(float a, float x)
{
	return (sin(x) + 0.1) * (sin(a) + 0.1);
}
////////////////////////
float GetFirstEquation2(float a, float x)
{
	return (cos(x) + (x) - 7) * (cos(a) + (a) - 7);
}

float GetSecondEquation2(float a, float x)
{
	return (exp(x) - 1/x) * (exp(a) - 1/x);
}
////////////////
float GetFirstEquation3(float a, float x)
{
	return ((x * x * x) + (2 * x) - 7) * ((a * a * a) + (2 * a) - 7);
}

float GetSecondEquation3(float a, float x)
{
	return (exp(x) - 2*x) * (exp(a) - 2*x);
} 


void GetForm( float a, float b,float(*choise)(float a , float x))
{
	float e{0.001}, x{0};
	while (abs(a - b) > e * 2)
	{
		x = (a + b) / 2;
		if ( choise(a, x) <= 0)
		{
			b = x;
		}
		else
		{
			a = x;
		}
	}
	cout << "x = " << x << "\n";
}

void main() 
{
	float a, b;
	cout << "Initial data: \nWrite a: "; cin >> a;
	cout << "Write b: "; cin >> b;
	cout << "Var 7\n ";
	GetForm(a, b, GetFirstEquation);
	GetForm(a, b, GetSecondEquation);
	cout << "Var 1 \n";
	GetForm(a, b, GetFirstEquation1);
	GetForm(a, b, GetSecondEquation1);
	cout << "Var 3\n ";
	GetForm(a, b, GetFirstEquation2);
	GetForm(a, b, GetSecondEquation2);
	cout << "Var 12\n ";
	GetForm(a, b, GetFirstEquation3);
	GetForm(a, b, GetSecondEquation3);
}

//x3 + 2x – 4, x2 – 1	//	в Excel 1,1795  ,  -1,00023

/*начало функции GetFirstEquation
	возращаем ((x * x * x) + (2 * x) - 4) * ((a * a * a) + (2 * a) - 4)
когнец*/

/*начало функции GetSecondEquation
	возращаем ((x * x) - 1) * ((a * a) - 1)
конец*/




/*начало функции GetForm
	инициализируем и присваеваем значения переменным  e=0,001, x=0
	начало цикла
		условие модуль из a - b больше e * 2
		присваеваем x значение (a + b) / 2
		если choise(a, x) меньше или равно 0
			b присваеваем x
		иначе
			a присваеваем x
	конец цикла
	вывод "x= " и х
конец*/

/*Насало функции main
	инициализируем a, b
	вывод "Initial data: Write a: "
	ввод a
	вывод "Write b: "
	ввод b
	вызываем GetForm(a, b, GetFirstEquation)
	вызываем GetForm(a, b, GetSecondEquation)
конец*/
