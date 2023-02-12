#include "Header.h"

void showBase(Data* d, int n) { // Вывод на экран содержимого массива
	for (int i = 0; i < n; i++) {
		cout << "Товар №" << i + 1<< "." << endl;

		cout << "Штрих-код товара: " << d[i]._magazin.number<< endl;
		cout << "Название товара: " << d[i]._magazin.nameProduct << endl;
		cout << "Единица измерения товара: " << d[i]._magazin.unit << endl;
		cout << "Цена: " << d[i]._magazin.price << endl;
		cout << "Дата поступления д/м/г: " << d[i]._recieptData.day 
			<< "." << d[i]._recieptData.mouth 
			<< "." << d[i]._recieptData.year << endl;
		cout << endl;

	}
}
void dataEntry(Data* (&d)/*сылка на масив*/, int& n) { // Добавление данных
	cout << "Введите количество товаров: ";
	cin >> n;
	//Выделяю память
	d = new Data[n];
	if (n > 0) {
		for (int i = 0; i < n; i++)
		{
			int num = 0;
			cout << endl;
			cout << "Введите штрих-код товара: " ;
			cin >> d[i]._magazin.number;
			cout << "Ведите название товара: ";
			cin >> d[i]._magazin.nameProduct;
			cout << "Введите единица измерения товара: ";
			cin >> d[i]._magazin.unit;
			cout << "Введите цену: " ;
			cin >> d[i]._magazin.price;
			cout << "Введите дату поступления д м г ";
			cin >> num;
			if (num <= 31) {
				d[i]._recieptData.day = num;
			}
			else {
				cout << "Вы вели неверно день EROR";
				system("pause"); //задержка чтобы прочитать	
			}
			cin >> num;
				if (num <= 12) {
					d[i]._recieptData.mouth = num;
				}
				else {
					cout << "Вы вели неверно день EROR";
					system("pause"); //задержка чтобы прочитать
				}
		    cin >> num;
				if (num <= 2021) {
					d[i]._recieptData.year = num;
				}
				else {
					cout << "Вы вели неверно день EROR";
					system("pause"); //задержка чтобы прочитать					
				}
			cout << endl;
			cout << "_________Товар был добавлен_________" << endl;
			system("pause"); //задержка чтобы прочитать
			system("cls"); //очистка консоли
			
		}
	}
	else
	{
		cout << "Ошибка 404" << endl;
		system("pause"); //задержка чтобы прочитать
		system("cls"); //очистка консоли
		
	}
}

void reName(Data* d, int n) { // Изменение данных
		for (int i = 0; i < n; i++) {
			cout << "Номер " << i + 1 << "." << endl;
			cout << "Название товара: " << d[i]._magazin.nameProduct << endl;
		}
		cout << "Введите № товара: " << endl;
		cin >> n;
		n--;

		int num = 0;
		if (n >= 0 ) {
			cout << "Введите штрих-код товара: ";
			cin >> d[n]._magazin.number;
			cout << "Ведите название товара: ";
			cin >> d[n]._magazin.nameProduct;
			cout << "Введите единица измерения товара: ";
			cin >> d[n]._magazin.unit;
			cout << "Введите цену: ";
			cin >> d[n]._magazin.price;
			cout << "Введите дату поступления д м г: ";
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
			cout << "_________Товар был добавлен_________" << endl;
			system("pause"); //задержка чтобы прочитать
			system("cls"); //очистка консоли
		}
		else
		{
			cout << "Eror 404";
			system("pause"); //задержка чтобы прочитать
			system("cls"); //очистка консоли
		}

		
}
int tempNum; // мини меню будет в сортировке
void miniSort() {
	cout << "Выберите по какому пункту вы хотите сортировать: " << endl
		<< "(1) По цене." << endl
		<< "(2) По номеру." << endl   // оформление немного
		<< "(3) По названию." << endl
		<< "(4) По дате поступления."<< endl 
		<< "(0) Выход" << endl;
	cin >> tempNum;
	system("cls"); //очистка консоли;
}
void bubbleCopy(Data& data_new, Data& data_old) { //присваиваю старые данные к новым.
	data_new._magazin.number = data_old._magazin.number;
	data_new._magazin.nameProduct = data_old._magazin.nameProduct;
	data_new._magazin.unit = data_old._magazin.unit;
	data_new._magazin.price = data_old._magazin.price;

	data_new._recieptData.day = data_old._recieptData.day;
	data_new._recieptData.mouth = data_old._recieptData.mouth;
	data_new._recieptData.year = data_old._recieptData.year;

}
void sortItem(Data* d, int n) { //передаю данные и создаю функцию
	system("cls"); //очистка консоли
	miniSort(); // открываю меню
	Data buf;
	while (tempNum != 0) {
		switch (tempNum)
		{
		case 1: 
			for (int i = 0; i < n; i++) { //до  тех пор пока не закончаться масивы
				for (int j = i + 1; j < n; j++) { // сравниваем каждый раз при запуске 
					if (d[i]._magazin.price > d[j]._magazin.price) {
						bubbleCopy(buf, d[j]);
						bubbleCopy(d[j], d[i]); // прохожусь по каждому масиву и сравниваю его и перезаписываю
						bubbleCopy(d[i], buf);
					}
				}
			}
			
			system("pause"); //задержка чтобы прочитать
			cout << "Товары были отсортированы по цене.";
			system("cls"); //очистка консоли
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

			system("pause"); //задержка чтобы прочитать
			cout << "Товары были отсортированы по номеру.";
			system("cls"); //очистка консоли
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

			system("pause"); //задержка чтобы прочитать
			cout << "Товары были отсортированы по названию.";
			system("cls"); //очистка консоли
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

			system("pause"); //задержка чтобы прочитать
			cout << "Товары были отсортированы по названию.";
			system("cls"); //очистка консоли
			miniSort();
			break;
		default:
			break;
			
		}
	}
}

