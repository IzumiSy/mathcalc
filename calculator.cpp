#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <iostream>
#include "calculator.h"
#include "stringExpression.h"

Calculator::Calculator(std::string expressions) {
  this->stringExpressions = expressions;
  return;
}

Calculator::~Calculator() {
  return;
}

void Calculator::parseStringExpressions() {
  StringExpression stringExpression(this->stringExpressions);

  while (1) {
    stringExpression.begin();
    stringExpression.parseNumberValue();
    if (stringExpression.hasNextExpression()) {
      stringExpression.parseExpression();
      stringExpression.next();
    } else {
      break;
    }
  }

  this->expressionList = stringExpression.getExpressionsList();
  this->expressionList.cleanupJunks();
  return;
}

void Calculator::printExpressions() {
  std::string stringifiedExpression = this->expressionList.getStringified();
  std::cout << stringifiedExpression << std::endl;
  return;
}

void Calculator::validateExpressions() {
  this->expressionList.validateBracketsParing();
  this->expressionList.validateDuplicatedSymbol();
  this->expressionList.validateLonelySymbol();
  return;
}

void Calculator::execCalculation() {
  return;
}
