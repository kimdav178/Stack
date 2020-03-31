#include <iostream>
#include "Subforwardlist.h"
#include "Subforwardlist.cpp"
using namespace std;

int main() {
    int i,n;
    Subforwardlist a;
    cin >>n;
    a.push_back(n);
    cout <<a.size() <<endl;
    cout <<a.pop_back() <<endl;
    cin >>n;
    a.push_forward(n);
    cout <<a.size() <<endl;
    cin >>n;
    a.push_back(n);
    cin >>n;
    a.push_where(2,n);
    cout <<a.size() <<endl;
    a.erase_where(3);
    cout <<a.pop_forward() <<endl;
    cout <<a.getData() <<endl;
    cout <<a.getNext()->getData() <<endl;
    cout <<a.pop_back() <<endl;
    cout <<a.pop_back() <<endl;
    cout <<a.pop_back() <<endl;
    return 0;
}
