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

int main(int argc, char *argv[])
{
    struct PROGRESSION_FLAGS pflags;
    bool exit_bracket_processing = false;
    string expressions;
    list<string>::iterator _is_exists_brackets;
    list<string>::iterator bracket_start, bracket_end;
    list<string>::iterator bracket_pass_st, bracket_pass_ed;
    list<string>::iterator exp_begin, exp_end;

    if (argc == 1) {
        cout << "usage: mathcalc [expression]" << endl;
        return 0;
    }

    expressions = argv[1];
    build_expressions(expressions, &pflags);

    cout << "> " << stringify_list(pflags.expressions) << endl;

    // Clean up bracket-wrapped expressions
    while (1) {
        cout << "------" << endl;
        switch (process_brackets(&pflags)) {
            case NO_MORE_BRACKETS:
                exit_bracket_processing = true;
                break;
            case BRACKET_MISMATCH:
                cout << "Bracket mis-match" << endl;
                return 0;
            default:
                break;
        }
        if (exit_bracket_processing) {
            break;
        }
    }

    // Last calcuration after cleaning up of brackets
    cout << calcurate(pflags.expressions.begin(), pflags.expressions.end()) << endl;

    return 0;
}


