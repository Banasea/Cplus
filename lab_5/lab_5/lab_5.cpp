#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

/*СТРУКТУРА СТУДЕНТ*/
struct Student
{
    char FullName[30];             // Имя и Фамилия
    int course;                    // Курс
    char academ_perf[30];          // Успеваемость

    void Input(Student& student);  //Функция ввода данных в структуру
    Student* Next;                 //Адрес на следующий элемент

    void Print();
};

class List
{
    Student* Head;                  // Указатель на начало списка
public:
    List() :Head(NULL) {};            // Конструктор по умолчанию (Head=NULL).
    ~List();                        // Прототип деструктора.
    void Add(Student& student);     // Прототип функции добавления 
                                    // элемента в список.
    void Show();                    // Прототип функции вывода списка
                                    // на экран.
    Student* SearchStudent(char* Name);           // Прототип функции поиска студента.
};

/*ФУНКЦИЯ ЗАПОЛНЕНИЯ ДАННЫХ ПО СТУДЕНТУ*/
void Student::Input(Student& student)
{
    cout << endl;
    cout << "Имя и Фамилия: ";
    cin.getline(FullName, 30);              //Ввод Имени и Фамилии.
    cout << "Курс: ";
    cin >> course;                          //Ввод курса.
    cin.ignore();                           //Игнорируем символ.
    cout << "Успеваемость: ";
    cin.getline(academ_perf, 30);           //Ввод оценки.
}

List::~List()                               // Деструктор класса List.
{
    while (Head != NULL)                // Пока по адресу есть хоть.
                                        // что-то.
    {
        Student* temp = Head->Next;     // Сразу запоминаем указатель
                                        // на адрес следующего элемента структуры.
        delete Head;                    // Освобождаем память по месту начала списка.
        Head = temp;                    // Меняем адрес начала списка.
    }
}

/*ФУНКЦИЯ ДОБАВЛЕНИЯ НОВОЙ СТРУКТУРЫ В СПИСОК*/
void List::Add(Student& student)
{
    Student* temp = new Student;   // Выделение памяти под новую структуру.
    temp->Next = Head;           // Указываем, что адрес следующего
                                   // элемента это начало списка.

//Копирование содержимого параметра student в только что созданную переменную.
    temp->FullName, student.FullName;
    temp->course = student.course;
    temp->academ_perf, student.academ_perf;

    Head = temp;                   //Смена адреса начала списка.
}
// Поиск компонента в списке по имени
Student* List::SearchStudent(char* Name)
{
    Student* temp = Head;
    while (temp != NULL)
    {
        if (!strcmp(temp->FullName, Name)) return temp;
        temp = temp->Next;
        //cout << temp;
    }
    return temp;
}

/*ФУНКЦИЯ КЛАССА LIST ДЛЯ ВЫВОДА СПИСКА НА ЭКРАН*/
void List::Show()
{
    Student* temp = Head;           // Объявляем указатель и
                                    // изначально он указывает на начало.

    while (temp != NULL)            // Пока по адресу на начало
                                    // хоть что-то есть.
    {
        temp->Print();
        temp = temp->Next;      //Указываем на следующий адрес из списка.
    }
    cout << endl;
}

void Student::Print()
{
    //Выводим все элементы структуры
    cout << FullName << "\t\t";  //Вывод имени.
    cout << course << "\t\t";    //Вывод курса.
    cout << academ_perf << endl; //Вывод успеваемости.
}

int main()
{
    setlocale(LC_ALL, "Russian");

    char Name[30];
    Student student;          // Объявили переменную, тип которой Студент.
    int N;                    // Объявили переменную выбора.
    List lst;                 // Объявили переменную типа Список
                              // Она выступает как контейнер данных.
    while (1)
    {
        cout << endl;
        cout << "Что требуется сделать?" << endl;
        cout << "1. Добавить студента;" << endl;
        cout << "2. Показать студентов;" << endl;
        cout << "3. Найти студента;" << endl;
        cout << "4. Найти студента по успеваемости: " << endl;
        cout << "5. Выход" << endl;
        cout << "Введите цифру: ";
        cin >> N;
        cin.ignore();                    //Игнорируем клавишу Enter

        if (N == 1)
        {
            student.Input(student);      // Передаем в функцию заполнения
                                         // переменную студент.
            lst.Add(student);            // Добавляем заполненную структуру
                                         // в список.
        }
        if (N == 2)
        {
            cout << endl;
            lst.Show();                  //Показываем список на экране.
        }
        if (N == 3)
        {
            cout << endl;
            cout << "Введите имя: ";
            cin >> Name;

            lst.SearchStudent(Name)->Print();

        }
        if (N == 5)
        {
            break;                        // Выход из цикла.
        }
    }

    //  system("pause");
    return 0;
}