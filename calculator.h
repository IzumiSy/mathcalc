#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

#include <string>
#include <list>
#include "types.h"

class Calculator {
  private:
    // struct PROGRESSION_FLAGS pflags;

    std::string stringExpressions;
    struct ExpressionList expressionList;

  public:
    Calculator(std::string expressions);
    ~Calculator();

    void parseStringExpressions();
    void printExpressions();

    void processBrackets();
    void execCalculation();
};

#endif // __CALCULATOR_H__

