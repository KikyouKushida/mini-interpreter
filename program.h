#pragma once
#include <vector>
#include <memory>
#include "stmt.h"

using Program = std::vector<std::unique_ptr<Stmt>>;