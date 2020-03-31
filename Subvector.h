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
    double *mas;
    unsigned int top;
    unsigned int capacity;
public:
    Subvector();
    ~Subvector();
    bool push_back(double d);
    int pop_back();
    bool resize(unsigned int new_capacity);
    void shrink_to_fit();
    void clear();
};


#endif //UNTITLED_SUBVECTOR_H
