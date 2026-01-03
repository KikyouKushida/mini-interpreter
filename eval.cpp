#include "eval.h"

int eval(const Expr& e, std::map<std::string, int>& env) {
  if (auto p = dynamic_cast<const IntExpr*>(&e)) {
    return p->value;
  } else if (auto p = dynamic_cast<const VarExpr*>(&e)) {
    auto it = env.find(p->name);
    if (it == env.end()) {
      throw std::runtime_error("Undefined variable: " + p->name);
    } else {
      return it->second;
    }
  } else if (auto p = dynamic_cast<const BinaryExpr*>(&e)) {
    int leval = eval(*(p->left), env), reval = eval(*(p->right), env);
    if (p->op == TokenType::PLUS) {
      return leval + reval;
    } else if (p->op == TokenType::MINUS) {
      return leval - reval;
    } else if (p->op == TokenType::MUL) {
      return leval * reval;
    } else if (p->op == TokenType::DIV) {
      if (reval == 0) {
        throw std::runtime_error("Division by zero");
      }
      return leval / reval;
    } else {
      throw std::runtime_error("Unknown operator type");
    }
  } else {
    throw std::runtime_error("Unknown expression type");
  }
}