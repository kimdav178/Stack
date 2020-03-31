//
// Created by david on 31.03.2020.
//

#ifndef UNTITLED_SUBFORWARDLIST2_H
#define UNTITLED_SUBFORWARDLIST2_H

#include <iostream>
using namespace std;

class Subforwardlist2 {
protected:
    double data;
    Subforwardlist2 *next;
public:
    Subforwardlist2();

    ~Subforwardlist2();

    double getData();

    void setData(double d);

    Subforwardlist2* getNext();

    void setNext(Subforwardlist2* t);

    bool push_back(double d);

    int pop_back();

    bool push_forward(double d);

    int pop_forward();

    bool push_where(unsigned int where, double d);

    bool erase_where (unsigned int d);

    unsigned int size ();

    void clear();
};


#endif //UNTITLED_SUBFORWARDLIST2_H
