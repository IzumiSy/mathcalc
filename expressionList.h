#ifndef __EXPRESSION_LIST_H__
#define __EXPRESSION_LIST_H__

#include <list>
#include <string>
#include "expression.h"

class ExpressionList {
  private:
    std::list<struct EXPRESSION> expressions;

    static bool emptyExpression(const struct EXPRESSION &expression) {
      return (expression.type == EXPRESSION::VALUE && expression.value == "");
    };

  public:
    void add(struct EXPRESSION expression);
    void cleanupJunks();
    void validateBracketsParing();
    void validateDuplicatedSymbol();
    void validateLonelySymbol();

    std::string stringify() const;
    std::list<struct EXPRESSION> toList() const;
};

#endif // __EXPRESSION_LIST_H__
