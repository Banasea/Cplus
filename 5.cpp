// 14)	Характер игры (номер, имя, ник, раса, класс, пол, возраст, количество оружия, уровень)
//создание массива из структур; вывод на экран содержимого массива; добавление данных; изменение данных; сортировка данных; поиск данных по определенному критерию; удаление данных; выход и другие
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

struct Node {
    string name;
    string nick;
    string race;
    string clas;
    string sex;
    string age;
    string weapon_amount;
    string lvl;
    Node* next;
    Node(string _name, string _nick, string _race, string _clas, string _sex, string _age, string _weapon_amount, string _lvl) : name(_name), nick(_nick), race(_race), clas(_clas), sex(_sex), age(_age), weapon_amount(_weapon_amount), lvl(_lvl), next(nullptr) {}
};

struct list {
    Node* first;
    Node* last;

    list() : first(nullptr), last(nullptr) {}

    bool is_empty() {
        return first == nullptr;
    }

    void push_back(string name, string nick, string race, string clas, string sex, string age, string weapon_amount, string lvl) {
        Node* p = new Node(name, nick, race, clas, sex, age, weapon_amount, lvl);
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        p->name = name;
        p->nick = nick;
        p->race = race;
        p->clas = clas;
        p->sex = sex;
        p->age = age;
        p->weapon_amount = weapon_amount;
        p->lvl = lvl;
        last->next = p;
        last = p;
    }

    void print() {
        if (is_empty()) return;
        Node* p = first;
        while (p) {
            cout << "name: " << p->name << endl;
            cout << "nick: " << p->nick << endl;
            cout << "race: " << p->race << endl;
            cout << "class: " << p->clas << endl;
            cout << "sex: " << p->sex << endl;
            cout << "age: " << p->age << endl;
            cout << "weapon amount: " << p->weapon_amount << endl;
            cout << "level: " << p->lvl << endl << endl << endl;
            p = p->next;
        }
        cout << endl;
    }
    Node* find(string name) {
        Node* p = first;
        while (p && p->name != name) p = p->next;
        return (p && p->name == name) ? p : nullptr;
    }

    void remove_first() {
        if (is_empty()) return;
        Node* p = first;
        first = p->next;
        delete p;
    }

    void remove_last() {
        if (is_empty()) return;
        if (first == last) {
            remove_first();
            return;
        }
        Node* p = first;
        while (p->next != last) p = p->next;
        p->next = nullptr;
        delete last;
        last = p;
    }


    void remove(string name) {
        if (is_empty()) return;
        if (first->name == name) {
            remove_first();
            return;
        }
        else if (last->name == name) {
            remove_last();
            return;
        }
        Node* slow = first;
        Node* fast = first->next;
        while (fast && fast->name != name) {
            fast = fast->next;
            slow = slow->next;
        }
        if (!fast) {
            cout << "This element does not exist" << endl;
            return;
        }
        slow->next = fast->next;
        delete fast;
    }

    Node* operator[] (const int index) {
        if (is_empty()) return nullptr;
        Node* p = first;
        for (int i = 0; i < index; i++) {
            p = p->next;
            if (!p) return nullptr;
        }
        return p;
    }
};






list gameRecords;
int amount_of_characters = 0;
string name, nick, race, clas, sex, age, weapon_amount, lvl;

int main()
{

    int sw;
    while (true) {
        cout << "-------MENU-------\n1. Create character\n2. Show all info\n3. Edit\n4. Sort characters by level\n5. Find character by nickname\n6. Delete character\n7. Exit\nInput -> ";
        cin >> sw;
        if (sw < 8 && sw > 0) system("cls");
        switch (sw) {
        case 1: { //create
            cout << "1. Input name: ";
            cin >> name;
            cout << "2. Input nick: ";
            cin >> nick;
            cout << "3. Input race: ";
            cin >> race;
            cout << "4. Input class: ";
            cin >> clas;
            cout << "5. Input sex: ";
            cin >> sex;
            cout << "6. Input age: ";
            cin >> age;
            cout << "7. Input weapon amount: ";
            cin >> weapon_amount;
            cout << "8. Input level: ";
            cin >> lvl;
            gameRecords.push_back(name, nick, race, clas, sex, age, weapon_amount, lvl);
            system("pause");
            break;
        }
        case 2: {
            gameRecords.print();
            system("pause");
            break;
        }
        case 3: { //edit
            string answer;
            string new_value;
            gameRecords.print();
            cout << "\nWho do you want to edit?(enter name) -> ";
            cin >> answer;
            gameRecords.remove(answer);
            cout << "1. Input name: ";
            cin >> name;
            cout << "2. Input nick: ";
            cin >> nick;
            cout << "3. Input race: ";
            cin >> race;
            cout << "4. Input class: ";
            cin >> clas;
            cout << "5. Input sex: ";
            cin >> sex;
            cout << "6. Input age: ";
            cin >> age;
            cout << "7. Input weapon amount: ";
            cin >> weapon_amount;
            cout << "8. Input level: ";
            cin >> lvl;
            gameRecords.push_back(name, nick, race, clas, sex, age, weapon_amount, lvl);
            system("pause");
            break;

        }
        case 4: { //sort
            system("pause");
            break;
        }
        case 5: { //find
            string answer;
            string new_value;
            gameRecords.print();
            cout << "\nWho do you want to find?(enter name) -> ";
            cin >> answer;
            gameRecords.find(answer);
        }
        case 6: { //delete
            string answer;
            string new_value;
            gameRecords.print();
            cout << "\nWho do you want to delete?(enter name) -> ";
            cin >> answer;
            gameRecords.remove(answer);
            break;
        }
        case 7: {
            exit(NULL);
            break;
        }
        default: {
            cout << "Input error!\nRetry input -> ";
            break;
        }
        }
        system("cls");
    }

}
