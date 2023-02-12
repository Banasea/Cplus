#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

struct infoMagazin {

public:
	int num; //номер товара
	string nameProduct;//название товара
	string measurements;//единица измерения
	int price;//цена
};



void DataNew();
void DataEntry(); 
void DataRead(string fileName);
void DataPrint();
void DataChange();
void Copy();
void DataDelete();
void DataAdd();
int DataSize();
void sortItem();