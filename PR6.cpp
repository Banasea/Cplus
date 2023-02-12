#include <iostream>
#include <string>
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

class Game {
    int num;
    string name;
    string nick;
    string race;
    string clas;
    string sex;
    string age;
    string weapon_amount;
    string lvl;
public:
    Game() {
        this->num = -1;
        this->name = "NOINFO";
        this->nick = "NOINFO";
        this->race = "NOINFO";
        this->clas = "NOINFO";
        this->sex = "NOINFO";
        this->age = "-1";
        this->weapon_amount = "-1";
        this->lvl = "-1";
    }
    Game(int num, string name, string mick, string race, string clas, string sex, string age, string weapon, string lvl) {
        this->num = num;
        this->name = name;
        this->nick = mick;
        this->race = race;
        this->clas = clas;
        this->sex = sex;
        this->age = age;
        this->weapon_amount = weapon;
        this->lvl = lvl;
    }
    //конструктор для создания записи без класса
    Game(int num, string name, string mick) {
        this->num = num;
        this->name = name;
        this->nick = mick;
        this->race = "NOINFO";
        this->clas = "NOINFO";
        this->sex = "NOINFO";
        this->age = "-1";
        this->weapon_amount = "-1";
        this->lvl = "-1";
    }
    //функции возврата значений
    int rNum() {
        return this->num;
    }
    string rNick() {
        return this->nick;
    }
    string rRace() {
        return this->race;
    }
    string rClas() {
       return  this->clas;
    }
    string rSex() {
        return this->sex;
    }
    string rAge() {
       return this->age;
    }
    string rWeapon_amount() {
        return this->weapon_amount;
    }
    string rLvl() {
        return this->lvl;
    }
    string rName() {
        return this->name;
    }
    void showName() {
        cout << this->name << endl;
    }
    void showNick() {
        cout << this->nick << endl;
    }
    void showRace() {
        cout << this->race << endl;
    }
    void showClas() {
        cout << this->clas << endl;
    }
    void showSex() {
        cout << this->sex << endl;
    }
    void showAge() {
        cout << this->age << endl;
    }
    void showWeapon_amount() {
        cout << this->weapon_amount << endl;
    }
    void showLvl() {
        cout << this->lvl << endl;
    }
    void showNum() {
        cout << this->num << endl;
    }
    int ExpAmount() {
        int exp = -1;
        exp = stoi(lvl) * 1000;
        return exp;
    }
    //1 истина 0 ложь
    int operator==(Game a) {
        if (this->race==a.rRace()) {
            return 1;
        }
        return 0;
    }
    void operator+(int a) {
        int buf=stoi(this->lvl);
        buf = buf + a;
        this->lvl = to_string(buf);
    }
 };

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Game obj1, obj2(123,"3 параметра","ЭтоНик"), obj3(4328,"Имя","Ник","Раса","Класс","Пол","37","69","40");
    cout << "--------------------------------------------------------------------------" << endl;

    cout << "Вывод объекта без параметров" << endl;
    cout << "Номер:";
    obj1.showNum();
    cout << "Имя:";
    obj1.showName();
    cout << "Ник:";
    obj1.showNick();
    cout << "Раса:";
    obj1.showRace();
    cout << "Класс:";
    obj1.showClas();
    cout << "Пол:";
    obj1.showSex();
    cout << "Возраст:";
    obj1.showAge();
    cout << "Колво оружия:";
    obj1.showWeapon_amount();
    cout << "ЛВЛ:";
    obj1.showLvl();
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "Вывод объекта с неполными параметрами" << endl;
    cout << "Номер:";
    obj2.showNum();
    cout << "Имя:";
    obj2.showName();
    cout << "Ник:";
    obj2.showNick();
    cout << "Раса:";
    obj2.showRace();
    cout << "Класс:";
    obj2.showClas();
    cout << "Пол:";
    obj2.showSex();
    cout << "Возраст:";
    obj2.showAge();
    cout << "Колво оружия:";
    obj2.showWeapon_amount();
    cout << "ЛВЛ:";
    obj2.showLvl();
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "Вывод объекта со всеми параметрами" << endl;
    cout << "Номер:";
    obj2.showNum();
    cout << "Имя:";
    obj2.showName();
    cout << "Ник:";
    obj2.showNick();
    cout << "Раса:";
    obj2.showRace();
    cout << "Класс:";
    obj2.showClas();
    cout << "Пол:";
    obj2.showSex();
    cout << "Возраст:";
    obj2.showAge();
    cout << "Колво оружия:";
    obj2.showWeapon_amount();
    cout << "ЛВЛ:";
    obj2.showLvl();
    system("pause");
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "Проверим работу перегруженного оператора ==" << endl << "Сверим 3 объект и 2 должно вывести 0" << endl;
    if ((obj2 == obj3) == 0) {
        cout << "Объекты не равны" << endl;
    }
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "Проверим работу перегруженного оператора +" << endl << "Сложим объект 3 с числом 10, должно получится лвл 50" << endl;
    obj3.showLvl();
    obj3 + 10;
    obj3.showLvl();
    cout << "Верно" << endl;


}