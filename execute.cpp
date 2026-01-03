#include "execute.h"

void execute(const Stmt& stmt, std::map<std::string, int>& env) {
  if (auto p = dynamic_cast<const AssignStmt*>(&stmt)) {
    env[p->name] = eval(*(p->expr), env);
  } else if (auto p = dynamic_cast<const PrintStmt*>(&stmt)) {
    std::cout << eval(*(p->expr), env) << "\n";
  } else {
    throw std::runtime_error("Unknown statement type");
  }
}