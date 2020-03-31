//
// Created by david on 31.03.2020.
//

#ifndef UNTITLED_SUBFORWARDLIST2_H
#define UNTITLED_SUBFORWARDLIST2_H

#include <iostream>
using namespace std;

class Subforwardlist {
protected:
    double data;    // Хранит значение элемента списка

    Subforwardlist *next;   // Указатель на следующий элемент списка

public:
    Subforwardlist();   // Конструктор односвязного списка

    ~Subforwardlist();  // Деструктор

    double getData();   // Возвращет значение поля data

    void setData(double d); // Устанавливает значение поля data

    Subforwardlist* getNext();  // Возвращает указатель next

    void setNext(Subforwardlist* t);    // Устанавливает область, на которую указывает next

    bool push_back(double d);   // Добавление элемента в конец

    int pop_back(); // Вывод последнего элемента из списка

    bool push_forward(double d);    // Добавление элемента в начало

    int pop_forward();  // Вывод первого элемента

    bool push_where(unsigned int where, double d);  // Добавление элемента на заданную позицию

    bool erase_where (unsigned int d);  // Удаление элемента с заданной позиции

    unsigned int size ();   // Возвращает размер списка
};


#endif //UNTITLED_SUBFORWARDLIST2_H
