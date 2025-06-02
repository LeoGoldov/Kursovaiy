// Файл реализации функций
#include "header.h"

Candidate candidates[MAX_CANDIDATES];
int candidates_count = 0;

//Добавление кандидатов
void addcandidate() {
    string surname, name, patronymic, data, born;
    cout << "Введите фамилию кандидата: ";
    cin >> surname;
    cout << "Введите имя кандидата: ";
    cin >> name;
    cout << "Введите отчество кандидата: ";
    cin >> patronymic;
    cout << "Введите дату рождения кандидата: ";
    cin >> data;
    cout << "Введите место рождения кандидата: ";
    cin >> born;

    candidates[candidates_count].setSurname(surname);
    candidates[candidates_count].setName(name);
    candidates[candidates_count].setPatronymic(patronymic);
    candidates[candidates_count].setData(data);
    candidates[candidates_count].setBorn(born);

    cout << "Введите индекс популярности:\n"
        << "1-Поддержан президентом(70%)\n"
        << "2-Поддержан оппозиционной партией(15%)\n"
        << "3-оппозиционный кандидат, который снимет свою кандидатуру в пользу кандидата №1(10%)\n"
        << "4-Прочие(5)\n";
    int indexpopular;
    cin >> indexpopular;

    switch (indexpopular) {
    case 1: candidates[candidates_count].setPopularity(70); break;
    case 2: candidates[candidates_count].setPopularity(15); break;
    case 3: candidates[candidates_count].setPopularity(10); break;
    case 4: candidates[candidates_count].setPopularity(5); break;
    default: cout << "Ошибка" << endl;
    }

    candidates_count++;
    cout << "Кандидат успешно добавлен!" << endl;
}

//Сохранение кандидатов
void savetofile() {
    ofstream file("candidates.txt");

    file << candidates_count << endl;

    for (int i = 0; i < candidates_count; i++) {
        file << candidates[i].getSurname() << endl;
        file << candidates[i].getName() << endl;
        file << candidates[i].getPatronymic() << endl;
        file << candidates[i].getData() << endl;
        file << candidates[i].getBorn() << endl;
        file << candidates[i].getPopularity() << endl;
    }

    cout << "Данные сохранены в файл candidates.txt" << endl;
}

//Удаление кандидатов
void deletecandidate() {
    string surname, name, patronymic;
    cout << "Введите фамилию кандидата для удаления: ";
    cin >> surname;
    cout << "Введите имя кандидата для удаления: ";
    cin >> name;
    cout << "Введите отчество кандидата для удаления: ";
    cin >> patronymic;

    for (int i = 0; i < candidates_count; i++) {
        if (candidates[i].getSurname() == surname &&
            candidates[i].getName() == name &&
            candidates[i].getPatronymic() == patronymic) {
            swap(candidates[i], candidates[candidates_count - 1]);
            candidates_count--;
            cout << "Кандидат успешно удалён!" << endl;
            return;
        }
    }

    cout << "Кандидат с такими ФИО не найден" << endl;
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
        cout << "ФИО кандидата: " << candidates[i].getFullName() << endl;
        cout << "Дата рождения: " << candidates[i].getData() << endl;
        cout << "Место рождения: " << candidates[i].getBorn() << endl;
        cout << "Популярность: " << candidates[i].getPopularity() << endl;
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

    string surname, name, patronymic, data, born;
    int popularity;

    for (int i = 0; i < candidates_count; i++) {
        getline(file, surname);
        getline(file, name);
        getline(file, patronymic);
        getline(file, data);
        getline(file, born);
        file >> popularity;
        file.ignore();

        candidates[i].setSurname(surname);
        candidates[i].setName(name);
        candidates[i].setPatronymic(patronymic);
        candidates[i].setData(data);
        candidates[i].setBorn(born);
        candidates[i].setPopularity(popularity);
    }

    sortCandidates();
    cout << "Данные загружены из файла candidates.txt" << endl;
}

// Сортировка кандидатов по популярности
void sortCandidates() {
    sort(candidates, candidates + candidates_count,
        [](const Candidate& a, const Candidate& b) {
            return a.getPopularity() > b.getPopularity();
        });
}