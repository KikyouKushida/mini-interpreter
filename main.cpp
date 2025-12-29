#include <string>
#include <iostream>
#include <vector>
#include <cctype>     // isspace, isdigit, isalpha
#include <stdexcept>  // std::runtime_error
#include "token.h"
#include "tokenizer.h"
#include "ast.h"
#include "parser.h"

void testTokenizer(std::string input) {
  std::vector<Token> tokens1 = tokenize(input);
  for (auto v: tokens1) {
    std::cout << v.toString() << " ";
  }
  std::cout << "\n";
  return ;
}

std::string toString(const Expr& e) {
  if (auto p = dynamic_cast<const IntExpr*>(&e)) {
    return std::to_string(p->value);
  } else if (auto p = dynamic_cast<const VarExpr*>(&e)) {
    return p->name;
  } else if (auto p = dynamic_cast<const BinaryExpr*>(&e)) {
    std::string op;
    switch (p->op) {
      case TokenType::PLUS: op = "+"; break;
      case TokenType::MINUS: op = "-"; break;
      case TokenType::MUL: op = "*"; break;
      case TokenType::DIV: op = "/"; break;
      // case TokenType::ASSIGN: op = "="; break;
      default: op = "?"; break;
    }
    return "(" + op + " " + toString(*p->left) + " " + toString(*p->right) + ")";
  }
  return "<unknown expr>";
}

void testAst() {
  std::unique_ptr<Expr> a = std::make_unique<IntExpr>(1);
  std::unique_ptr<Expr> b = std::make_unique<IntExpr>(2);
  std::unique_ptr<Expr> c = std::make_unique<IntExpr>(3);
  std::unique_ptr<Expr> d = std::make_unique<BinaryExpr>(TokenType::MUL, std::move(b), std::move(c));
  std::unique_ptr<Expr> e = std::make_unique<BinaryExpr>(TokenType::PLUS, std::move(a), std::move(d));
  std::cout << toString(*e) << "\n";
  return ;
}

void testParser1() {
  std::vector<Token> tokens = tokenize("1 + 2 * (3 + 4)");
  TokenStream tokenStream(tokens);
  std::cout << toString(*parseAllExpression(tokenStream)) << "\n";
  return ;
}

void testParser2() {
  std::vector<Token> tokens = tokenize("10 - 3 - 2");
  TokenStream tokenStream(tokens);
  std::cout << toString(*parseAllExpression(tokenStream)) << "\n";
  return ;
}

void testParser3() {
  std::vector<Token> tokens = tokenize("(1 + 2) * 3");
  TokenStream tokenStream(tokens);
  std::cout << toString(*parseAllExpression(tokenStream)) << "\n";
  return ;
}
 
int main() {
  // testTokenizer("a = 3");
  // testTokenizer("b = a * 2 + 1");
  // testAst();
  testParser1();
  testParser2();
  testParser3();
  return 0;
}