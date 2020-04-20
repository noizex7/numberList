#include <iostream>
using namespace::std;

#ifndef NUMBER_H
#define NUMBER_H

class Number
{
    friend ostream& operator << (ostream&, const Number&);
    friend istream& operator >> (istream&, Number&);
private:
    double* list;
    int index;
public:
    Number(int = 1);

    void setIndex(int);
    void setNumber(double, int);

    int getIndex() const;
    double getNumber(int) const;

    void sort();
    double getHighest();
    double getLowest();
    double getAverage();

    const Number operator = (Number& right);
    bool operator == (Number& right) const;
    bool operator != (Number& right);
    double& operator [] (int);
    double operator [] (int) const;




    ~Number();
};
#endif
