#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

struct infoMagazin {

public:
	int num; //����� ������
	string nameProduct;//�������� ������
	string measurements;//������� ���������
	int price;//����
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