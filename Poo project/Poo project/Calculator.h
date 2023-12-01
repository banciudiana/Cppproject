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
                std::cerr << "Error: Division by zero." << std::endl;
                return 0.0; // Handle division by zero error
            }
        default:
            std::cerr << "Error: Unknown operator." << std::endl;
            return 0.0; // Handle unknown operator error
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
        while (const char* currentToken = tokens.getNextToken())
        {
            if (tokens.isNumericToken(currentToken))
            {
                Numerele operand;
                sscanf(currentToken, "%lf", &operand);
                result = calculate(result, operand.getValue(), lastOperator);
            }
            else
            {
                Operator oper;
                sscanf(currentToken, "%c", &oper);

                if (isOperator(oper.getSymbol()))
                {
                    lastOperator = oper.getSymbol();
                }
                else
                {
                    std::cerr << "Error: Invalid operator." << std::endl;
                    
                    return 0.0;
                }
            }
        }
        tokens.resetIndex();

        return result;
    }

public:
    static double evaluateExpression( Token& tokens)
    {
        int index = 0;
        return evaluateExpressionHelper(tokens);
    }
};