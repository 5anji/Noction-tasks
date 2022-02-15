#include <algorithm>
#include <csignal>
#include <iostream>
#include <map>

enum class str {
    option_1,
    option_2,
    option_3,
    option_4,
    option_5,
    option_6,
    option_7,
    option_8,
    option_9,
    option_10,
    // option_,
    // option_,
    option_d,
    option_c,
    option_q,
};

void signalHandler(int n);
void display_menu(std::string* a);
void init_map();

extern std::map<std::string, str> str_val;