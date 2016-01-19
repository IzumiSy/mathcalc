#ifndef UTILS_H
#define UTILS_H

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

string stringify_list(list<string> n)
{
    string buf;
    list<string>::iterator begin = n.begin();
    list<string>::iterator end = n.end();

    for (;begin != end;begin++) {
        buf += *begin;
    }

    return buf;
}

#endif
