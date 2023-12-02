#pragma once
#include<iostream>
using namespace std;

class Operator
{
private:
    char symbol;
    int idSymbol;
public:
    Operator(char op, int id)
    {
        if (op != NULL) {
            symbol = op;
        }
        if (id != 0)
        {
            idSymbol = id;
        }
    }
    Operator(char op = '\0') : symbol(op) {}

    char getSymbol() {
        return symbol;
    }
    void setSymbol(char op)
    {
        if (op != NULL)
        {
            symbol = op;
        }
    }
    int getIdSymbol() {
        return idSymbol;
    }
    void setIdSymbol(int a)
    {
        if (a != NULL)
        {
            idSymbol = a;
        }
    }
    bool operator>(const Operator& op)
    {
        if ((symbol == '+' || symbol == '-') && (op.symbol == '*' || op.symbol == '/'))
            return false;
        else 
            return true;
    }
    bool operator< (const Operator& op)
    {
        if ((symbol == '+' || symbol == '-') && (op.symbol == '*' || op.symbol == '/'))
            return true;
        else return false;
    }

    friend ostream& operator<<(ostream& out, Operator& oper);
    friend istream& operator>>(istream& in,const  Operator& oper);
};
istream& operator>>(istream& in, const Operator& oper)
{
    in >> oper.symbol;
    return in;
}

ostream& operator<<(ostream& out, Operator& oper)
{
    cout << "operator " << oper.symbol;
    return out;
}