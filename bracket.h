#ifndef BRACKET_H
#define BRACKET_H

#include "types.h"

#define BRACKET_PAIR_FOUND 1

int match_bracket_pair(list<string> expressions, int bracket_pair_counter)
{
    list<string>::iterator back_it;
    int bracket_count = 0;

    back_it = expressions.end();
    while (back_it != expressions.begin()) {
        if (*back_it == ")") {
            bracket_count++;
            if (bracket_count == bracket_pair_counter) {
                return BRACKET_PAIR_FOUND;
            }
        }
        back_it--;
    }

    return 0;
}

int process_brackets(struct PROGRESSION_FLAGS *pflags)
{
    list<string>::iterator begin_it, back_it;
    int bracket_count = 0, result;
    int pair_match_count = 0;

    begin_it = pflags->expressions.begin();
    while (begin_it != pflags->expressions.end()) {
        if (*begin_it == "(") {
            bracket_count++;
            result = match_bracket_pair(pflags->expressions, bracket_count);
            if (result == BRACKET_PAIR_FOUND) {
                pair_match_count++;
            }
        }
        begin_it++;
    }

    return (bracket_count == pair_match_count);
}

#endif
