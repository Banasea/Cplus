#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <istream>

using namespace std;

/*
	Интернет-магазин (номер, наименование товара, единица измерения, цена, дата поступления)

	1.номер /264
	2.наименование товара /Ролтон
	3.единица измерения /гр
	4.цена /$
	5.дата поступления /12.03.2021



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