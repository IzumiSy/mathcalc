#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>

// TODO: EXPRESSIONは単なるインターフェースにしてこれを満たす
// 数値クラス, 記号クラスを実装するほうがよい. 例えばtoLongメソッド
// などは記号に対してはどのように作用するか予測できないためよくない。
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

  bool operator==(std::string value) const {
    return (this->value == value);
  }

  inline bool isSymbol() const {
    return this->type == SYMBOL;
  }

  inline long toLong() const {
    if (this->isSymbol()) {
      return 0;
    } else {
      return std::stol(this->value);
    }
  }
};

#endif // EXPRESSION_H
