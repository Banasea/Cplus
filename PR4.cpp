// 14)	Характер игры (номер, имя, ник, раса, класс, пол, возраст, количество оружия, уровень)
//создание массива из структур; вывод на экран содержимого массива; добавление данных; изменение данных; сортировка данных; поиск данных по определенному критерию; удаление данных; выход и другие
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;

struct game {
    int num;
    string name;
    string nick;
    string race;
    string clas;
    string sex;
    string age;
    string weapon_amount;
    string lvl;
};

game gameRecords[11];
int amount_of_characters = 0;

int FileInput() {
    ofstream fout("Heroes.txt");
    fout << amount_of_characters << endl;
    for (int i = 0; i < amount_of_characters; i++) {
        fout << gameRecords[i].num << endl;
        fout << gameRecords[i].name << endl;
        fout << gameRecords[i].nick << endl;
        fout << gameRecords[i].clas << endl;
        fout << gameRecords[i].sex << endl;
        fout << gameRecords[i].age << endl;
        fout << gameRecords[i].weapon_amount << endl;
        fout << gameRecords[i].lvl << endl;
    }
    fout.close(); // закрываем файл
    return 0;
}

int FileOutput() {
    ifstream fin("Heroes.txt");
    fin >> amount_of_characters;
    for (int i = 0; i < amount_of_characters; i++) {
        fin >> gameRecords[i].num;
        fin >> gameRecords[i].name;
        fin >> gameRecords[i].nick;
        fin >> gameRecords[i].clas;
        fin >> gameRecords[i].sex;
        fin >> gameRecords[i].age;
        fin >> gameRecords[i].weapon_amount;
        fin >> gameRecords[i].lvl;
    }
    fin.close();
    return 0;
}

