// Заголовочный файл header.h
#pragma once
#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

const int MAX_CANDIDATES = 100;

//класс с основной информацией
class BaseCandidate {
private:
    string surname;
    string name;
    string patronymic;
    string data;
    string born;

public:
    BaseCandidate(string s = "", string n = "", string p = "", string d = "", string b = "")
        : surname(move(s)), name(move(n)), patronymic(move(p)), data(move(d)), born(move(b)) {}

    // Геттеры
    string getSurname() const { return surname; }
    string getName() const { return name; }
    string getPatronymic() const { return patronymic; }
    string getFullName() const { return surname + " " + name + " " + patronymic; }
    string getData() const { return data; }
    string getBorn() const { return born; }

    // Сеттеры
    void setSurname(const string& s) { surname = s; }
    void setName(const string& n) { name = n; }
    void setPatronymic(const string& p) { patronymic = p; }
    void setData(const string& d) { data = d; }
    void setBorn(const string& b) { born = b; }
};

// Класс информацией о популярности (наследование)
class Candidate : public BaseCandidate {
private:
    int popularity;

public:
    Candidate(string s = "", string n = "", string p = "", string d = "", string b = "", int pop = 0)
        : BaseCandidate(move(s), move(n), move(p), move(d), move(b)), popularity(pop) {}

    // Геттеры
    int getPopularity() const { return popularity; }

    // Сеттеры
    void setPopularity(int p) { popularity = p; }

    bool operator>(const Candidate& other) const {
        return popularity > other.popularity;
    }
};

// Объявления функций
void addcandidate();
void deletecandidate();
void show();
void savetofile();
void loadfromfile();
void sortCandidates();

#endif