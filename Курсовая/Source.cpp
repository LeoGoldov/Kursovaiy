#include "Header.h"

Candidate candidates[MAX_CANDIDATES];
int candidates_count = 0;

//Добавление кандидатов
void addcandidate() {
    if (candidates_count >= MAX_CANDIDATES) {
        cout << "Достигнуто максимальное количество кандидатов!\n";
        return;
    }
    cout << "Введите имя кандидата: ";
    cin >> candidates[candidates_count].name;
    cout << "Введите дату рождения кандидата: ";
    cin >> candidates[candidates_count].data;
    cout << "Введите место рождения кандидата: ";
    cin >> candidates[candidates_count].born;
    cout << "Введите индекс популярности:\n" << "1-Поддержан президентом(70%)\n" << "2-Поддержан оппозиционной партией(15%)\n" <<
        "3-оппозиционный кандидат, который снимет свою кандидатуру в пользу кандидата №1(10%)\n" << "4-Прочие(5)\n";
    int indexpopular;
    cin >> indexpopular;
    switch (indexpopular) {
    case 1:candidates[candidates_count].popularity = 70; break;
    case 2:candidates[candidates_count].popularity = 15; break;
    case 3:candidates[candidates_count].popularity = 10; break;
    case 4:candidates[candidates_count].popularity = 5; break;
    default: cout << "Ошибка" << endl;
    }
    candidates_count++;
    cout << "Кандидат успешно добавлен!" << endl;
}

//Сохранение кандидатов
void savetofile() {
    ofstream file("candidates.txt");
    if (!file) {
        cout << "Ошибка при создании файла!" << endl;
        return;
    }

    // Записываем количество кандидатов
    file << candidates_count << endl;

    // Записываем данные каждого кандидата
    for (int i = 0; i < candidates_count; i++) {
        file << candidates[i].name << endl;
        file << candidates[i].data << endl;
        file << candidates[i].born << endl;
        file << candidates[i].popularity << endl;
    }

    cout << "Данные сохранены в файл candidates.txt" << endl;
}

//Удаление кандидатов
void deletecandidate() {
    string name;
    cout << "Введите имя кандидата для удаления: ";
    cin >> name;

    for (int i = 0; i < candidates_count; i++) {
        if (candidates[i].name == name) {
            swap(candidates[i], candidates[candidates_count - 1]);
            candidates_count--;
            cout << "Кандидат успешно удалён!" << endl;
            return;
        }
    }

    cout << "Кандидат с таким именем не найден" << endl;
}

//Вывод списка
void show() {
    if (candidates_count == 0) {
        cout << "Список кандидатов пуст:" << endl;
        return;
    }

    sortCandidates();

    cout << "Список кандидатов (по популярности):" << endl;
    cout << "----------------------------------" << endl;
    for (int i = 0; i < candidates_count; i++) {
        cout << "Имя кандидата: " << candidates[i].name << endl;
        cout << "Место рождения кандидата:" << candidates[i].data << endl;
        cout << "Место рождения: " << candidates[i].born << endl;
        cout << "Популярность: " << candidates[i].popularity <<endl;
        cout << "----------------------------------" << endl;
    }
}

//Загрузка файлов
void loadfromfile() {
    ifstream file("candidates.txt");
    if (!file) {
        cout << "Файл не найден, будет создан новый." << endl;
        return;
    }

   
    file >> candidates_count;
    file.ignore(); 

    // Считываем данные каждого кандидата
    for (int i = 0; i < candidates_count; i++) {
        getline(file, candidates[i].name);
        getline(file, candidates[i].data);
        getline(file, candidates[i].born);
        file >> candidates[i].popularity;
        file.ignore(); 
    }

    sortCandidates();

    cout << "Данные загружены из файла candidates.txt" << endl;
}
// Сортировка кандидатов по популярности
void sortCandidates() {
    sort(candidates, candidates + candidates_count,
        [](const Candidate& a, const Candidate& b) {
            return a.popularity > b.popularity;
        });
}