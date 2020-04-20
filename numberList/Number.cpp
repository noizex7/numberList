#include "Number.h"

istream& operator >> (istream& strm, Number& right)
{
    int i;
    for (i = 0; i < right.index; i++)
    {
        cout << "Enter the number for slot [" << i + 1 << "]\n";
        strm >> right[i];
    }
    return strm;
}

ostream& operator << (ostream& strm, const Number& right)
{
    int i;
    for (i = 0; i < right.index; i++)
    {
        strm << right[i] << '\t';
    }

    return strm;
}

Number::Number(int aIndex)
{
    int i;
    setIndex(aIndex);

    list = new double[index];

    for (i = 0; i < index; i++)
    {
        list[i] = 0;
    }
}

void Number::setIndex(int aIndex)
{
    if (aIndex < 1)
    {
        index = 1;
    }
    else
    {
        index = aIndex;
    }

}

void Number::setNumber(double aNumber, int aIndex)
{
    list[aIndex] = aNumber;
}

int Number::getIndex() const
{
    return index;
}

double Number::getNumber(int aIndex) const
{
    return list[aIndex];
}

void Number::sort()
{
    int i, j;
    double temp;

    for (i = 0; i < index; i++)
    {
        for (j = i + 1; j < index; j++)
        {
            if (list[i] > list[j])
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}

double Number::getHighest()
{
    int i;
    double highest = list[0];

    for (int i = 1; i < index; i++)
    {
        if (highest < list[i])
        {
            highest = list[i];
        }
    }

    return highest;
}

double Number::getLowest()
{
    int i;
    double lowest = list[0];

    for (i = 1; i < index; i++)
    {
        if (lowest > list[i])
        {
            lowest = list[i];
        }
    }

    return lowest;
}

double Number::getAverage()
{
    int i;
    double counter = 0;

    for (i = 0; i < index; i++)
    {
        counter += list[i];
    }

    return counter / double(index);
}

const Number Number::operator = (Number& right)
{
    int i;
    if (&right != this)
    {
        if (index != right.getIndex())
        {
            delete[] list;
            index = right.getIndex();
            list = new double[index];
        }
    }

    for (i = 0; i < index; i++)
    {
        list[i] = right[i];
    }

    return *this;
}

bool Number::operator == (Number& right) const
{
    int i;
    if (index != right.getIndex())
    {
        return false;
    }
    for (i = 0; i < index; i++)
    {
        if (list[i] != right.list[i])
        {
            return false;
        }
    }

    return true;
}

bool Number::operator != (Number& right)
{
    int i;
    if (index != right.getIndex())
    {
        return true;
    }
    for (i = 0; i < index; i++)
    {
        if (list[i] != right.list[i])
        {
            return true;
        }
    }

    return false;
}

double& Number::operator [] (int subscript)
{
    if (index < 0 || subscript >= index)
    {
        throw out_of_range("Subscript out of range");
    }

    return list[subscript];
}

double Number::operator [] (int subscript) const
{
    if (index < 0 || subscript >= index)
    {
        throw out_of_range("Subscript out of range");
    }

    return list[subscript];
}


Number::~Number()
{
    delete[] list;
}
