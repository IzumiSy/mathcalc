#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <iostream>
#include "calculator.h"
#include "stringExpression.h"

void Calculator::parse(std::string expressions) {
  StringExpression stringExpression(expressions);

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

void Calculator::print() {
  std::string stringifiedExpression = this->expressionList.getStringified();
  std::cout << stringifiedExpression << std::endl;
  return;
}

void Calculator::validate() {
  this->expressionList.validateBracketsParing();
  this->expressionList.validateDuplicatedSymbol();
  this->expressionList.validateLonelySymbol();
  return;
}

void Calculator::run() {
  // TODO: あとでつくる
  return;
}
