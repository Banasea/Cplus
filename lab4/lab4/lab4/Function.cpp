#include "Header.h"

void DataNew()
{
	ofstream _buf("Buffer.txt");

	if (!_buf) cout << "������ �������� ������" << endl;

	_buf.close();
}
void DataEntry()
{
	infoMagazin newBuf;
	int n;

	cout << "������� ���-�� ������: " << endl;//���������
	cin >> n; //������


	//��������� ���� ������ 
	ofstream record("Buffer.txt", ios::app); // ��������� � ����� ::app

	if (record)  {  //���� �������� ����
		record << n << endl; 

		for (int i = 0; i < n; i++) {
			cout << "�����: " << endl;
			cin >> newBuf.num;

			cout  << "�������� ������: " << endl;
			cin >> newBuf.nameProduct;

			cout << "E������ ���������: " << endl;
			cin >> newBuf.measurements;

			cout << "����: " << endl;
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
		cout << "������ �������� �����!" << endl;
		record.close();
	}
	record.close();

}
void DataRead(string fileName)
{
	infoMagazin newBuf;
	// ������ ������ �� �����
	ifstream reading(fileName);
	ofstream record("Buffer.txt", ios::out);

	if (reading)
	{
		if (record)
		{
			//��������� ���������� 
			int n;

			//��������� ������ 
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
			cout << "������ ���� �������!" << endl;
		}
		else {
			cout << "�������� ������!" << endl;
		}
	}
	else {
		cout << "�������� ������" << endl;
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
		//��������� ������
		
		int n;

		reading >> n;
		if (n>0)
		{
		cout << "���-�� ������: " << n << endl << endl;

		for (int i = 0; i < n; i++)
		{
			cout << "�: "<< i + 1 << endl;
			reading >> newBuf.num;
			cout << "�����: " << newBuf.num << endl;
			reading >> newBuf.nameProduct;
			cout << "�������� ������: " << newBuf.nameProduct << endl;
			reading >> newBuf.measurements;
			cout << "E������ ���������: "<< newBuf.measurements << endl;
			reading >> newBuf.price;
			cout << "����: " << newBuf.price <<endl;
			cout << "__________" << endl << endl;
		}

		}
		else
		{
			cout << "������ �����!" << endl;
		}
	}
	else
	{
		cout << "������ ������" << endl;
	}
	reading.close();
}
void DataChange()
{
	Copy();
	//����������� � ����, ��� ����� ����������
	ifstream reading("BufferNew.txt"); //����� ��� ������
	ofstream record("Buffer.txt", ios::out); //����� ��� ������ out-

	if (reading)
	{
		if (record)
		{
			infoMagazin newBuf;
			int n, d;

			reading >> n;

			cout << "�������� ����� ����������� �������� �� 1 �� " << n << endl;
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
						cout << "�����: " << endl;
						cin >> newBuf.num;
						cout << "�������� ������: " << endl;
						cin >> newBuf.nameProduct;
						cout << "E������ ���������: " << endl;
						cin >> newBuf.measurements;
						cout << "����: " << endl;
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
				cout << "������ ��������!" << endl;
			}
			else
			{
				cout << "����� ������ �� �����!" << endl;
			}
		}
		else
		{
			cout << "�������� ������!" << endl;
		}
	}
	else
	{
		cout << "�������� ������!" << endl;
	}
	
	record.close();
	reading.close();
	remove("BufferNew.txt");
}
void Copy()
{
	//����������� � ����� ���� 
	ifstream reading("Buffer.txt"); //����� ��� ������
	ofstream record("BufferNew.txt", ios::out); //����� ��� ������ out-

	if (reading)
	{
		if (record)
		{
			//��������� ����������
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
	ifstream reading("BufferNew.txt"); //����� ��� ������
	ofstream record("Buffer.txt", ios::out); //����� ��� ������ out � ������� ����������

	if (reading) //��������
	{
		if (record)
		{
			//��������� ���������� 
			infoMagazin newBuf;
			int n, d;

			reading >> n; //��������� �� ��������� ����� � �����
			int b = n - 1;

			cout << "�������� ����� ���������� �������� �� 1 �� " << n << endl;
			cin >> d;
			d--;

			system("cls");

			record << b << endl; //���������� ����� ������ �.� n-1

			if (d >= 0 && d < n) { //��������� �� ��������� ����� ����� ������� ����� ������� 
				for (int i = 0; i < n; i++)
				{
					if (i != d) // ���� ������� �� ��� ������� ����� ������� ������ ���������� ������ 
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
				cout << "������ ���� �������!" << endl;
			} 
			else 
			{ cout << "����� ������ �� �����!" << endl; }
		} 
		else
		{ cout << "�������� ������!" << endl; }
	}
	else 
	{ cout << "�������� ������!" << endl; }
	
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
		cout << "������ �������� ��������� �����!" << endl; 

	size.close();

	return n;
	
}
void DataAdd()
{
	//��������� ���������� 
	infoMagazin newBufAdd;
	int n = DataSize() + 1; //���-�� ��������� +1

	ofstream record("Buffer.txt", ios::app); // ���������� � �����
	ofstream recordSize("Buffer.txt", ios::out | ios::in); //��� ������� ������� ��������� 

	if (recordSize)
	{
		recordSize << n << endl;
	}
	else {

		cout << "������ �������� ��������� �����!" << endl;
	}

	if (record)
	{
		record << endl;

		cout << "�����: " << endl;
		cin >> newBufAdd.num;
		
		cout << "�������� ������: " << endl;
		cin >> newBufAdd.nameProduct;

		cout << "E������ ���������: " << endl;
		cin >> newBufAdd.measurements;

		cout << "����: " << endl;
		cin >> newBufAdd.price;

		record << newBufAdd.num << endl;
		record << newBufAdd.nameProduct << endl;
		record << newBufAdd.measurements << endl;
		record << newBufAdd.price;

		cout << "_____________" << endl;

	}
	else
	{

		cout << "������ �������� ��������� �����!" << endl;
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
	
	system("cls"); //������� �������
	Copy();
	ifstream reading("BufferNew.txt");
	ofstream record("Buffer.txt", ios::app);
	if (reading)
	{
		//��������� ���������� 
		int n;

		//��������� ������ 
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