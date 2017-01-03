#ifndef __STRING_EXPRESSION_H__
#define __STRING_EXPRESSION_H__

#include <vector>
#include <string>
#include "types.h"

typedef std::string EXPRESSION_SIGN;

class StringExpression {
  private:
    struct ExpressionList expressionList;
    std::vector<EXPRESSION_SIGN> expressionSigns;
    std::string::size_type currentPos;
    std::string::size_type nextExpressionPos;
    std::string expressions;

    void setSign(std::string sign);
    void defineExpressionSings();
    EXPRESSION_TYPE getExpressionType(std::string sign);
    std::string::size_type getNextExpressionPos();

  public:
    StringExpression(std::string expressions);
    struct ExpressionList getExpressionsList();

    bool hasNextExpression();
    void parseNumberValue();
    void parseExpression();
    void begin();
    void next();
};

#endif
