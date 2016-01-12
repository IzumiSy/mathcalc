#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <list>
#include <locale>
using namespace std;

#define DIV 1
#define MUL 2
#define PLS 3
#define MNS 4

#define NO_EXP 0

string _itos(int n)
{
    stringstream s;
    s << n;
    return s.str();
}

int _stoi(string s) {
    if (s.empty()) {
        return -1;
    }
    return atoi(s.c_str());
}

void put_list_in_string(list<string> n)
{
    list<string>::iterator begin = n.begin();
    list<string>::iterator end = n.end();
    for (;begin != end;begin++) {
        cout << *begin << " ";
    }
}

// Process expressions
int expression_processor(
    string it,
    bool *exists_mul_and_div,
    bool *exists_pls_and_mns,
    bool go_through )
{
    int exptype = NO_EXP;

    if (it == "*") {
        exptype = MUL;
        *exists_mul_and_div = true;
    } else if (it == "/") {
        exptype = DIV;
        *exists_mul_and_div = true;
    }
    if (!*exists_mul_and_div && go_through) {
        if (it == "+") {
            exptype = PLS;
            *exists_pls_and_mns = true;
        } else if (it == "-") {
            exptype = MNS;
            *exists_pls_and_mns = true;
        }
    }

    return exptype;
}

struct EXP_DIVIDER_RESULT {
    int left_value;
    int right_value;
};

void exp_divider(
    list<string> *exp_array,
    list<string>::iterator *it,
    struct EXP_DIVIDER_RESULT *exp_result )
{
    string buf;

    *it = exp_array->erase(*it);
    buf = *(*it);
    exp_result->right_value = _stoi(buf);

    *it = exp_array->erase(*it);
    *(*it)--;
    buf = *(*it);
    exp_result->left_value = _stoi(buf);
}

int exec_calcurate(int exptype, struct EXP_DIVIDER_RESULT divider_result)
{
    int let = 0;
    int right = divider_result.right_value;
    int left = divider_result.left_value;

    switch (exptype) {
        case MUL: let = right * left; break;
        case DIV: let = left / right; break;
        case PLS: let = left + right; break;
        case MNS: let = left - right; break;
        default:  let = (int)NULL;    break;
    }

    return let;
}

struct PROGRESSION_FLAGS {
    list<string> expressions;
    list<string>::iterator it;
    bool exists_mul_and_div;
    bool exists_pls_and_mns;
    bool go_through;
};

int sub_calcurate(struct PROGRESSION_FLAGS *pflags)
{
    struct EXP_DIVIDER_RESULT edr;
    int right, left, let;
    int exptype;

    exptype = expression_processor(
        *pflags->it, &pflags->exists_mul_and_div,
        &pflags->exists_pls_and_mns, pflags->go_through
    );

    if (exptype != NO_EXP) {
        exp_divider(&pflags->expressions, &pflags->it, &edr);
        right = edr.right_value;
        left = edr.left_value;

        if (right == -1 || left == -1) {
            return -1;
        }

        let = exec_calcurate(exptype, edr);

        if (let == (int)NULL) {
            return -2;
        }

        pflags->expressions.insert(pflags->it, _itos(let));
        pflags->it = pflags->expressions.erase(pflags->it);

        return 1;
    }

    return 0;
}

int calcurate(list<string>::iterator begin, list<string>::iterator end)
{
    struct PROGRESSION_FLAGS pflags;
    list<string>::iterator exp_begin, exp_end;
    int result;

    exp_begin = begin;
    end--;
    if (*end != ")") {
        end++;
    }
    exp_end = end;

    pflags.it = exp_begin;
    for (;pflags.it != exp_end;pflags.it++)  {
        pflags.expressions.push_back(*pflags.it);
    }

    pflags.go_through = false;

    cout << "( ";
    put_list_in_string(pflags.expressions);
    cout << ")" << endl;

    while (1) {
        pflags.exists_mul_and_div = false;
        pflags.exists_pls_and_mns = false;

        pflags.it = pflags.expressions.begin();
        while (pflags.it != pflags.expressions.end()) {
            result = sub_calcurate(&pflags);

            if (result == 1) {
                cout << "= ( ";
                put_list_in_string(pflags.expressions);
                cout << ")" << endl;
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

    return _stoi(*pflags.expressions.begin());
}

void build_expressions(string expressions, struct PROGRESSION_FLAGS *pflags)
{
    string::size_type current, prev, pos_plus, pos_minus, pos_multi, pos_div;
    string::size_type pos_bracket_begin, pos_bracket_end;
    bool noexp;

    current = 0;
    noexp = false;

    while (1) {
        pos_plus = expressions.find("+", current);
        pos_minus = expressions.find("-", current);
        pos_multi = expressions.find("*", current);
        pos_div = expressions.find("/", current);
        pos_bracket_begin = expressions.find("(", current);
        pos_bracket_end = expressions.find(")", current);
        if (pos_plus == string::npos &&
            pos_minus == string::npos &&
            pos_multi == string::npos &&
            pos_div == string::npos &&
            pos_bracket_begin == string::npos &&
            pos_bracket_end == string::npos) {
            noexp = true;
        }

        // number
        prev = current;
        current = min(pos_plus, min(pos_minus, min(pos_multi,
                  min(pos_div, min(pos_bracket_begin, pos_bracket_end)))));
        pflags->expressions.push_back(expressions.substr(prev, current - prev));

        // expression
        if (noexp) break;
        pflags->expressions.push_back(expressions.substr(current, 1));
        current++;
    }

    return;
}

int main(int argc, char *argv[])
{
    struct PROGRESSION_FLAGS pflags;
    string expressions;

    if (argc == 1) {
        cout << "usage: mathcalc [expression]" << endl;
        return 0;
    }

    expressions = argv[1];
    build_expressions(expressions, &pflags);

    list<string>::iterator _is_exists_brackets;
    list<string>::iterator bracket_start, bracket_end;
    list<string>::iterator bracket_pass_st, bracket_pass_ed;
    list<string>::iterator exp_begin, exp_end;

    put_list_in_string(pflags.expressions);
    cout << endl;

    // process all multipulication and division at first
    // and after all of them are processed, it starts processing
    // the rest expressions such as addition and subtraction
    pflags.go_through = false;

    bool in_bracket = false;
    int bracket_value, result;

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
                cout << "= ";
                put_list_in_string(pflags.expressions);
                cout << endl;
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

    return 0;
}


