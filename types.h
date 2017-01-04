#ifndef TYPES_H
#define TYPES_H

#include <list>
#include <string>

struct SYMBOL {
  enum TYPES {
    PLUS = 0,
    MINUS,
    DIVIDE,
    MULTIPLY,
    BRACKET_BEGIN,
    BRACKET_END,
    OTHER
  };

  SYMBOL::TYPES type;
  std::string character;

  static struct SYMBOL makeSymbol(std::string character, SYMBOL::TYPES type) {
    struct SYMBOL symbol;
    symbol.character = character;
    symbol.type = type;
    return symbol;
  };

  bool operator==(std::string character) {
    return (this->character == character);
  }
};

struct EXPRESSION {
  enum TYPES {
    VALUE,
    SYMBOL
  };

  EXPRESSION::TYPES type;
  std::string value;

  static struct EXPRESSION makeExpression(EXPRESSION::TYPES type, std::string value) {
    struct EXPRESSION expression;
    expression.type = type;
    expression.value = value;
    return expression;
  };

  bool operator==(std::string value) {
    return (this->value == value);
  }
};

struct EXP_DIVIDER_RESULT {
    int left_value;
    int right_value;
};

struct PROGRESSION_FLAGS {
    std::list<std::string> expressions;
    std::list<std::string>::iterator it;
    bool exists_mul_and_div;
    bool exists_pls_and_mns;
    bool go_through;
};

#endif
