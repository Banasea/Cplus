#include "Header.h"

void DataNew()
{
	ofstream _buf("Buffer.txt");

	if (!_buf) cout << "Ошибка создания буфера" << endl;

	_buf.close();
}
void DataEntry()
{
	infoMagazin newBuf;
	int n;

	cout << "Введите кол-во данных: " << endl;//интерфейс
	cin >> n; //запись


	//открываем файл буфера 
	ofstream record("Buffer.txt", ios::app); // записываю в конец ::app

	if (record)  {  //если открылся файл
		record << n << endl; 

		for (int i = 0; i < n; i++) {
			cout << "Номер: " << endl;
			cin >> newBuf.num;

			cout  << "Название товара: " << endl;
			cin >> newBuf.nameProduct;

			cout << "Eдиница измерения: " << endl;
			cin >> newBuf.measurements;

			cout << "Цена: " << endl;
			cin >> newBuf.price;

			record << newBuf.num << endl;
			record << newBuf.nameProduct << endl;
			record << newBuf.measurements << endl;
			if (i < n - 1) {
				record << newBuf.price << endl;
			}
			else 
				record << newBuf.price;
			
			cout << "_____________" << endl;
		}
	}
	else {
		cout << "Ошибка открытия файла!" << endl;
		record.close();
	}
	record.close();

}
void DataRead(string fileName)
{
	infoMagazin newBuf;
	// чтение данных из файла
	ifstream reading(fileName);
	ofstream record("Buffer.txt", ios::out);

	if (reading)
	{
		if (record)
		{
			//временные переменные 
			int n;

			//считываем данные 
			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++)
			{
				reading >> newBuf.num;
				reading >> newBuf.nameProduct;
				reading >> newBuf.measurements;
				reading >> newBuf.price;

				record << newBuf.num << endl;
				record << newBuf.nameProduct << endl;
				record << newBuf.measurements << endl;
				if (i < n - 1)
				{
					record << newBuf.price << endl;
				}
				else
				{
					record << newBuf.price;
				}
			}
			cout << "Данные были считаны!" << endl;
		}
		else {
			cout << "Проблема записи!" << endl;
		}
	}
	else {
		cout << "проблема чтения" << endl;
	}
	reading.close();
	record.close();
}
void DataPrint()
{
	infoMagazin newBuf;
	ifstream reading("Buffer.txt");

	if (reading)
	{
		//временные данные
		
		int n;

		reading >> n;
		if (n>0)
		{
		cout << "Кол-во данных: " << n << endl << endl;

		for (int i = 0; i < n; i++)
		{
			cout << "№: "<< i + 1 << endl;
			reading >> newBuf.num;
			cout << "Номер: " << newBuf.num << endl;
			reading >> newBuf.nameProduct;
			cout << "Название товара: " << newBuf.nameProduct << endl;
			reading >> newBuf.measurements;
			cout << "Eдиница измерения: "<< newBuf.measurements << endl;
			reading >> newBuf.price;
			cout << "Цена: " << newBuf.price <<endl;
			cout << "__________" << endl << endl;
		}

		}
		else
		{
			cout << "Данные пусты!" << endl;
		}
	}
	else
	{
		cout << "Ошибка чтения" << endl;
	}
	reading.close();
}
void DataChange()
{
	Copy();
	//копирование в файл, тем самым перезапись
	ifstream reading("BufferNew.txt"); //поток для чтения
	ofstream record("Buffer.txt", ios::out); //поток для записи out-

	if (reading)
	{
		if (record)
		{
			infoMagazin newBuf;
			int n, d;

			reading >> n;

			cout << "Выберите номер заменяемого элемента от 1 до " << n << endl;
			cin >> d;
			d--;

			system("cls");

			record << n << endl;

			if (d >= 0 && d < n)
			{
				for (int i = 0; i < n; i++)
				{
					if ( i != d)
					{
						reading >> newBuf.num;
						record << newBuf.num << endl;

						reading >> newBuf.nameProduct;
						record << newBuf.nameProduct << endl;

						reading >> newBuf.measurements;
						record << newBuf.measurements << endl;

						reading >> newBuf.price;
						if (i < n - 1) {
							record << newBuf.price << endl;
						}
						else
							record << newBuf.price;

						cout << "_____________" << endl;
					}
					else
					{
						cout << "Номер: " << endl;
						cin >> newBuf.num;
						cout << "Название товара: " << endl;
						cin >> newBuf.nameProduct;
						cout << "Eдиница измерения: " << endl;
						cin >> newBuf.measurements;
						cout << "Цена: " << endl;
						cin >> newBuf.price;

						record << newBuf.num << endl;
						record << newBuf.nameProduct << endl;
						record << newBuf.measurements << endl;

						if (i < n - 1) {
							record << newBuf.price << endl;
						}
						else
						{
							record << newBuf.price;

						}

						cout << "_____________" << endl;

					}
				}
				cout << "Данные изменены!" << endl;
			}
			else
			{
				cout << "Номер введен не верно!" << endl;
			}
		}
		else
		{
			cout << "Проблема записи!" << endl;
		}
	}
	else
	{
		cout << "Проблема чтения!" << endl;
	}
	
	record.close();
	reading.close();
	remove("BufferNew.txt");
}
void Copy()
{
	//копирование в новый файл 
	ifstream reading("Buffer.txt"); //поток для чтения
	ofstream record("BufferNew.txt", ios::out); //поток для записи out-

	if (reading)
	{
		if (record)
		{
			//временные переменные
			infoMagazin newBuf;
			int n;

			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++)
			{
				reading >> newBuf.num;
				record << newBuf.num << endl;

				reading >> newBuf.nameProduct;
				record << newBuf.nameProduct << endl;

				reading >> newBuf.measurements;
				record << newBuf.measurements << endl;

				reading >> newBuf.price;

				if (i < n - 1)
				{
					record << newBuf.price << endl;
				}
				else
				{
					record << newBuf.price;
				}
			}
		}
	}
}
void DataDelete()
{
	Copy();
	ifstream reading("BufferNew.txt"); //поток для чтения
	ofstream record("Buffer.txt", ios::out); //поток для записи out и удаляем содержимое

	if (reading) //проверки
	{
		if (record)
		{
			//временные переменные 
			infoMagazin newBuf;
			int n, d;

			reading >> n; //считываем из буферного файла в новый
			int b = n - 1;

			cout << "Выберите номер удаляемого элемента от 1 до " << n << endl;
			cin >> d;
			d--;

			system("cls");

			record << b << endl; //записываем новые данные т.е n-1

			if (d >= 0 && d < n) { //проверяем ли правильно ввели номер который хотим удалить 
				for (int i = 0; i < n; i++)
				{
					if (i != d) // если элемент не тот который хотим удалить просто записываем данные 
					{
						reading >> newBuf.num;
						reading >> newBuf.nameProduct;
						reading >> newBuf.measurements;
						reading >> newBuf.price;

						record << newBuf.num << endl;
						record << newBuf.nameProduct << endl;
						record << newBuf.measurements << endl;
						if (i < n - 1)
						{
							record << newBuf.price << endl;
						}
						else
						{
							record << newBuf.price;
						}
					}
					else
					{
						reading >> newBuf.num;
						reading >> newBuf.nameProduct;
						reading >> newBuf.measurements;
						reading >> newBuf.price;
					}
				}
				cout << "Данные были удалены!" << endl;
			} 
			else 
			{ cout << "Номер введен не верно!" << endl; }
		} 
		else
		{ cout << "Проблема записи!" << endl; }
	}
	else 
	{ cout << "Проблема чтения!" << endl; }
	
	record.close();
	reading.close();
	remove("BufferNew.txt");
	
}
int DataSize()
{
	ifstream size("Buffer.txt");
	int n;

	if (size)
	{
		size >> n;
	}
	else 
		cout << "Ошибка открытия буферного файла!" << endl; 

	size.close();

	return n;
	
}
void DataAdd()
{
	//временные переменные 
	infoMagazin newBufAdd;
	int n = DataSize() + 1; //кол-во элементов +1

	ofstream record("Buffer.txt", ios::app); // добавление в конец
	ofstream recordSize("Buffer.txt", ios::out | ios::in); //для ззаписи сколько элементов 

	if (recordSize)
	{
		recordSize << n << endl;
	}
	else {

		cout << "Ошибка открытия буферного файла!" << endl;
	}

	if (record)
	{
		record << endl;

		cout << "Номер: " << endl;
		cin >> newBufAdd.num;
		
		cout << "Название товара: " << endl;
		cin >> newBufAdd.nameProduct;

		cout << "Eдиница измерения: " << endl;
		cin >> newBufAdd.measurements;

		cout << "Цена: " << endl;
		cin >> newBufAdd.price;

		record << newBufAdd.num << endl;
		record << newBufAdd.nameProduct << endl;
		record << newBufAdd.measurements << endl;
		record << newBufAdd.price;

		cout << "_____________" << endl;

	}
	else
	{

		cout << "Ошибка открытия буферного файла!" << endl;
	}

	record.close();
	recordSize.close();
}
void bubbleCopy()
{

}
void sortItem()
{
	infoMagazin newBuf;
	
	system("cls"); //очистка консоли
	Copy();
	ifstream reading("BufferNew.txt");
	ofstream record("Buffer.txt", ios::app);
	if (reading)
	{
		//временные переменные 
		int n;

		//считываем данные 
		reading >> n;
		record << n << endl;
		

		for (int i = 0; i < n; i++)
		{
			reading >> newBuf.num;
			reading >> newBuf.nameProduct;
			reading >> newBuf.measurements;
			reading >> newBuf.price;

			record << newBuf.num << endl;
			record << newBuf.nameProduct << endl;
			record << newBuf.measurements << endl;

			if (i < n - 1)
			{
				record << newBuf.price << endl;
			}
			else
			{
				record << newBuf.price;
			}
		}


	}

}