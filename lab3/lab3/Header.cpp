#include "Header.h"

void showBase(Data* d, int n) { // ����� �� ����� ����������� �������
	for (int i = 0; i < n; i++) {
		cout << "����� �" << i + 1<< "." << endl;

		cout << "�����-��� ������: " << d[i]._magazin.number<< endl;
		cout << "�������� ������: " << d[i]._magazin.nameProduct << endl;
		cout << "������� ��������� ������: " << d[i]._magazin.unit << endl;
		cout << "����: " << d[i]._magazin.price << endl;
		cout << "���� ����������� �/�/�: " << d[i]._recieptData.day 
			<< "." << d[i]._recieptData.mouth 
			<< "." << d[i]._recieptData.year << endl;
		cout << endl;

	}
}
void dataEntry(Data* (&d)/*����� �� �����*/, int& n) { // ���������� ������
	cout << "������� ���������� �������: ";
	cin >> n;
	//������� ������
	d = new Data[n];
	if (n > 0) {
		for (int i = 0; i < n; i++)
		{
			int num = 0;
			cout << endl;
			cout << "������� �����-��� ������: " ;
			cin >> d[i]._magazin.number;
			cout << "������ �������� ������: ";
			cin >> d[i]._magazin.nameProduct;
			cout << "������� ������� ��������� ������: ";
			cin >> d[i]._magazin.unit;
			cout << "������� ����: " ;
			cin >> d[i]._magazin.price;
			cout << "������� ���� ����������� � � � ";
			cin >> num;
			if (num <= 31) {
				d[i]._recieptData.day = num;
			}
			else {
				cout << "�� ���� ������� ���� EROR";
				system("pause"); //�������� ����� ���������	
			}
			cin >> num;
				if (num <= 12) {
					d[i]._recieptData.mouth = num;
				}
				else {
					cout << "�� ���� ������� ���� EROR";
					system("pause"); //�������� ����� ���������
				}
		    cin >> num;
				if (num <= 2021) {
					d[i]._recieptData.year = num;
				}
				else {
					cout << "�� ���� ������� ���� EROR";
					system("pause"); //�������� ����� ���������					
				}
			cout << endl;
			cout << "_________����� ��� ��������_________" << endl;
			system("pause"); //�������� ����� ���������
			system("cls"); //������� �������
			
		}
	}
	else
	{
		cout << "������ 404" << endl;
		system("pause"); //�������� ����� ���������
		system("cls"); //������� �������
		
	}
}

void reName(Data* d, int n) { // ��������� ������
		for (int i = 0; i < n; i++) {
			cout << "����� " << i + 1 << "." << endl;
			cout << "�������� ������: " << d[i]._magazin.nameProduct << endl;
		}
		cout << "������� � ������: " << endl;
		cin >> n;
		n--;

		int num = 0;
		if (n >= 0 ) {
			cout << "������� �����-��� ������: ";
			cin >> d[n]._magazin.number;
			cout << "������ �������� ������: ";
			cin >> d[n]._magazin.nameProduct;
			cout << "������� ������� ��������� ������: ";
			cin >> d[n]._magazin.unit;
			cout << "������� ����: ";
			cin >> d[n]._magazin.price;
			cout << "������� ���� ����������� � � �: ";
			cin >> num;
			if (num <= 31) {
				d[n]._recieptData.day = num;
			}
			cin >> num;
			if (num <= 12) {
				d[n]._recieptData.mouth = num;
			}
			cin >> num;
			if (num <= 2021) {
				d[n]._recieptData.year = num;
			}
			cout << "_________����� ��� ��������_________" << endl;
			system("pause"); //�������� ����� ���������
			system("cls"); //������� �������
		}
		else
		{
			cout << "Eror 404";
			system("pause"); //�������� ����� ���������
			system("cls"); //������� �������
		}

		
}
int tempNum; // ���� ���� ����� � ����������
void miniSort() {
	cout << "�������� �� ������ ������ �� ������ �����������: " << endl
		<< "(1) �� ����." << endl
		<< "(2) �� ������." << endl   // ���������� �������
		<< "(3) �� ��������." << endl
		<< "(4) �� ���� �����������."<< endl 
		<< "(0) �����" << endl;
	cin >> tempNum;
	system("cls"); //������� �������;
}
void bubbleCopy(Data& data_new, Data& data_old) { //���������� ������ ������ � �����.
	data_new._magazin.number = data_old._magazin.number;
	data_new._magazin.nameProduct = data_old._magazin.nameProduct;
	data_new._magazin.unit = data_old._magazin.unit;
	data_new._magazin.price = data_old._magazin.price;

	data_new._recieptData.day = data_old._recieptData.day;
	data_new._recieptData.mouth = data_old._recieptData.mouth;
	data_new._recieptData.year = data_old._recieptData.year;

}
void sortItem(Data* d, int n) { //������� ������ � ������ �������
	system("cls"); //������� �������
	miniSort(); // �������� ����
	Data buf;
	while (tempNum != 0) {
		switch (tempNum)
		{
		case 1: 
			for (int i = 0; i < n; i++) { //��  ��� ��� ���� �� ����������� ������
				for (int j = i + 1; j < n; j++) { // ���������� ������ ��� ��� ������� 
					if (d[i]._magazin.price > d[j]._magazin.price) {
						bubbleCopy(buf, d[j]);
						bubbleCopy(d[j], d[i]); // ��������� �� ������� ������ � ��������� ��� � �������������
						bubbleCopy(d[i], buf);
					}
				}
			}
			
			system("pause"); //�������� ����� ���������
			cout << "������ ���� ������������� �� ����.";
			system("cls"); //������� �������
			miniSort(); 
			break;
		case 2:
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if (d[i]._magazin.number > d[j]._magazin.number) {
						bubbleCopy(buf, d[j]);
						bubbleCopy(d[j], d[i]);
						bubbleCopy(d[i], buf);
					}
				}
			}

			system("pause"); //�������� ����� ���������
			cout << "������ ���� ������������� �� ������.";
			system("cls"); //������� �������
			miniSort();
			break;
		case 3:
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if (d[i]._magazin.nameProduct > d[j]._magazin.nameProduct) {
						bubbleCopy(buf, d[j]);
						bubbleCopy(d[j], d[i]);
						bubbleCopy(d[i], buf);
					}
				}
			}

			system("pause"); //�������� ����� ���������
			cout << "������ ���� ������������� �� ��������.";
			system("cls"); //������� �������
			miniSort();
			break;
		case 4:
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if (d[i]._recieptData.day > d[j]._recieptData.day) {
						bubbleCopy(buf, d[j]);
						bubbleCopy(d[j], d[i]);
						bubbleCopy(d[i], buf);
					}
					if (d[i]._recieptData.mouth > d[j]._recieptData.mouth) {
						bubbleCopy(buf, d[j]);
						bubbleCopy(d[j], d[i]);
						bubbleCopy(d[i], buf);
					}
					if (d[i]._recieptData.year > d[j]._recieptData.year) {
						bubbleCopy(buf, d[j]);
						bubbleCopy(d[j], d[i]);
						bubbleCopy(d[i], buf);
					}
				}
			}

			system("pause"); //�������� ����� ���������
			cout << "������ ���� ������������� �� ��������.";
			system("cls"); //������� �������
			miniSort();
			break;
		default:
			break;
			
		}
	}
}

