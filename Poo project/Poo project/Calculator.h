#pragma once
#include<iostream>
#include<string>
#include"Operator.h"
#include"Numerele.h"
#include"Token.h"
using namespace std;


class Calculator
{

private:
    double* numereCalcul;
    int dim;
    static const int DIM_MAX = 10000;
    static int obiecteCalculator;
   
public:
    Calculator()
      	{
        	numereCalcul = nullptr;
        		dim = 0;
        }
    Calculator(double numbers[], int numbersDim) :Calculator()
       	{
        		if (numbersDim > 0 && DIM_MAX > numbersDim && numbers!=nullptr)
       	{
        			numereCalcul = new double[numbersDim];
        			dim = numbersDim;
        			for (int i = 0; i < numbersDim; i++)
        			{
        				numereCalcul[i] = numbers[i];
        		}
        			obiecteCalculator++;
        
        		}
        		else return;
        }
    ~Calculator()
        	{
        		delete[] numereCalcul;
        		obiecteCalculator--;
        	}
    Calculator(const Calculator& c)
     {
       		numereCalcul = new double[c.dim];
        	dim = c.dim;
       	for (int i = 0; i < c.dim; i++)
        {
        	numereCalcul[i] = c.numereCalcul[i];
     	}
     }
    Calculator& operator =(const Calculator& c)
        {
        		if (this != &c)
        		{
        
        			delete[] numereCalcul;
        			numereCalcul = new double[c.dim];
        			dim = c.dim;
        			for (int i = 0; i < c.dim; i++)
        			{
        				numereCalcul[i] = c.numereCalcul[i];
        			}
        		}
        		return *this;
        }
        int getDim()
        {
        	return dim;
       
        }
        
        void setDim(int d)
        {
      	if (d > 0)
        {
        			dim = d;
        }
        else cout << "nu corespunde cerintelor" << endl;
        }
        
        double* getNumereCalcul()
        {
        		return numereCalcul;
        }
        
    void setNumereCalcul(const double numbers[], int numbersDim)
    {
        		if (numbers != nullptr && DIM_MAX > numbersDim && numbersDim > 0)
        		{
        			delete[] numereCalcul;
        			numereCalcul = new double[numbersDim];
        			for (int i = 0; i < numbersDim; i++)
        			{
        				numereCalcul[i] = numbers[i];
        				dim = numbersDim;
        			}
        		}
    }
    double  operator +(const Calculator& c)
    {
        if (dim != c.dim)
            throw ("nu se pot aduna");
        else
        {
            double result;
            for (int i = 0; i < dim; i++)
            result = numereCalcul[i] + c.numereCalcul[i];
            return result;
        }
    }
    double  operator -(const Calculator& c)
    {
        if (dim != c.dim)
            throw ("nu se pot scade");
        else
        {
            double result;
            for (int i = 0; i < dim; i++)
                result = numereCalcul[i] - c.numereCalcul[i];
            return result;
        }
    }
    static double calculate(double left, double right, char op)
    {
        switch (op)
        {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        case '/':
            if (right != 0.0)
            {
                return left / right;
            }
            else
            {
                throw ("nu se poate impartii la zero");
                return 0.0; 
            }
        default:
            throw("acest operator nu exista");
            return 0.0; 
        }
    }
    static bool isOperator(char ch)
    {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/';
    }
    static double evaluateExpressionHelper(Token&tokens)
    {
        double result = 0.0;
        char lastOperator = '+'; 
        const int maxStackSize = 100;  
        double values[maxStackSize];
        char operators[maxStackSize];
        int valueIndex = 0;
        int  operatorIndex = 0;
        while (const char* currentToken = tokens.getNextToken())
        {
            if (tokens.esteNumar(currentToken))
            {
                Numerele operand;
                sscanf(currentToken, "%lf", &operand);
                values[valueIndex++] = operand.getValue();
            }
            else
            {
                Operator oper;
                sscanf(currentToken, "%c", &oper);
                char currentOperator = oper.getSymbol();
                while (operatorIndex > 0 && hasHigherPrecedence(operators[operatorIndex - 1], currentOperator))
                {
                    applyOperator(values, valueIndex, operators[--operatorIndex]);
                }

                operators[operatorIndex++] = currentOperator;
            }
        }
        while (operatorIndex > 0)
        {
            applyOperator(values, valueIndex, operators[--operatorIndex]);
        }
        if (valueIndex > 0)
        {
            return values[--valueIndex];
        }
        
    }

    static bool hasHigherPrecedence(char op1, char op2)
    {
        return (op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-');
    }

    static void applyOperator(double nr[], int& nrI, char oper)
    {
        if (nrI < 2)
        {
            throw ("exp invalida");
            
        }

        double right = nr[--nrI];
        double left = nr[--nrI];

        char op = oper;
        double result = calculate(left, right, op);
        nr[nrI++] = result;
    }
    static double evaluateExpression( Token& tokens)
    {
        return evaluateExpressionHelper(tokens);
    }


    friend istream& operator >>(istream& in, Calculator& c);
    friend ostream& operator<<(ostream& out, Calculator& c);

};
int Calculator::obiecteCalculator = 0;

ostream& operator<<(std::ostream& out, Calculator& c) {
    out << "Dimensiune " << c.dim <<endl;
    out << "Numerele calcului " << endl;
    for (int i = 0; i < c.dim; i++) {
        out << c.numereCalcul[i] << "\t" << endl;
    }
    return out;
}

istream& operator>>(std::istream& in, Calculator& c) {
    cout << "Dimensiune ";
    in >> c.dim;
    if (c.dim <= 0)
        throw ("Dimensiunea nu este buna ");
    cout << endl;
    cout << "Numerele calcului ";
    c.numereCalcul = new double[c.dim];
    for (int i = 0; i < c.dim; i++) {
        in >> c.numereCalcul[i];
    }

    return in;
}