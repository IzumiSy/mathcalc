#include <string>
#include <vector>
#include <algorithm>
#include "stringExpression.h"
#include "types.h"

void StringExpression::addSign(struct SYMBOL sign) {
  this->expressionSigns.push_back(sign);
}

void StringExpression::defineExpressionSings() {
  this->addSign(SYMBOL::makeSymbol("+", SYMBOL::PLUS));
  this->addSign(SYMBOL::makeSymbol("-", SYMBOL::MINUS));
  this->addSign(SYMBOL::makeSymbol("*", SYMBOL::MULTIPLY));
  this->addSign(SYMBOL::makeSymbol("/", SYMBOL::DIVIDE));
  this->addSign(SYMBOL::makeSymbol("(", SYMBOL::BRACKET_BEGIN));
  this->addSign(SYMBOL::makeSymbol(")", SYMBOL::BRACKET_END));
}

std::string::size_type StringExpression::getNextExpressionPos() {
  std::vector<std::string::size_type> expressionPositionsIndex;
  std::vector<struct SYMBOL>::iterator it = this->expressionSigns.begin();
  std::vector<struct SYMBOL>::iterator end = this->expressionSigns.end();

  for (; it != end; it++) {
    expressionPositionsIndex.push_back(this->expressions.find(it->character, this->currentPos));
  }

  return *std::min_element(expressionPositionsIndex.begin(), expressionPositionsIndex.end());
}

StringExpression::StringExpression(std::string expressions) {
  this->defineExpressionSings();
  this->expressions = expressions;
  this->currentPos = 0;
}

struct ExpressionList StringExpression::getExpressionsList() {
  return this->expressionList;
}

void StringExpression::begin() {
  this->nextExpressionPos = this->getNextExpressionPos();
}

void StringExpression::next() {
  this->currentPos = (nextExpressionPos + 1);
}

bool StringExpression::hasNextExpression() {
  nextExpressionPos = this->getNextExpressionPos();
  if (this->nextExpressionPos == std::string::npos) {
    return false;
  } else {
    return true;
  }
}

void StringExpression::parseNumberValue() {
  struct EXPRESSION expression;
  std::string valuePart =
    this->expressions.substr(this->currentPos, this->nextExpressionPos - this->currentPos);

  expression.type = VALUE;
  expression.value = valuePart;
  this->expressionList.expressions.push_back(expression);
}

void StringExpression::parseExpression() {
  struct EXPRESSION expression;
  std::string expressionPart = this->expressions.substr(nextExpressionPos, 1);

  expression.type = SYMBOL;
  expression.value = expressionPart;
  this->expressionList.expressions.push_back(expression);
}

