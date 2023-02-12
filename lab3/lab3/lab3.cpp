#include "Header.h"

int _stateMenu;

void Menu() {
    cout << "(1) Вывод на экран содержимого массива: " << endl
        << "(2) Добавление данных: " << endl
        << "(3) Изменение данных: " << endl
        << "(4) Сортировка данных: " << endl
        << "(5) Поиск данных по определенному критерию: " << endl
        << "(6) Удаление данных: " << endl
        << "(0) Выход: " << endl
        << "Ваш Выбор: ";
        cin >> _stateMenu;
}
int main()
{
   
    SetConsoleCP(1251); //русификаторы ввода и вывода
    SetConsoleOutputCP(1251); 

    //Инициализация данных
    int _actions,
        amouthData = 0;
    string fileName;
    //Массив данных
    Data* d = new Data[amouthData]; //указываю ссылку, инициализация данных динамическое распределение памяти

    setlocale(LC_ALL, "rus");
    Menu(); //меню для отслешки состояния его создал свич с кейсами
    while (_stateMenu != 0) {
        switch (_stateMenu)
        {
        case 1: //вывод на экран
            system("cls"); //очистка консоли
            if (amouthData != 0) {
                showBase(d, amouthData);
                system("pause"); //задержка чтобы прочитать
            }
            else{ 
                cout << "Данные пусты " << endl; 
                system("pause"); //задержка чтобы прочитать
            }
            system("cls"); //очистка консоли
            Menu();
            break;
        case 2: //запись данных
            system("cls"); //очистка консоли
            dataEntry(d, amouthData);
            Menu();
            break;
        case 3:
            system("cls"); //очистка консоли
            if (amouthData != 0) {
                reName(d, amouthData);
            }
            else {
                cout << "Данные пусты " << endl;
                system("pause"); //задержка чтобы прочитать
                system("cls"); //очистка консоли
            }
            Menu();
            break;
        case 4: 
            system("cls"); //очистка консоли
            sortItem(d, amouthData);
            Menu();
            break;
        case 5:
            system("cls"); //очистка консоли
            searchItem(d, amouthData);
            Menu();
            break;
        case 6:
            system("cls"); //очистка консоли
            if (amouthData != 0) {
                deleteItem(d, amouthData);
                system("pause"); //задержка чтобы прочитать
            }
            else {
                cout << "Данные пусты " << endl;
                system("pause"); //задержка чтобы прочитать
            }
            system("cls"); //очистка консоли
            Menu();
            break;
        default:
            break;
        }
    }

}

