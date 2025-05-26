#include "header.h"
int main() {
    
    setlocale(LC_ALL, "RU");// использование русского языка
    system("chcp 1251");
   
    loadfromfile();
    
    while (true) {
        cout << "--------------------------------" << endl;
        cout << "   |Программа ВыборАналитика|" << endl;
        cout << "--------------------------------" << endl;
        cout << "Меню управления кандидатами:" << endl;
        cout << "1. Добавить кандидата" << endl;
        cout << "2. Удалить кандидата" << endl;
        cout << "3. Показать список" << endl;
        cout << "4. Сохранить в файл" << endl;       
        cout << "5. Выход" << endl;
        cout << "Выберите действие: " << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: addcandidate(); break;
        case 2: deletecandidate(); break;
        case 3: show(); break;
        case 4: savetofile(); break;       
        case 5: return 0;
        default: cout << "Ошибка: неверный пункт меню!" << endl;
        }
    }
}