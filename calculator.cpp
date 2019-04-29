#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <iostream>
#include "calculator.h"
#include "stringExpression.h"

// Parses string expressions of std::string into ExpressionList
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

// Prints stringified ExpressionList into STDOUT
void Calculator::print() {
  std::cout << this->expressionList.stringify() << std::endl;
  return;
}

// Checks out if this->expressionList has any invalid expression, and throws exceptions.
// his method expects to be called after Calculator::parse because this->expressionList is populated by it.
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
