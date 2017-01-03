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

#include "calculator.cpp"

int main(int argc, char *argv[])
{
    struct PROGRESSION_FLAGS pflags;
    string expressions;

    if (argc == 1) {
        cout << "usage: mathcalc [expression]" << endl;
        return 0;
    }

    // Build expression array from string given from command-line
    expressions = argv[1];
    build_expressions(expressions, &pflags);

    // Clean up bracket-wrapped expressions
    exec_bracket_processing(&pflags);

    // Last calcuration after cleaning up of brackets
    cout << calcurate(pflags.expressions.begin(), pflags.expressions.end()) << endl;

    return 0;
}


