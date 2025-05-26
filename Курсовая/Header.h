#pragma once
#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <algorithm>
#include <string>
#include <clocale>
#include <fstream>

using namespace std;

const int MAX_CANDIDATES = 100;
// Базовый класс с основной информацией
class BaseCandidate {
public:
    string name;
    string data;
    string born;

    BaseCandidate(string n = "", string d = "", string b = "")
        : name(move(n)), data(move(d)), born(move(b)) {}
};

// Класс с доп. информацией о популярности (наследуется от BaseCandidate)
class Candidate : public BaseCandidate {
public:
    int popularity;

    Candidate(string n = "", string d = "", string b = "", int p = 0)
        : BaseCandidate(move(n), move(d), move(b)), popularity(p) {}

    bool operator>(const Candidate& other) const {
        return popularity > other.popularity;
    }
};


void addcandidate();
void deletecandidate();
void show();
void savetofile();    
void loadfromfile();
void sortCandidates();
#endif