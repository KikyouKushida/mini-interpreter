

#include <memory>
#include <string>
#include <vector>
#include "token.h"
#include "ast.h"
#include "parser.h"
#include <stdexcept>

std::unique_ptr<Expr> parseExpression(TokenStream& ts) {
  std::unique_ptr<Expr> left = parseTerm(ts);
  while (ts.peek().type == TokenType::PLUS || ts.peek().type == TokenType::MINUS) {
    TokenType op = ts.consume().type;
    std::unique_ptr<Expr> right = parseTerm(ts);
    left = std::make_unique<BinaryExpr>(op, std::move(left), std::move(right));
  }
  return left;
}

std::unique_ptr<Expr> parseTerm(TokenStream& ts) {
  std::unique_ptr<Expr> left = parseFactor(ts);
  while (ts.peek().type == TokenType::MUL || ts.peek().type == TokenType::DIV) {
    TokenType op = ts.consume().type;
    std::unique_ptr<Expr> right = parseFactor(ts);
    left = std::make_unique<BinaryExpr>(op, std::move(left), std::move(right));
  }
  return left;
}

std::unique_ptr<Expr> parseFactor(TokenStream& ts) {
  if (ts.peek().type == TokenType::INT) {
    const Token& t = ts.consume();
    return std::make_unique<IntExpr>(t.value);
  } else if (ts.peek().type == TokenType::IDENT) {
    const Token& t = ts.consume();
    return std::make_unique<VarExpr>(t.lexeme);
  } else if (ts.peek().type == TokenType::LPAREN) {
    ts.consume();
    auto inside = parseExpression(ts);
    ts.expect(TokenType::RPAREN);
    return inside;
  } else {
    throw std::runtime_error(
      "Unexpected token " + tokenTypeName(ts.peek().type) +
      " ('" + ts.peek().lexeme + "') at position " +
      std::to_string(ts.peek().position)
    );
  }
}

std::unique_ptr<Expr> parseAllExpression(TokenStream& ts) {
  auto expr = parseExpression(ts);
  ts.expect(TokenType::END);
  return expr;
}