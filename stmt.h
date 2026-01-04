#pragma once

#include <memory>
#include <string>
#include "token.h"
#include "ast.h"

struct Stmt {
  virtual ~Stmt() = default;
};

struct AssignStmt : Stmt {
  std::string name;
  std::unique_ptr<Expr> expr;
  AssignStmt(std::string name_, std::unique_ptr<Expr> expr_) {
    name = name_;
    expr = std::move(expr_);
  }
};

struct PrintStmt : Stmt {
  std::unique_ptr<Expr> expr;
  PrintStmt(std::unique_ptr<Expr> expr_) {
    expr = std::move(expr_);
  }
};

struct BlockStmt : Stmt {
  std::vector<std::unique_ptr<Stmt>> statements;
  BlockStmt(std::vector<std::unique_ptr<Stmt>> statements_) {
    for (auto& stmt: statements_) {
      statements.push_back(std::move(stmt));
    }
  }
};