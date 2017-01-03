#include <string>
#include <list>
#include "types.h"

struct PROGRESSION_FLAGS {
    list<string> expressions;
    list<string>::iterator it;
    bool exists_mul_and_div;
    bool exists_pls_and_mns;
    bool go_through;
};

class Calculator {
  private:
    struct PROGRESSION_FLAGS pflags;

  public:
    void Calculator();
    void ~Calculator();

    void buildExpressions();
    void processBrackets();
    void execCalculation();
};

void Calculator::Calculator(string expression) {

}

void Calculator::~Calculater() {

}

void Calculator::buildExpressions() {

}

void Calculator::processBrackets() {

}

void Calculator::execCalculation() {

}
