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
    int bracket_value, result;
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

    cout << stringify_list(pflags.expressions) << endl;

    int ret; // DEBUG
    ret = process_brackets(&pflags);

    /*
    // process all multipulication and division at first
    // and after all of them are processed, it starts processing
    // the rest expressions such as addition and subtraction
    pflags.go_through = false;
    in_bracket = false;

    while (1) {
        pflags.exists_mul_and_div = false;
        pflags.exists_pls_and_mns = false;

        pflags.it = pflags.expressions.begin();
        while (pflags.it != pflags.expressions.end()) {
            bracket_value = 0;

            // Process all brackets at first
            exp_begin = pflags.expressions.begin();
            exp_end = pflags.expressions.end();
            if (find(exp_begin, exp_end, "(") != exp_end ||
                find(exp_begin, exp_end, ")") != exp_end) {
                if (*pflags.it == "(") {
                    if (in_bracket) {
                        cout << "Error: bracket duplication" << endl;
                        return 0;
                    }
                    in_bracket = true;
                    pflags.it--; bracket_start = pflags.it; pflags.it++;
                    pflags.it++; bracket_pass_st = pflags.it; pflags.it--;
                } else if (*pflags.it == ")") {
                    if (!in_bracket) {
                        cout << "Error: invalid bracket" << endl;
                        return 0;
                    }
                    in_bracket = false;
                    pflags.it++; pflags.it++; bracket_end = pflags.it; pflags.it--;
                    bracket_pass_ed = pflags.it; pflags.it++;
                    bracket_value = calcurate(bracket_pass_st, bracket_pass_ed);
                    pflags.expressions.erase(bracket_start, bracket_end);
                    pflags.expressions.insert(pflags.it, _itos(bracket_value));
                }
                pflags.it++;
                continue;
            }

            result = sub_calcurate(&pflags);

            if (result == 1) {
                cout << "= " << stringify_list(pflags.expressions) << endl;
            } else if (result < 0) {
                cout << "Error(" << result << ")" << endl;
            }

            pflags.it++;
        }

        if (pflags.go_through &&
            !pflags.exists_mul_and_div &&
            !pflags.exists_pls_and_mns) {
            break;
        }

        // processing for subtraction and addition is not going
        // to be triggerd off before going-through expression
        // processing has not completed once.
        pflags.go_through = true;
    }
    */

    return 0;
}


