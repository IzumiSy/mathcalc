#ifndef __STRING_EXPRESSION_H__
#define __STRING_EXPRESSION_H__

#include <vector>
#include <string>
#include "types.h"

class StringExpression {
  private:
    struct ExpressionList expressionList;
    std::vector<struct SIGN> expressionSigns;
    std::string::size_type currentPos;
    std::string::size_type nextExpressionPos;
    std::string expressions;

    struct SIGN makeSign(std::string sign, SIGN_TYPE type);
    void addSign(struct SIGN sign);
    void defineExpressionSings();
    SIGN_TYPE getExpressionType(std::string sign);
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
