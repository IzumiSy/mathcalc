#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>

struct EXPRESSION {
  enum TYPES {
    VALUE = 0,
    SYMBOL
  };

  EXPRESSION::TYPES type;
  std::string value;

  static struct EXPRESSION make(EXPRESSION::TYPES type, std::string value) {
    struct EXPRESSION expression;
    expression.type = type;
    expression.value = value;
    return expression;
  };

  bool operator==(std::string value) {
    return (this->value == value);
  }
};

#endif