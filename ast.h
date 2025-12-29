#pragma once

#include <memory>
#include <string>
#include "token.h"

struct Expr {
  virtual ~Expr() = default;
};

struct IntExpr : Expr {
  int value;
  IntExpr(int value_) {
    value = value_;
  }
};

struct VarExpr : Expr {
  std::string name;
  VarExpr(std::string name_) {
    name = name_;
  }
};

struct BinaryExpr : Expr {
  TokenType op;
  std::unique_ptr<Expr> left, right;
  BinaryExpr(TokenType op_, std::unique_ptr<Expr> left_, std::unique_ptr<Expr> right_) {
    op = op_;
    left = std::move(left_);
    right = std::move(right_);
  }
};