#include<iostream>
#include "Token.h"
#include "Calculator.h"
#include <string>

int main()
{
  
        Token token;
        cin >> token;
   
    double result = Calculator::evaluateExpression(token);

  
    std::cout << "Result: " << result << std::endl;

    return 0;
   
}