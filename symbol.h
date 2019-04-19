#ifndef SYMBOL_H
#define SYMBOL_H

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

  static struct SYMBOL make(std::string character, SYMBOL::TYPES type) {
    struct SYMBOL symbol;
    symbol.character = character;
    symbol.type = type;
    return symbol;
  };

  bool operator==(std::string character) {
    return (this->character == character);
  }
};

#endif // SYMBOL_H