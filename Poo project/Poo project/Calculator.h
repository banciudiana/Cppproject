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
    
    static double evaluateExpressionHelper(Token&tokens)
    {
        double result = 0.0;
      
        while (const char* currentToken = tokens.getNextToken())
        {
            if (tokens.isNumericToken(currentToken))
            {
                Numerele operand;
                sscanf(currentToken, "%lf", &operand);
                result = operand.getValue();
            }
            else
            {
                Operator oper;
                sscanf(currentToken, "%c", &oper);

                switch (oper.getSymbol())
                {
                case '+':
                    break;
                case '-':
                    break;
                case '*':
                   break;
                case '/':
                    break;
                default:
                    
                    break;
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