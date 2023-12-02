#pragma once
#include<iostream>
#include<string>

using namespace std;

class Numerele
{
private:
    double val;
    int valMax;

public:
    Numerele(double v, int max)
    {
        val = v;
        valMax = max;
    }
    Numerele(double val = 0.0) : val(val) {}

    double getValue() {
        return val;
    }
    void setVal(double v)
    {
        if (v != NULL)
        {
            val = v;
        }
    }
    int getValMax()
    {
        return valMax;
    }
    void setValMax(int a)
    {
        if (a != 0)
            valMax = a;
    }
    double operator++()
    {
        val++;
        return val;
    }
    double operator--()
    {
        if (val >= 1)
        {
            val--;
            return val;
        }
        else
            return val;
    }
    friend ostream& operator<<(ostream& out, Numerele& nr);
    
    friend istream& operator>>(istream& in, Numerele& nr);
};

istream& operator>>(istream& in, Numerele& nr)
{
    in >> nr.val;
    return in;
}
ostream& operator<<(ostream& out, Numerele& nr)
{
    out << "nr " << nr.val;
    return out;
}