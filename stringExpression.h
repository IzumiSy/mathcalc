#ifndef __STRING_EXPRESSION_H__
#define __STRING_EXPRESSION_H__

#include <vector>
#include <string>
#include "symbol.h"
#include "expressionList.h"

class StringExpression {
  private:
    ExpressionList expressionList;
    std::vector<struct SYMBOL> symbols;
    std::string::size_type currentPos;
    std::string::size_type nextExpressionPos;
    std::string expressions;

    void addSymbol(struct SYMBOL sign);
    void defineSymbols();
    SYMBOL::TYPES getExpressionType(std::string sign);
    std::string::size_type getNextExpressionPos();

  public:
    StringExpression(std::string expressions);
    ExpressionList getExpressionsList();

    bool hasNextExpression();
    void parseNumberValue();
    void parseExpression();
    void begin();
    void next();
};

#endif
