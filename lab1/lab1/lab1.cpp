//Определяет, если два числа являются взаимно простыми
#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_ALL, "rus");
	int a; /*Создал переменную для получении введенных чисел*/
	int b;
	cout << "Введите 1е натуральное число: "<< endl; /*Для оформления*/
		cin >> a; /*Записываю полученное число*/
		cout << "Введите 2е натуральное число: " << endl;
		cin >> b;
		while (a != b)
		{
			if (a > b) {
				a = a - b;
			}
			else                //Определяю НОД Алгоритм Евклида
			{
				b = b - a;
			}
		}
		if (a == 1) {
			cout << "НОД = 1" << endl;
			system("pause");
		}
		else
		{
			cout << "НОД > 1";
		}
}
