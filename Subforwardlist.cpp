//
// Created by david on 31.03.2020.
//

#include "Subforwardlist.h"

using namespace std;

Subforwardlist::Subforwardlist()
{
    data = 0;
    next = NULL;
}

Subforwardlist::~Subforwardlist()
{
    if (this == NULL)
    {
        return;
    }
    Subforwardlist **t = new Subforwardlist*;
    *t = this;
    while (*t != NULL)
    {
        *t=(*t)->getNext();
    }
    delete t;
    this->~Subforwardlist();
}

double Subforwardlist::getData() {
    return data;
}

void Subforwardlist::setData(double d) {
    data=d;
}

Subforwardlist* Subforwardlist::getNext() {
    return next;
}

void Subforwardlist::setNext(Subforwardlist* t) {
    next=t;
}

bool Subforwardlist::push_back(double d)
{
    Subforwardlist *a = new Subforwardlist;
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
        Subforwardlist *q = new Subforwardlist;
        q->setData(d);
        q->setNext(NULL);
        a->setNext(q);
    }
    *this = *a;
    delete a;
    return true;
}

int Subforwardlist::pop_back()
{
    if (this == NULL)
    {
        return 0;
    }
    else
    {
        double n=0;
        Subforwardlist *t= new Subforwardlist;
        Subforwardlist *q= new Subforwardlist;
        Subforwardlist *r= new Subforwardlist;
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

bool Subforwardlist::push_forward(double d)
{
    Subforwardlist *t= new Subforwardlist;
    if (this==NULL)
    {
        t->setData(d);
        t->setNext(NULL);
        *this = *t;
        delete t;
    }
    else
    {
        Subforwardlist *r=new Subforwardlist;
        r=this;
        t->setData(d);
        t->setNext(r);
        *this=*t;
    }
    return true;
}

int Subforwardlist::pop_forward()
{
    if (this==NULL)
    {
        return 0;
    }
    else
    {
        double n=this->getData();
        Subforwardlist *t= new Subforwardlist;
        *t=*this->getNext();
        delete this;
        *this=*t;
        return n;
    }
}

bool Subforwardlist::push_where(unsigned int where, double d)
{
    if (this==NULL)
    {
        if (getData()>1)
        {
            return false;
        }
        else
        {
            Subforwardlist *t = new Subforwardlist;
            t->setData(d);
            t->setNext(NULL);
            *this = *t;
        }
    }
    else
    {
        Subforwardlist *t = new Subforwardlist;
        Subforwardlist *r = new Subforwardlist;
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
            Subforwardlist *q = new Subforwardlist;
            Subforwardlist *w = new Subforwardlist;
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

bool Subforwardlist::erase_where (unsigned int d)
{
    if (this==NULL)
    {
        return false;
    }
    else
    {
        Subforwardlist *t = new Subforwardlist;
        Subforwardlist *r = new Subforwardlist;
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

unsigned int Subforwardlist::size ()
{
    if (this == NULL)
    {
        return 0;
    }
    else
    {
        int i=1;
        Subforwardlist *t = new Subforwardlist;
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
