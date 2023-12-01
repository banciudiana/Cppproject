#include<iostream>
#include "Token.h"
#include "Calculator.h"

int main()
{
	
    Token tokenizer;
    std::cin >> tokenizer;

    std::cout << tokenizer << std::endl;

  
    double result = Calculator::evaluateExpression(tokenizer);

  
    std::cout << "Result: " << result << std::endl;

    return 0;
   
}