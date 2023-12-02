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
    double result = 0.0;
    char lastOperator = '+';
    static const int maxStackSize = 100;
    double values[maxStackSize];
    char operators[maxStackSize];
    int valueIndex = 0;
    int operatorIndex = 0;

public:
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
            if (tokens.isNumericToken(currentToken))
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

    static void applyOperator(double values[], int& valueIndex, char operators)
    {
        if (valueIndex < 2)
        {
            throw ("exp invalida");
            
        }

        double right = values[--valueIndex];
        double left = values[--valueIndex];

        char op = operators;
        double result = calculate(left, right, op);
        values[valueIndex++] = result;
    }

public:
    static double evaluateExpression( Token& tokens)
    {
        int index = 0;
        return evaluateExpressionHelper(tokens);
    }
};