void searchItem(Data* d, int n) {
	cout << "�������� �� ������ ������ �� ������ ������: " << endl
		<< "(1) �� ����." << endl
		<< "(2) �� ������." << endl   // ���������� �������
		<< "(3) �� ��������." << endl
		<< "(4) �� ���� �����������." << endl
		<< "(0) �����" << endl;
	cin >> tempNum;
	system("cls"); //������� �������
		switch (tempNum)
		{
		case 1:
			int searchPrice;
			int select;
			cout << "������� ����: ";
			cin >> searchPrice;
			cout << endl;
			for (int i = 0; i <= n; i++) {
				if (searchPrice == d[i]._magazin.price) {
					cout << "����� �" << i + 1 << "." << endl;
					cout << "�����-��� ������: " << d[i]._magazin.number << endl;
					cout << "�������� ������: " << d[i]._magazin.nameProduct << endl;
					cout << "������� ��������� ������: " << d[i]._magazin.unit << endl;
					cout << "����: " << d[i]._magazin.price << endl;
					cout << "���� ����������� �/�/�: "
						<< d[i]._recieptData.day << "."
						<< d[i]._recieptData.mouth << "."
						<< d[i]._recieptData.year << endl;

					cout << "(1) �������� ������." << endl
						<< "(0) �����" << endl;
					cin >> select;

					if (select == 1) {
						int data = 0;
						cout << endl;
						cout << "������� �����-��� ������: ";
						cin >> d[i]._magazin.number;
						cout << "������ �������� ������: ";
						cin >> d[i]._magazin.nameProduct;
						cout << "������� ������� ��������� ������: ";
						cin >> d[i]._magazin.unit;
						cout << "������� ����: ";
						cin >> d[i]._magazin.price;
						cout << "������� ���� ����������� � � � ";
						cin >> data;
						if (data <= 31) {
							d[i]._recieptData.day = data;
						} else { cout << "�� ���� ������� ���� EROR"; break;}

						cin >> data;
						if (data <= 12) {
							d[i]._recieptData.mouth = data;
						} else { cout << "�� ���� ������� ����� EROR"; break;}

						cin >> data;
						if (data <= 2021) {
							d[i]._recieptData.year = data;
						} else { cout << "�� ���� ������� ��� EROR"; break;}
					} 
				} else { cout << "����� �� ���� " << searchPrice << " �� ������." << endl; }
			}
			break;
		case 2:

			break;
			default:
			break;
		}
	system("cls"); //������� �������
}
void copy(Data* (&d_n), Data* (&d_o), int n) {
	for (int i = 0; i < n; i++) {
		d_n[i] = d_o[i];
	}
}
void deleteItem(Data* (&d), int& n) {
	n--;
	
	
}