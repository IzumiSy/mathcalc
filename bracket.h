#ifndef BRACKET_H
#define BRACKET_H

#include "types.h"
#include "calcurate.h"

#define BEGIN_BRACKET 1
#define END_BRACKET   2

int bracket_count(list<string> expressions, int type)
{
    list<string>::iterator it = expressions.begin();
    int result = 0;

    while (it != expressions.end()) {
        switch (type) {
            case BEGIN_BRACKET:
                if (*it == "(") {
                    result++;
                }
                break;
            case END_BRACKET:
                if (*it == ")") {
                    result++;
                }
                break;
            default:
                ;
        }
        it++;
    }

    return result;
}

int process_brackets(struct PROGRESSION_FLAGS *pflags)
{
    list<string> partial_expressions;
    list<string>::iterator it, pair_match_seek_it;
    list<string>::iterator last_begin_bracket_it,
                           pair_end_bracket_it;
    list<string>::iterator statement_begin,
                           statement_end;
    list<string>::iterator insert_position;
    bool begin_bracket_found,
         end_bracket_found;
    int begin_bracket_counter = 0,
        end_bracket_counter = 0;
    int bracket_value = 0;

    begin_bracket_counter = bracket_count(pflags->expressions, BEGIN_BRACKET);
    end_bracket_counter = bracket_count(pflags->expressions, END_BRACKET);
    if (begin_bracket_counter != end_bracket_counter) {
        return -1;
    }

    it = pflags->expressions.begin();
    while (it != pflags->expressions.end()) {
        begin_bracket_found = false;
        end_bracket_found = false;

        if (*it == "(") {
            begin_bracket_found = true;
            last_begin_bracket_it = it;

            pair_match_seek_it = it;
            while (pair_match_seek_it != pflags->expressions.end()) {
                pair_match_seek_it++;
                if (*pair_match_seek_it == "(") {
                    break;
                }
                if (*pair_match_seek_it == ")") {
                    end_bracket_found = true;
                    pair_match_seek_it++; pair_end_bracket_it = pair_match_seek_it;
                    break;
                }
            }
        }
        if (begin_bracket_found && end_bracket_found) {
            break;
        }

        it++;
    }

    statement_begin = last_begin_bracket_it;
    statement_begin++;
    statement_end = pair_end_bracket_it;
    statement_end--;
    bracket_value = calcurate(statement_begin, statement_end);
    cout << bracket_value << endl;

    insert_position = last_begin_bracket_it;
    insert_position--;
    pflags->expressions.erase(last_begin_bracket_it, pair_end_bracket_it);
    pflags->expressions.insert(insert_position, _itos(bracket_value));
    cout << stringify_list(pflags->expressions) << endl;

    return 0;
}

#endif
