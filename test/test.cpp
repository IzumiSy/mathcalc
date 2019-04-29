#include "vendors/minunit.h"
#include "../expression.h"
#include "../rpn.h"
#include <list>

MU_TEST(rpnPlus) {
  const struct EXPRESSION plus =
    EXPRESSION::make(EXPRESSION::TYPES::SYMBOL, "+");

  std::list<struct EXPRESSION> expressions;
  expressions.push_back(EXPRESSION::make(EXPRESSION::TYPES::VALUE, "10"));
  expressions.push_back(EXPRESSION::make(EXPRESSION::TYPES::VALUE, "5"));
  expressions.push_back(plus);

  const RPN rpnPlus(expressions);
  mu_check(rpnPlus.result() == 15);
}

MU_TEST(rpnMinus) {
  const struct EXPRESSION minus =
    EXPRESSION::make(EXPRESSION::TYPES::SYMBOL, "-");

  std::list<struct EXPRESSION> expressions;
  expressions.push_back(EXPRESSION::make(EXPRESSION::TYPES::VALUE, "10"));
  expressions.push_back(EXPRESSION::make(EXPRESSION::TYPES::VALUE, "20"));
  expressions.push_back(minus);

  const RPN rpnMinus(expressions);
  mu_check(rpnMinus.result() == 10);
}

MU_TEST(rpnMulti) {
  const struct EXPRESSION minus =
    EXPRESSION::make(EXPRESSION::TYPES::SYMBOL, "*");

  std::list<struct EXPRESSION> expressions;
  expressions.push_back(EXPRESSION::make(EXPRESSION::TYPES::VALUE, "20"));
  expressions.push_back(EXPRESSION::make(EXPRESSION::TYPES::VALUE, "3"));
  expressions.push_back(minus);

  const RPN rpnMinus(expressions);
  mu_check(rpnMinus.result() == 60);
}

MU_TEST(rpnDivision) {
  const struct EXPRESSION minus =
    EXPRESSION::make(EXPRESSION::TYPES::SYMBOL, "/");

  std::list<struct EXPRESSION> expressions;
  expressions.push_back(EXPRESSION::make(EXPRESSION::TYPES::VALUE, "3"));
  expressions.push_back(EXPRESSION::make(EXPRESSION::TYPES::VALUE, "30"));
  expressions.push_back(minus);

  const RPN rpnMinus(expressions);
  mu_check(rpnMinus.result() == 10);
}

int main(int argc, char *argv[]) {
  MU_RUN_TEST(rpnPlus);
  MU_RUN_TEST(rpnMinus);
  MU_RUN_TEST(rpnMulti);
  MU_RUN_TEST(rpnDivision);
  MU_REPORT();
  return minunit_status;
}
