#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

struct Exception {
  std::string message;

  static struct Exception make(std::string message) {
    struct Exception e;
    e.message = message;
    return e;
  };

  const char *msg() {
    return this->message.c_str();
  };
};

#endif