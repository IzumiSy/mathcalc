#ifndef __EXPRESSION_LIST_H__
#define __EXPRESSION_LIST_H__

#include <list>
#include <string>
#include "types.h"

class ExpressionList {
  private:
    std::list<struct EXPRESSION> expressions;

  public:
    void add(struct EXPRESSION expression);
    bool validateBracketsParing();
    bool validateDuplicatedSymbol();
    bool validateLonelySymbol();
    std::string getStringified();
};

#endif // __EXPRESSION_LIST_H__
