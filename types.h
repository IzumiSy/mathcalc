#ifndef TYPES_H
#define TYPES_H

#include <list>
#include <string>

enum EXPRESSION_TYPE {
  PLUS = 0,
  MINUS,
  DIVIDE,
  MULTIPLE,
  BRACKET_BEGIN,
  BRACKET_END,

  VALUE,
  OTHER
};

struct EXPRESSION {
  EXPRESSION_TYPE type;
  std::string value;
};

struct ExpressionList {
  std::list<struct EXPRESSION> expressions;
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
