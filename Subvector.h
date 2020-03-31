//
// Created by david on 31.03.2020.
//

#ifndef UNTITLED_SUBVECTOR_H
#define UNTITLED_SUBVECTOR_H


#include <iostream>
using namespace std;

class Subvector
{
private:
    double *mas;    // Указатель на первый элемент вектора (динамического массива)

    unsigned int top;   // Количество элементов вектора

    unsigned int capacity;  // Размер (вместительность) вектора

public:
    Subvector();    // Конструктор недовектора

    ~Subvector();   // Деструктор

    bool push_back(double d);   // Добавление элемента в конец

    int pop_back(); // Вывод элемента из конца

    bool resize(unsigned int new_capacity); // Изменить размер массива

    void shrink_to_fit();   // Удалить свободные ячейки
};


#endif //UNTITLED_SUBVECTOR_H
