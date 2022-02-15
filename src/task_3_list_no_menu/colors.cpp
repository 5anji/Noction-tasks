#include "colors.h"

std::string Black(std::string str) { return "\033[30m" + str + "\033[0m"; }

std::string Red(std::string str) { return "\033[31m" + str + "\033[0m"; }

std::string Green(std::string str) { return "\033[32m" + str + "\033[0m"; }

std::string Orange(std::string str) { return "\033[33m" + str + "\033[0m"; }

std::string Blue(std::string str) { return "\033[34m" + str + "\033[0m"; }

std::string Purple(std::string str) { return "\033[35m" + str + "\033[0m"; }

std::string Cyan(std::string str) { return "\033[36m" + str + "\033[0m"; }

std::string Gray(std::string str) { return "\033[37m" + str + "\033[0m"; }

std::string Bold(std::string str) { return "\033[1m" + str + "\033[0m"; }

std::string Underline(std::string str) { return "\033[4m" + str + "\033[0m"; }