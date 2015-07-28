#include <iostream>
#include <algorithm>
#include <string>
#include <list>
using namespace std;

int main(int argc, char *argv[]) {
    // string exp(argv[1]);
    string exp("122+412-2*5");
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

    // puts all contents
    cout << "Parsed: ";
    list<string>::iterator begin = exp_array.begin(),
                           end = exp_array.end();
    for (;begin != end;begin++) { cout << *begin << " "; }
    cout << endl;

    return 0;
}


