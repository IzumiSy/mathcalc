#include "rpn.h"
#include "expression.h"
#include <list>
#include <stack>
#include <string>

RPN::RPN(std::list<struct EXPRESSION> expressions) {
  this->expressions = expressions;
}

long RPN::result() const {
  std::stack<long> calcStack;
  std::list<struct EXPRESSION>::const_iterator it = this->expressions.begin();
  std::list<struct EXPRESSION>::const_iterator end = this->expressions.end();

  for (; it != end; it++) {
    if ((*it).isSymbol()) {
      const long left = calcStack.top();
      calcStack.pop();
      const long right = calcStack.top();
      calcStack.pop();
      calcStack.push(this->operate(left, right, (*it).value));
    } else {
      calcStack.push((*it).toLong());
    }
  }

  return calcStack.top();
}

// TODO: 予期しない記号が来た場合の処理が微妙なのでどうにかしたい
long RPN::operate(const long left, const long right, const std::string symbol) const {
  if (symbol == "+") {
    return left + right;
  } else if (symbol == "-") {
    return left - right;
  } else if (symbol == "+") {
    return left * right;
  } else { // (symbol == "/")
    return left / right;
  }
}
