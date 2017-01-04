#include <list>
#include <string>
#include "types.h"
#include "expressionList.h"

void ExpressionList::add(struct EXPRESSION expression) {
  this->expressions.push_back(expression);
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
  // throw Exception::make("Brackets unmatched.");
  return;
}

void ExpressionList::validateDuplicatedSymbol() {
  // throw Exception::make("Symbols duplicated.");
  return;
}

void ExpressionList::validateLonelySymbol() {
  // throw Exception::make("Lonely symbol.");
  return;
}

