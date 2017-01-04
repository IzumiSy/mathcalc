#include <list>
#include <string>
#include <algorithm>
#include "types.h"
#include "expressionList.h"

void ExpressionList::add(struct EXPRESSION expression) {
  this->expressions.push_back(expression);
}

void ExpressionList::cleanupJunks() {
  this->expressions.remove_if(ExpressionList::emptyExpression);
}

std::string ExpressionList::getStringified() {
  std::string buffer;
  std::list<struct EXPRESSION>::iterator it = this->expressions.begin();
  std::list<struct EXPRESSION>::iterator end = this->expressions.end();

  for (; it != end; it++) {
      buffer += it->value;
  }

  return buffer;
}

void ExpressionList::validateBracketsParing() {
  size_t beginBracketCount = std::count(this->expressions.begin(), this->expressions.end(), std::string("("));
  size_t endBracketCount = std::count(this->expressions.begin(), this->expressions.end(), std::string(")"));

  if (beginBracketCount != endBracketCount) {
    throw Exception::make("Brackets unmatched.");
  }

  return;
}

void ExpressionList::validateDuplicatedSymbol() {
  std::list<struct EXPRESSION>::iterator it = this->expressions.begin();
  std::list<struct EXPRESSION>::iterator end = this->expressions.end();
  std::list<struct EXPRESSION>::iterator temp;

  for (; it != end; it++) {
    if (it->type == EXPRESSION::SYMBOL) {
      temp = it;
      temp++;
      if (temp->type == EXPRESSION::SYMBOL && temp->value != std::string("(") && temp->value != ")") {
        throw Exception::make("Duplicated symbol.");
      }
    }
  }

  return;
}

void ExpressionList::validateLonelySymbol() {
  // throw Exception::make("Lonely symbol.");
  return;
}

