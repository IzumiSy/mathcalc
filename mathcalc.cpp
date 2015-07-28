#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <list>
using namespace std;

#define DIV 1
#define MUL 2
#define PLS 3
#define MNS 4

string itos(int n) 
{
    stringstream s;
    s << n;
    return s.str();
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
    // string exp(argv[1]);
    string exp("4/2+122+412+5*7-2*5");
    list<string> exp_array;
    string::size_type current, prev,
        pos_plus, pos_minus, pos_multi, pos_div;
    bool noexp;

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
    noexp = true;
    it = exp_array.begin();
    while (it != exp_array.end()) {
        exptype = 0;
        if (*it == "*") {
            exptype = MUL;
        } else if (*it == "/") {
            exptype = DIV;
        } else if (*it == "+") {
            exptype = PLS;
        } else if (*it == "-") {
            exptype = MNS;
        }
        if (exptype != 0) {
            it = exp_array.erase(it);
            buf = *it;
            right = atoi(buf.c_str());
            it = exp_array.erase(it);
            it--;
            buf = *it;
            left = atoi(buf.c_str());
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
            exp_array.insert(it, itos(let));
            it = exp_array.erase(it);
        }
        it++;
        if (exptype != 0) {
            cout << "= ";
            put_list_in_string(exp_array);
        }
    }

    return 0;
}


