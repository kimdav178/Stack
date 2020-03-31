//
// Created by david on 31.03.2020.
//

#include "Subforwardlist2.h"

using namespace std;

Subforwardlist2::Subforwardlist2()
{
    data = 0;
    next = NULL;
}

Subforwardlist2::~Subforwardlist2()
{
    if (this == NULL)
    {
        return;
    }
    Subforwardlist2 **t = new Subforwardlist2*;
    *t = this;
    while (*t != NULL)
    {
        *t=(*t)->getNext();
    }
    delete t;
    this->~Subforwardlist2();
}

double Subforwardlist2::getData() {
    return data;
}

void Subforwardlist2::setData(double d) {
    data=d;
}

Subforwardlist2* Subforwardlist2::getNext() {
    return next;
}

void Subforwardlist2::setNext(Subforwardlist2* t) {
    next=t;
}

bool Subforwardlist2::push_back(double d)
{
    Subforwardlist2 *a = new Subforwardlist2;
    a->setNext(this);
    if (a==NULL)
    {
        a->setData(d);
        a->setNext(NULL);
    }
    else
    {
        while (a->getNext() != NULL)
        {
            a=a->getNext();
        }
        Subforwardlist2 *q = new Subforwardlist2;
        q->setData(d);
        q->setNext(NULL);
        a->setNext(q);
    }
    *this = *a;
    delete a;
    return true;
}

int Subforwardlist2::pop_back()
{
    if (this == NULL)
    {
        return 0;
    }
    else
    {
        double n=0;
        Subforwardlist2 *t= new Subforwardlist2;
        Subforwardlist2 *q= new Subforwardlist2;
        Subforwardlist2 *r= new Subforwardlist2;
        t=this;
        *r=*t;
        if (t->getNext() == NULL)
        {
            n=t->getData();
            delete this;
        }
        else
        {
            while (t->getNext() != NULL)
            {
                q=t;
                t=t->getNext();
            }
            n=t->getData();
            q->setNext(NULL);
            t=NULL;
            delete t;
            delete q;
            *this = *r;
            delete r;
        }
        return n;
    }
}

bool Subforwardlist2::push_forward(double d)
{
    Subforwardlist2 *t= new Subforwardlist2;
    if (this==NULL)
    {
        t->setData(d);
        t->setNext(NULL);
        *this = *t;
        delete t;
    }
    else
    {
        Subforwardlist2 *r=new Subforwardlist2;
        r=this;
        t->setData(d);
        t->setNext(r);
        *this=*t;
    }
    return true;
}

int Subforwardlist2::pop_forward()
{
    if (this==NULL)
    {
        return 0;
    }
    else
    {
        double n=this->getData();
        Subforwardlist2 *t= new Subforwardlist2;
        *t=*this->getNext();
        delete this;
        *this=*t;
        return n;
    }
}

bool Subforwardlist2::push_where(unsigned int where, double d)
{
    if (this==NULL)
    {
        if (getData()>1)
        {
            return false;
        }
        else
        {
            Subforwardlist2 *t = new Subforwardlist2;
            t->setData(d);
            t->setNext(NULL);
            *this = *t;
        }
    }
    else
    {
        Subforwardlist2 *t = new Subforwardlist2;
        Subforwardlist2 *r = new Subforwardlist2;
        t=this;
        *r=*t;
        int i=1;
        while ((t->getNext() != NULL) && (i<where))
        {
            t=t->getNext();
            i++;
        }
        if (i<where)
        {
            return false;
        }
        else
        {
            Subforwardlist2 *q = new Subforwardlist2;
            Subforwardlist2 *w = new Subforwardlist2;
            w->setData(t->getData());
            w->setNext(t->getNext());
            q->setData(d);
            q->setNext(w);
            *t=*q;
            *this=*r;
            delete q;
            delete w;
            delete t;
            delete r;
            return true;
        }
    }
}

bool Subforwardlist2::erase_where (unsigned int d)
{
    if (this==NULL)
    {
        return false;
    }
    else
    {
        Subforwardlist2 *t = new Subforwardlist2;
        Subforwardlist2 *r = new Subforwardlist2;
        int i=1;
        t=this;
        *r=*t;
        while ((t->getNext() != NULL) && (i<d))
        {
            t=t->getNext();
            i++;
        }
        if (i<d)
        {
            return false;
        }
        else
        {
            *t=*(t->getNext());
            *this=*r;
            return true;
        }
        delete t;
        delete r;
    }
}

unsigned int Subforwardlist2::size ()
{
    if (this == NULL)
    {
        return 0;
    }
    else
    {
        int i=1;
        Subforwardlist2 *t = new Subforwardlist2;
        t=this;
        while (t->next != NULL)
        {
            i++;
            t=t->getNext();
        }
        delete t;
        return i;
    }
}
