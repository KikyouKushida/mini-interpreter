#include "token.h"
#include <string>
#include <vector>
#include <cctype>     // isspace, isdigit, isalpha
#include <stdexcept>  // std::runtime_error

bool isEmpty(char c);
bool isIdentStart(char c);
bool isIdentChar(char c);
std::vector<Token> tokenize(const std::string& input);