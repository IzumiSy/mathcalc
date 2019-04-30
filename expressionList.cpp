#include <list>
#include <string>
#include <algorithm>
#include "expression.h"
#include "exception.h"
#include "expressionList.h"

void ExpressionList::add(struct EXPRESSION expression) {
  this->expressions.push_back(expression);
}

void ExpressionList::cleanupJunks() {
  this->expressions.remove_if(ExpressionList::emptyExpression);
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
      if ((it->value != std::string(")")) &&
          (temp->type == EXPRESSION::SYMBOL) &&
          (temp->value != std::string("("))) {
        throw Exception::make("Duplicated symbol.");
      }
    }
  }

  return;
}

void ExpressionList::validateLonelySymbol() {
  std::list<struct EXPRESSION>::const_iterator head = this->expressions.begin();
  std::list<struct EXPRESSION>::const_iterator tail = this->expressions.end();

  tail--;
  if ((head->type == EXPRESSION::SYMBOL && head->value != std::string("(")) ||
      (tail->type == EXPRESSION::SYMBOL && tail->value != std::string(")"))) {
    throw Exception::make("Lonely symbol.");
  }

  return;
}

std::string ExpressionList::stringify() const {
  std::string buffer;
  std::list<struct EXPRESSION>::const_iterator it = this->expressions.begin();
  std::list<struct EXPRESSION>::const_iterator end = this->expressions.end();

  for (; it != end; it++) {
    buffer += it->value;
  }

  return buffer;
}

std::list<struct EXPRESSION> ExpressionList::toList() const {
  return this->expressions;
}
