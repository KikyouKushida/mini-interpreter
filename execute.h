#pragma once

#include <memory>
#include <string>
#include <vector>
#include "token.h"
#include "ast.h"
#include "stmt.h"
#include "eval.h"
#include "program.h"
#include <stdexcept>
#include <map>
#include <iostream>

void execute(const Stmt& stmt, std::vector<std::map<std::string, int>>& envStack);

void executeProgram(const Program&, std::vector<std::map<std::string, int>>& envStack);