//
// Created by david on 31.03.2020.
//

#include "Subvector.h"

using namespace std;


Subvector::Subvector()
{
    mas=NULL;
    top=0;
    capacity=0;
}

Subvector::~Subvector()
{
    double* p;
    p=new double[0];
    for (int i=0; i<capacity; i++) {
        delete(&(mas[i]));
    }
    mas=p;
    capacity=0;
    top=0;
}

bool Subvector::push_back(double d)
{
    double* q;
    if (capacity > top)
    {
        mas[top]=d;
        top++;
    }
    else
    {
        q=new double[(capacity)+1];
        capacity++;
        top++;
        q[top]=d;
        for (int i=0; i<capacity; i++)
        {
            q[i]=mas[i];
        }
        mas=q;
    }
    return true;
}

int Subvector::pop_back()
{
    double y=mas[top-1];
    delete(&(mas[top-1]));
    top--;
    capacity--;
    return y;
}

bool Subvector::resize(unsigned int new_capacity) {
    capacity=capacity+new_capacity;
    double * p;
    p=new double[capacity+new_capacity];
    for (int i=0; i < top; i++) {
        p[i]=mas[i];
    }
    mas=p;
    return true;
}

void Subvector::shrink_to_fit() {
    for (int i=top; i<capacity; i++) {
        delete(&(mas[i]));
    }
    capacity=top;
}