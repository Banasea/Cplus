#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <istream>

using namespace std;

/*
	��������-������� (�����, ������������ ������, ������� ���������, ����, ���� �����������)

	1.����� /264
	2.������������ ������ /������
	3.������� ��������� /��
	4.���� /$
	5.���� ����������� /12.03.2021



*/
struct magazin
{
	int number;
	string	nameProduct, unit;
	int	price;
		

};
struct recieptData
{
	int day,
		mouth,
		year;
};
struct Data {
	magazin _magazin;
	recieptData _recieptData;
};
void dataEntry(Data* (&d), int &n);
void showBase(Data* d, int n);
void reName(Data* d, int n);
void sortItem(Data* d, int n);
void searchItem(Data* d, int n);
void copy(Data* (&d_n), Data* (&d_o), int n);
void deleteItem(Data* (&d), int& n);