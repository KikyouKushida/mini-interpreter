#pragma once
#include <string>
#include <vector>
#include <cctype>     // isspace, isdigit, isalpha
#include <stdexcept>  // std::runtime_error
#include <map>
#include "ast.h"

int eval(const Expr& e, std::map<std::string, int>& env);