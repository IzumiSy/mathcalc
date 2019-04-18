#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

#include <string>
#include <list>
#include "types.h"
#include "expressionList.h"

class Calculator {
  private:
    // struct PROGRESSION_FLAGS pflags;

    std::string stringExpressions;
    ExpressionList expressionList;

  public:
    Calculator(std::string expressions);
    ~Calculator();

    void parse();
    void print();
    void validate();
    void run();
};

#endif // __CALCULATOR_H__

