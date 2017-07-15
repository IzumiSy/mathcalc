#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>
#include <list>
#include <locale>
using namespace std;

#include "calculator.h"
#include "types.h"

int main(int argc, char *argv[])
{
    if (argc == 1) {
        cout << "usage: mathcalc [expression]" << endl;
        exit(1);
    }

    // struct PROGRESSION_FLAGS pflags;
    string expressions = argv[1];

    Calculator calc(expressions);
    try {
      calc.parseStringExpressions();
      calc.validateExpressions();
      calc.printExpressions();
    } catch (struct Exception e) {
      std::cerr << "Error: " << e.msg() << std::endl;
      exit(1);
    }

    return 0;
}


