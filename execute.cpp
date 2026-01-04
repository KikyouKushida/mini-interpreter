#include "execute.h"

void execute(const Stmt& stmt, std::vector<std::map<std::string, int>>& envStack) {
  if (auto p = dynamic_cast<const AssignStmt*>(&stmt)) {
    envStack.back()[p->name] = eval(*(p->expr), envStack);
  } else if (auto p = dynamic_cast<const PrintStmt*>(&stmt)) {
    std::cout << eval(*(p->expr), envStack) << "\n";
  } else if (auto p = dynamic_cast<const BlockStmt*>(&stmt)) {
    envStack.push_back({});
    for (auto& stmt : p->statements) {
      execute(*stmt, envStack);
    }
    envStack.pop_back();
  } else {
    throw std::runtime_error("Unknown statement type");
  }
}

void executeProgram(const Program& program, std::vector<std::map<std::string, int>>& envStack) {
  for (const auto& stmt : program) {
    execute(*stmt, envStack);
  }
  return ;
}