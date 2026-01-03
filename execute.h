#pragma once

#include <memory>
#include <string>
#include <vector>
#include "token.h"
#include "ast.h"
#include "stmt.h"
#include "eval.h"
#include <stdexcept>
#include <map>
#include <iostream>

void execute(const Stmt& stmt, std::map<std::string, int>& env);