void searchItem(Data* d, int n) {
	cout << "Выберите по какому пункту вы хотите искать: " << endl
		<< "(1) По цене." << endl
		<< "(2) По номеру." << endl   // оформление немного
		<< "(3) По названию." << endl
		<< "(4) По дате поступления." << endl
		<< "(0) Выход" << endl;
	cin >> tempNum;
	system("cls"); //очистка консоли
		switch (tempNum)
		{
		case 1:
			int searchPrice;
			int select;
			cout << "Введите цену: ";
			cin >> searchPrice;
			cout << endl;
			for (int i = 0; i <= n; i++) {
				if (searchPrice == d[i]._magazin.price) {
					cout << "Товар №" << i + 1 << "." << endl;
					cout << "Штрих-код товара: " << d[i]._magazin.number << endl;
					cout << "Название товара: " << d[i]._magazin.nameProduct << endl;
					cout << "Единица измерения товара: " << d[i]._magazin.unit << endl;
					cout << "Цена: " << d[i]._magazin.price << endl;
					cout << "Дата поступления д/м/г: "
						<< d[i]._recieptData.day << "."
						<< d[i]._recieptData.mouth << "."
						<< d[i]._recieptData.year << endl;

					cout << "(1) Изменить данные." << endl
						<< "(0) Выход" << endl;
					cin >> select;

					if (select == 1) {
						int data = 0;
						cout << endl;
						cout << "Введите штрих-код товара: ";
						cin >> d[i]._magazin.number;
						cout << "Ведите название товара: ";
						cin >> d[i]._magazin.nameProduct;
						cout << "Введите единица измерения товара: ";
						cin >> d[i]._magazin.unit;
						cout << "Введите цену: ";
						cin >> d[i]._magazin.price;
						cout << "Введите дату поступления д м г ";
						cin >> data;
						if (data <= 31) {
							d[i]._recieptData.day = data;
						} else { cout << "Вы вели неверно день EROR"; break;}

						cin >> data;
						if (data <= 12) {
							d[i]._recieptData.mouth = data;
						} else { cout << "Вы вели неверно месяц EROR"; break;}

						cin >> data;
						if (data <= 2021) {
							d[i]._recieptData.year = data;
						} else { cout << "Вы вели неверно год EROR"; break;}
					} 
				} else { cout << "Товар по цене " << searchPrice << " не найден." << endl; }
			}
			break;
		case 2:

			break;
			default:
			break;
		}
	system("cls"); //очистка консоли
}
void copy(Data* (&d_n), Data* (&d_o), int n) {
	for (int i = 0; i < n; i++) {
		d_n[i] = d_o[i];
	}
}
void deleteItem(Data* (&d), int& n) {
	n--;
	
	
}