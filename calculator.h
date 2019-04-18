#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

#include <string>
#include <list>
#include "types.h"
#include "expressionList.h"

class Calculator {
  private:
    // struct PROGRESSION_FLAGS pflags;

    ExpressionList expressionList;

  public:
    void parse(std::string expressions);
    void print();
    void validate();
    void run();
};

#endif // __CALCULATOR_H__

