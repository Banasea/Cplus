
#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    SetConsoleCP(1251); //русификаторы ввода и вывода
    SetConsoleOutputCP(1251);


    setlocale(LC_ALL, "rus");
    cout << "Напишите текст: "; /*Оформление*/
    string str;
    getline(cin, str); /*Записал введенный текст*/
    int n = 'а'; /*Поиск буквы 'a'*/
    int value = 0;

    for (int i = 0; i < str.size(); i++)
        if (str[i] == n)
        {
            value++;
            
        }
    if (value > 0) {
        cout << "Найдена буква 'a'" << endl;
        cout << "Количество: " << value;
    }
    else {
        cout << "Буква 'a' не найдена. ";
    } 
  
}

