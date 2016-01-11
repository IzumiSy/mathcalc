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

struct PROGRESSION_FLAGS {
    list<string> expressions;
    list<string>::iterator it;
    bool exists_mul_and_div;
    bool exists_pls_and_mns;
    bool go_through;
};

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
            } else {
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

int main(int argc, char *argv[])
{
    string exp;
    list<string> exp_array;
    string::size_type current, prev,
        pos_plus, pos_minus, pos_multi, pos_div,
        pos_bracket_begin, pos_bracket_end;
    bool noexp;

    if (argc == 1) {
        cout << "usage: mathcalc [expression]" << endl;
        return 0;
    }
    exp = argv[1];

    current = 0;
    noexp = false;
    while (1) {
        pos_plus = exp.find("+", current);
        pos_minus = exp.find("-", current);
        pos_multi = exp.find("*", current);
        pos_div = exp.find("/", current);
        pos_bracket_begin = exp.find("(", current);
        pos_bracket_end = exp.find(")", current);
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
        exp_array.push_back(exp.substr(prev, current - prev));

        // expression
        if (noexp) break;
        exp_array.push_back(exp.substr(current, 1));
        current++;
    }

    int right, left, let, exptype;
    struct EXP_DIVIDER_RESULT edr;
    list<string>::iterator it;
    list<string>::iterator _is_exists_brackets;
    list<string>::iterator bracket_start, bracket_end;
    list<string>::iterator bracket_pass_st, bracket_pass_ed;

    put_list_in_string(exp_array);
    cout << endl;

    // process all multipulication and division at first
    // and after all of them are processed, it starts processing
    // the rest expressions such as addition and subtraction
    bool _exists_mul_and_div;
    bool _exists_pls_and_mns;
    bool _go_through = false;
    bool in_bracket = false;
    int bracket_value;

    while (1) {
        _exists_mul_and_div = false;
        _exists_pls_and_mns = false;

        it = exp_array.begin();
        while (it != exp_array.end()) {
            bracket_value = 0;

            // Process all brackets at first
            if (find(exp_array.begin(), exp_array.end(), "(") != exp_array.end() ||
                find(exp_array.begin(), exp_array.end(), ")") != exp_array.end()) {
                if (*it == "(") {
                    if (in_bracket) {
                        cout << "Error: bracket duplication" << endl;
                        return 0;
                    }
                    in_bracket = true;
                    it--; bracket_start = it; it++;
                    it++; bracket_pass_st = it; it--;
                } else if (*it == ")") {
                    if (!in_bracket) {
                        cout << "Error: invalid bracket" << endl;
                        return 0;
                    }
                    in_bracket = false;
                    it++; it++; bracket_end = it; it--;
                    bracket_pass_ed = it; it++;
                    bracket_value = calcurate(bracket_pass_st, bracket_pass_ed);
                    exp_array.erase(bracket_start, bracket_end);
                    exp_array.insert(it, _itos(bracket_value));
                }
                it++;
                continue;
            }

            exptype = expression_processor(
                *it, &_exists_mul_and_div,
                &_exists_pls_and_mns, _go_through
            );

            if (exptype != NO_EXP) {
                exp_divider(&exp_array, &it, &edr);
                right = edr.right_value;
                left = edr.left_value;
                if (right == -1 || left == -1) {
                    cout << "Error: unusual expression" << endl;
                    return 0;
                }

                let = exec_calcurate(exptype, edr);
                if (let == (int)NULL) {
                    cout << "Error exp(1)" << endl;
                    return 0;
                }

                exp_array.insert(it, _itos(let));
                it = exp_array.erase(it);

                cout << "= ";
                put_list_in_string(exp_array);
                cout << endl;
            }

            it++;
        }

        if (_go_through && !_exists_mul_and_div && !_exists_pls_and_mns) {
            break;
        }

        // processing for subtraction and addition is not going
        // to be triggerd off before going-through expression
        // processing has not completed once.
        _go_through = true;
    }

    return 0;
}


