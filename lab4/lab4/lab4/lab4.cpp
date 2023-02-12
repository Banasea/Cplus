
#include "Header.h"

int _stateMenu;

void Menu() {
    cout << "(1) Вывод на экран содержимого массива: " << endl
        << "(2) Ввод данных: " << endl
        << "(3) Изменение данных: " << endl
        << "(4) Сортировка данных: " << endl
        << "(5) Поиск данных по определенному критерию: " << endl
        << "(6) Добавить данные: " << endl
        << "(7) Удаление данных: " << endl
        << "(0) Выход: " << endl
        << "Ваш Выбор: ";
    cin >> _stateMenu;
}
int main()
{
    SetConsoleCP(1251); //русификаторы ввода и вывода
    SetConsoleOutputCP(1251);

    DataNew();

    Menu();

    int _actions;
    string fileName;

    while(_stateMenu !=0) 
    {
        switch (_stateMenu)
        {
        case 1:
            system("cls"); // очистка консоли
            DataPrint();
            system("pause"); // задержка
            system("cls"); // очистка консоли
            Menu();
            break;
        case 2:
            system("cls"); // очистка консоли
            cout << "Ввод вручную или из файла?" << endl
                << "(1) Вручную. " << endl
                << "(2) Из файла. " << endl;
            cin >> _actions;
            if (_actions == 1) {
                //ввод вручную
                DataEntry();
            }
            else {
                // чтение из файла 
                cout << "Введите название файла: ";
                cin >> fileName;

                DataRead(fileName);
            }
            system("pause"); // задержка
            system("cls"); // очистка консоли
            Menu();
            break;
        case 3:
            system("cls"); // очистка консоли
            DataChange();
            system("pause"); // задержка
            system("cls"); // очистка консоли
            Menu();
            break;
        case 4:
            system("cls"); // очистка консоли
            sortItem();
            system("pause"); // задержка
            system("cls"); // очистка консоли
            Menu();
            break;
        case 5:
            system("cls"); // очистка консоли
            
            system("pause"); // задержка
            system("cls"); // очистка консоли
            Menu();
            break;
        case 6:
            system("cls"); // очистка консоли
            DataAdd();
            system("pause"); // задержка
            system("cls"); // очистка консоли
            Menu();
            break;
        case 7:
            system("cls"); // очистка консоли
            DataDelete();
            system("pause"); // задержка
            system("cls"); // очистка консоли
            Menu();
            break;
        default:
            break;
        }
    }

    system("cls"); // очистка консоли
    
}