int main()
{
    int sw;
    FileOutput();
    while (true) {
        FileInput();
        cout << "-------MENU-------\n1. Create character\n2. Show all info\n3. Edit\n4. Sort characters by level\n5. Find character by nickname\n6. Delete character\n7. Exit\nInput -> ";
        cin >> sw;
        if (sw < 8 && sw > 0) system("cls");
        switch (sw) {
        case 1: { //create
            if (amount_of_characters == 10) {
                cout << "Error! Maximum amount of characters";
            }
            else {
                gameRecords[amount_of_characters].num = amount_of_characters;
                cout << "1. Input name: ";
                cin >> gameRecords[amount_of_characters].name;
                cout << "2. Input nick: ";
                cin >> gameRecords[amount_of_characters].nick;
                cout << "3. Input race: ";
                cin >> gameRecords[amount_of_characters].race;
                cout << "4. Input class: ";
                cin >> gameRecords[amount_of_characters].clas;
                cout << "5. Input sex: ";
                cin >> gameRecords[amount_of_characters].sex;
                cout << "6. Input age: ";
                cin >> gameRecords[amount_of_characters].age;
                cout << "7. Input weapon amount: ";
                cin >> gameRecords[amount_of_characters].weapon_amount;
                cout << "8. Input level: ";
                cin >> gameRecords[amount_of_characters].lvl;
                amount_of_characters++;
            }
            system("pause");
            break;
        }
        case 2: { //show
            if (amount_of_characters == 0) {
                cout << "Error! Zero characters exists.\nRetry input -> ";
            }
            else {
                cout << "----------------------------------\n";
                for (int i = 0; i < amount_of_characters; i++) {
                    cout << "Character " << gameRecords[i].num + 1 << ":" << endl;
                    cout << "Character's name - " << gameRecords[i].name << endl;
                    cout << "Character's nick - " << gameRecords[i].nick << endl;
                    cout << "Character's class - " << gameRecords[i].clas << endl;
                    cout << "Character's sex - " << gameRecords[i].sex << endl;
                    cout << "Character's age - " << gameRecords[i].age << endl;
                    cout << "Character's weapon amount - " << gameRecords[i].weapon_amount << endl;
                    cout << "Character's level - " << gameRecords[i].lvl << endl;
                    cout << "----------------------------------\n";
                }
                cout << "\n";
            }
            system("pause");
            break;
        }
        case 3: { //edit
            int answer, answer1;
            string new_value;
            cout << "----------------------------------\n";
            for (int i = 0; i < amount_of_characters; i++) {
                cout << i + 1 << ". " << gameRecords[i].nick << endl;
            }
            cout << "----------------------------------";
            cout << "\nWho do you want to edit? -> ";
            cin >> answer;
            while (answer > amount_of_characters) {
                cout << "Error! There are only " << amount_of_characters << " character(s)!\n Try again ->" << endl;
                cin >> answer;
            }
            answer--;
            cout << "\nCharacter " << gameRecords[answer].num + 1 << ":" << endl;
            cout << "1.Character's name - " << gameRecords[answer].name << endl;
            cout << "2.Character's nick - " << gameRecords[answer].nick << endl;
            cout << "3.Character's class - " << gameRecords[answer].clas << endl;
            cout << "4.Character's sex - " << gameRecords[answer].sex << endl;
            cout << "5.Character's age - " << gameRecords[answer].age << endl;
            cout << "6.Character's weapon amount - " << gameRecords[answer].weapon_amount << endl;
            cout << "7.Character's level - " << gameRecords[answer].lvl << endl;
            cout << "What do you want to edit? -> ";
            cin >> answer1;
            cout << "Enter new value -> ";
            cin >> new_value;
            switch (answer1) {
            case 1: gameRecords[answer].name = new_value; break;
            case 2: gameRecords[answer].nick = new_value; break;
            case 3: gameRecords[answer].clas = new_value; break;
            case 4: gameRecords[answer].sex = new_value; break;
            case 5: gameRecords[answer].age = new_value; break;
            case 6: gameRecords[answer].weapon_amount = new_value; break;
            case 7: gameRecords[answer].lvl = new_value; break;
            default: cout << "Input error!\n"; break;
            }
            system("pause");
            break;
        }
        case 4: { //sort
            int arr[10];
            for (int i = 0; i < amount_of_characters; i++) {
                arr[i] = i;
            }
            for (int i = 0; i < amount_of_characters; i++) {
                for (int j = 0; j < amount_of_characters - 1; j++) {
                    if (stoi(gameRecords[arr[j]].lvl) < stoi(gameRecords[arr[j + 1]].lvl)) {
                        int b = arr[j]; // создали дополнительную переменную
                        arr[j] = arr[j + 1]; // меняем местами
                        arr[j + 1] = b; // значения элементов
                    }
                }
            }
            cout << "----------------------------------\n";
            for (int i = 0; i < amount_of_characters; i++) {
                cout << "Character's level - " << gameRecords[arr[i]].lvl << endl;
                cout << "Character " << gameRecords[arr[i]].num + 1 << ":" << endl;
                cout << "Character's name - " << gameRecords[arr[i]].name << endl;
                cout << "Character's nick - " << gameRecords[arr[i]].nick << endl;
                cout << "Character's class - " << gameRecords[arr[i]].clas << endl;
                cout << "Character's sex - " << gameRecords[arr[i]].sex << endl;
                cout << "Character's age - " << gameRecords[arr[i]].age << endl;
                cout << "Character's weapon amount - " << gameRecords[arr[i]].weapon_amount << endl;
                cout << "----------------------------------\n";
            }
            system("pause");
            break;
        }
        case 5: { //find
            string find_nick;
            bool flag = false;
            cout << "Input nick: ";
            cin >> find_nick;
            cout << "----------------------------------\n";
            for (int i = 0; i < amount_of_characters; i++) {
                if (find_nick == gameRecords[i].nick) {
                    if (amount_of_characters == 0) {
                        cout << "Error! Zero characters exists.\nRetry input -> ";
                    }
                    else {
                        cout << "Character " << gameRecords[i].num + 1 << ":" << endl;
                        cout << "Character's name - " << gameRecords[i].name << endl;
                        cout << "Character's nick - " << gameRecords[i].nick << endl;
                        cout << "Character's class - " << gameRecords[i].clas << endl;
                        cout << "Character's sex - " << gameRecords[i].sex << endl;
                        cout << "Character's age - " << gameRecords[i].age << endl;
                        cout << "Character's weapon amount - " << gameRecords[i].weapon_amount << endl;
                        cout << "Character's level - " << gameRecords[i].lvl << endl;
                        cout << "----------------------------------\n";
                        cout << "\n";
                        flag = true;
                    }
                }
            }
            if (flag == false) { cout << "There are no players with this nickname." << endl; }
            system("pause");
            break;
        }
        case 6: { //delete
            int answer;
            cout << "----------------------------------\n";
            for (int i = 0; i < amount_of_characters; i++) {
                cout << i + 1 << ". " << gameRecords[i].nick << endl;
            }
            cout << "----------------------------------";
            cout << "\nWho do you want to delete? -> ";
            cin >> answer;
            answer--;
            for (int i = answer; i < amount_of_characters - 1; i++) {
                gameRecords[i] = gameRecords[i + 1];
                gameRecords[i].num--;
            }
            amount_of_characters--;
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
