#pragma once
#include<iostream>
#include<string>

using namespace std;

class Numerele 
{
private:
    double val;

public:
    Numerele(double val = 0.0) : val(val) {}

    double getValue()  {
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