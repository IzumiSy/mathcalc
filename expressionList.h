#ifndef __EXPRESSION_LIST_H__
#define __EXPRESSION_LIST_H__

#include <list>
#include <string>
#include "types.h"

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
    std::string getStringified();
};

#endif // __EXPRESSION_LIST_H__
