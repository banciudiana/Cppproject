#pragma once
#include<iostream>
using namespace std;

class Operator
{
private:
    char symbol;

public:
    
    Operator(char op = '\0') : symbol(op) {}

    char getSymbol() const {
        return symbol;
    }

    friend ostream& operator<<(ostream& out, Operator& oper);
    friend istream& operator>>(istream& in, Operator& oper);
};
istream& operator>>(istream& in, Operator& oper)
{
    in >> oper.symbol;
    return in;
}

ostream& operator<<(ostream& out, Operator& oper)
{
    cout << "operator " << oper.symbol;
    return out;
}