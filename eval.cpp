#include "eval.h"

int eval(const Expr& e, std::vector<std::map<std::string, int>>& envStack) {
  if (auto p = dynamic_cast<const IntExpr*>(&e)) {
    return p->value;
  } else if (auto p = dynamic_cast<const VarExpr*>(&e)) {
    for (auto it = envStack.rbegin(); it != envStack.rend(); ++it) {
      auto found = it->find(p->name);
      if (found != it->end()) {
        return found->second;
      } 
    }
    throw std::runtime_error("Undefined variable: " + p->name);
  } else if (auto p = dynamic_cast<const BinaryExpr*>(&e)) {
    int leval = eval(*(p->left), envStack), reval = eval(*(p->right), envStack);
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
    } else if (p->op == TokenType::GREATER) {
      return leval > reval ? 1 : 0;
    } else if (p->op == TokenType::LESS) {
      return leval < reval ? 1 : 0;
    } else if (p->op == TokenType::EQUAL) {
      return leval == reval ? 1 : 0;
    } else if (p->op == TokenType::NOTEQUAL) {
      return leval != reval ? 1 : 0;
    } else {
      throw std::runtime_error("Unknown operator type");
    }
  } else {
    throw std::runtime_error("Unknown expression type");
  }
}