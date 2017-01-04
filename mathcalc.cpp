#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>
#include <list>
#include <locale>
using namespace std;

#include "types.h"
#include "utils.h"
#include "bracket.h"
#include "calcurate.h"

#include "calculator.h"

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

    /*
    // Build expression array from string given from command-line
    expressions = argv[1];
    build_expressions(expressions, &pflags);

    // Clean up bracket-wrapped expressions
    exec_bracket_processing(&pflags);

    // Last calcuration after cleaning up of brackets
    cout << calcurate(pflags.expressions.begin(), pflags.expressions.end()) << endl;
    */

    return 0;
}


