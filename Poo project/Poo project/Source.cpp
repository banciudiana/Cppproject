#include<iostream>
#include "Token.h"
#include "Calculator.h"
#include <string>
//versiune finala

using namespace std;
int main()
{
  
    Token token;
    cin >> token;
   
    double result = Calculator::evaluateExpression(token);

  
    cout << "Result: " << result << endl;

    return 0;
   
}