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
    cout << endl;
}

int main(int argc, char *argv[]) 
{
    string exp;
    list<string> exp_array;
    string::size_type current, prev,
        pos_plus, pos_minus, pos_multi, pos_div;
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
        if (pos_plus == string::npos &&
            pos_minus == string::npos &&
            pos_multi == string::npos &&
            pos_div == string::npos) {
            noexp = true;
        }

        // number
        prev = current;
        current = min(pos_plus, min(pos_minus,
                  min(pos_multi, pos_div)));
        exp_array.push_back(exp.substr(prev, current - prev));

        // expression
        if (noexp) break;
        exp_array.push_back(exp.substr(current, 1));
        current++;
    }

    int right, left, let, exptype;
    string buf;
    list<string>::iterator it;

    put_list_in_string(exp_array);

    // process all multipulication and division at first
    // and after all of them are processed, it starts processing
    // the rest expressions such as addition and subtraction
    bool _exists_mul_and_div, _exists_pls_and_mns;
    bool _go_through = false;
    while (1) {
        _exists_mul_and_div = false;
        _exists_pls_and_mns = false;

        it = exp_array.begin();
        while (it != exp_array.end()) {
            exptype = 0;
            if (*it == "*") {
                exptype = MUL;
                _exists_mul_and_div = true;
            } else if (*it == "/") {
                exptype = DIV;
                _exists_mul_and_div = true;
            }
            if (!_exists_mul_and_div && _go_through) {
                if (*it == "+") {
                    exptype = PLS;
                    _exists_pls_and_mns = true;
                } else if (*it == "-") {
                    exptype = MNS;
                    _exists_pls_and_mns = true;
                }
            }
            if (exptype != 0) {
                it = exp_array.erase(it);
                buf = *it;
                right = _stoi(buf);
                it = exp_array.erase(it);
                it--;
                buf = *it;
                left = _stoi(buf);
                if (right == -1 || left == -1) {
                    cout << "Error: unusual expression" << endl;
                    return 0;
                }
                if (exptype == MUL) {
                    /* multipulication */
                    let = right * left;
                } else if (exptype == DIV) { 
                    /* division */
                    let = left / right;
                } else if (exptype == PLS) {
                    /* addition */
                    let = left + right;
                } else if (exptype == MNS) {
                    /* subtraction */
                    let = left - right;
                } else {
                    // error
                    cout << "Error exp(1)" << endl;
                    return 0;
                }
                exp_array.insert(it, _itos(let));
                it = exp_array.erase(it);
                
                cout << "= ";
                put_list_in_string(exp_array);
            }
            it++;
        }

        // processing for subtraction and addition is not going
        // to be triggerd off before going-through expression
        // processing has not completed once.
        _go_through = true;

        if (!_exists_mul_and_div && !_exists_pls_and_mns) {
            break;
        }
    }

    return 0;
}


