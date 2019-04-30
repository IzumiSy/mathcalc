#ifndef RPN_H
#define RPN_H

#include <list>
#include <string>

class RPN {
  private:
    std::list<struct EXPRESSION> expressions;
    long operate(const long left, const long right, const std::string symbol) const;

  public:
    RPN(std::list<struct EXPRESSION> expressions);
    long result() const;
};

#endif // RPN_H
