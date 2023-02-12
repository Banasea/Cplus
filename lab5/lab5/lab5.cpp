#include "Header.h"



int main()
{
    setlocale(LC_ALL, "ru");

    Magazin<int> lst;
    //lst.push_back(5);
    lst.push_back(2);
    lst.delete_back();
}

